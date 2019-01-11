#ifndef E2F55C614_A134_1398_8EBE_CF5FF36172CD
#define E2F55C614_A134_1398_8EBE_CF5FF36172CD

#include <memory>
#include <typeinfo>
#include <type_traits>
#include <any>

#include "cub/dci/role.h"

namespace cub {

struct BadAnyCast : std::bad_cast {
  const char* what() const noexcept override;
};

struct Any {
  Any() noexcept = default;

  Any(Any&&) noexcept = default;
  Any& operator=(Any&&) noexcept = default;

  Any(const Any&);
  Any& operator=(const Any&);

  template<
    typename Ref, typename T = std::decay_t<Ref>,
    typename = std::enable_if_t<!std::is_same<Any, T>()>
  >
  Any(Ref&& ref);

  template<
    typename Ref, typename T = std::decay_t<Ref>,
    typename = std::enable_if_t<!std::is_same<Any, T>()>
  >
  Any& operator=(Ref&& ref);

  void clear() noexcept;
  bool empty() const noexcept;
  void swap(Any& rhs) noexcept;

  template<typename T>
  T* cast() noexcept;

  template<typename T>
  const T* cast() const noexcept;

private:
  DEFINE_ROLE(Base) {
    ABSTRACT(Base* clone() const);
    ABSTRACT(const std::type_info& type() const noexcept);

    static Base* make(const Any&);
  };

  template<typename T>
  struct Impl;

  std::unique_ptr<Base> ptr;
};

template<typename T>
struct Any::Impl : Base {
  Impl(T t) : t(std::move(t)) {
  }

  T* get() {
    return &t; 
  }

  const T* get() const { 
    return &t; 
  }

private:
  OVERRIDE(Base* clone() const) {
    return new Impl(t);
  }

  OVERRIDE(const std::type_info& type() const noexcept) {
    return typeid(t);
  }

private:
  T t;
};

template<
  typename Ref, typename T = std::decay_t<Ref>,
  typename = std::enable_if_t<!std::is_same<Any, T>()>
>
inline Any::Any(Ref&& ref) : ptr(new Impl<T>(std::forward<Ref>(ref)))
{}

template<
  typename Ref, typename T = std::decay_t<Ref>,
  typename = std::enable_if_t<!std::is_same<Any, T>()>
>
inline Any& Any::operator=(Ref&& ref) {
  Any(std::forward<Ref>(ref)).swap(*this);
  return *this;
}

template <typename T>
inline T* Any::cast() noexcept {
  if (ptr) if (auto q = dynamic_cast<Any::Impl<T>*>(ptr.get()))
    return q->get();
  return nullptr;
}

template <typename T>
inline const T* Any::cast() const noexcept {
  return const_cast<Any*>(this)->cast<T>();
}

} // namespace cub

#endif
