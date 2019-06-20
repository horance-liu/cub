#ifndef HAC57EDDB_4C76_4370_876A_05C7A7318E09
#define HAC57EDDB_4C76_4370_876A_05C7A7318E09

#include "cub/base/symbol.h"
#include <utility>

namespace cub {

template <typename F>
struct ScopedExit {
  ScopedExit(F f) : f(std::move(f)) {
  }

  ~ScopedExit() {
    if (!dismissed) {
      f();
    }
  }

  ScopedExit(ScopedExit&& rhs) noexcept
      : f(std::move(rhs.f)) {
    rhs.dismissed = true;
  }

  void dismiss() {
    dismissed = true;
  }

private:
  bool dismissed = false;
  F f;
};

template <typename F>
ScopedExit<F> make_scoped_exit(F&& f) {
  return {std::forward<F>(f)};
};

#define CUB_SCOPED_EXIT(code) \
auto CUB_UNIQUE_NAME(scoped_exit_) = cub::make_scoped_exit((code))

}  // namespace cub

#endif
