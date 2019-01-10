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

class Any;

// template<typename T>
// T* any_cast(Any*) noexcept;

// template<typename T>
// const T* any_cast(const Any*) noexcept;

class Any {
  template<typename T>
  friend T* any_cast(Any*) noexcept;

  template<typename T>
  friend const T* any_cast(const Any*) noexcept;

  DEFINE_ROLE(Base) {
    ABSTRACT(Base* clone() const);
    ABSTRACT(const std::type_info& type() const noexcept);
  };

  static Base* clone(const Any&);

  template<typename T>
  struct Impl : Any::Base {
    Impl(T t) : t(std::move(t)) {
    }

    T& get() {
      return t; 
    }

    const T& get() const { 
      return t; 
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

  std::unique_ptr<Base> ptr;

public:
  Any() noexcept = default;

  Any(Any&&) noexcept = default;
  Any& operator=(Any&&) noexcept = default;

  Any(const Any&);
  Any& operator=(const Any&);

  template<typename Ref, typename T = std::decay_t<Ref>,
     typename = std::enable_if_t<
       std::is_copy_constructible<T>() &&
       !std::is_same<Any, T>()
     >
  >
  Any(Ref&& ref) : ptr(new Impl<T>(std::forward<Ref>(ref)))
  {}

  template<typename Ref, typename T = std::decay_t<Ref>,
     typename = std::enable_if_t<
       std::is_copy_constructible<T>() &&
       !std::is_same<Any, T>()
     >
  >
  Any& operator=(Ref&& ref) {
    Any(std::forward<Ref>(ref)).swap(*this);
    return *this;
  }

  void clear() noexcept {
    ptr.reset();
  }

  bool empty() const noexcept {
    return !ptr;
  }

  const std::type_info& type() const noexcept {
    return ptr ? ptr->type() : typeid(void);
  }
  
  void swap(Any& rhs) noexcept {
    ptr.swap(rhs.ptr);
  }
};

template <typename T>
T* any_cast(Any* p) noexcept {
  if (p && p->ptr)
    if (auto q = dynamic_cast<Any::Impl<T>*>(p->ptr.get()))
      return &q->get();
  return nullptr;
}

template <typename T>
const T* any_cast(const Any* p) noexcept {
  if (p && p->ptr)
    if (auto q = dynamic_cast<const Any::Impl<T>*>(p->ptr.get()))
      return &q->get();
  return nullptr;
}

} // namespace cub

#endif
