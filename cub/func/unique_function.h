#ifndef EDECEDE_8134_1397_FB34_B727FECE2BBB
#define EDECEDE_8134_1397_FB34_B727FECE2BBB

#include "cub/dci/role.h"
#include <utility>
#include <type_traits>

namespace cub {

template <typename Signature>
struct UniqueFunction {
};

template <typename R, typename... Args>
struct UniqueFunction<R(Args...)> {
  DEFINE_ROLE(Wrapper) {
    virtual R operator()(Args...) = 0;
  };

  using RawPointer = R(*)(Args...);
  using WrapperPointer = Wrapper*;

  template <typename F>
  static WrapperPointer make_wrapper(F&& f) {
    struct Impl : Wrapper {
      Impl(F f) : f(std::move(f)) {
      }

      R operator()(Args... args) override {
        return f(std::move(args)...);
      }

    private:
      F f;
    };
    return new Impl(std::forward<F>(f)); 
  };

  UniqueFunction() noexcept : fptr(nullptr) {
  }

  explicit UniqueFunction(RawPointer fptr) noexcept
    : fptr(fptr) {
  }

  explicit UniqueFunction(WrapperPointer wptr) noexcept
    : wrapped(true), wptr(wptr) {
  }

  template <
    typename F,
    typename = typename std::enable_if<
      !std::is_convertible<F, RawPointer>::value &&
      std::is_same<R, decltype((std::declval<F&>())(std::declval<Args>()...))>::value
    >::type
  >
  explicit UniqueFunction(F f) noexcept
    : UniqueFunction(make_wrapper(std::move(f))) {
  }

  UniqueFunction(UniqueFunction&& rhs) noexcept {
    movef(std::move(rhs));
  }

  UniqueFunction& operator=(UniqueFunction&& rhs) noexcept {
    destroy();
    movef(std::move(rhs));
    return *this;
  }

  UniqueFunction(const UniqueFunction& rhs) = delete;
  UniqueFunction& operator=(const UniqueFunction& rhs) = delete;

  ~UniqueFunction() {
    destroy();
  }

  bool isWrapped() const noexcept {
    return wrapped;
  }

  bool isNull() const noexcept {
    return fptr == nullptr;
  }

  explicit operator bool() const noexcept {
    return !isNull();
  }



private:
  void movef(UniqueFunction&& rhs) {
    wrapped = rhs.wrapped;
    fptr = rhs.fptr;
    rhs.fptr = nullptr;
    if (rhs.wrapped) {
      rhs.wrapped = false;
    }    
  }

  void destroy() {
    if (wrapped) {
      delete wptr;
    }
  }


private:
  bool wrapped = false;
  union {
    RawPointer fptr;
    WrapperPointer wptr;
  };

};

} // namespace cub

#endif
