#include "cub/base/any.h"

namespace cub {

const char* BadAnyCast::what() const noexcept {
    return "bad any cast";
}

Any::Base* Any::Base::make(const Any& rhs) {
  return rhs.ptr ? rhs.ptr->clone() : nullptr;
}

Any::Any(const Any& rhs) : ptr(Base::make(rhs)) {
}

Any& Any::operator=(const Any& rhs) {
  ptr.reset(Base::make(rhs));
  return *this;
}

void Any::clear() noexcept {
  ptr.reset();
}

bool Any::empty() const noexcept {
  return !ptr;
}

void Any::swap(Any& rhs) noexcept {
  ptr.swap(rhs.ptr);
}

} // namespace cub