#include "cub/base/any.h"

namespace cub {

const char* BadAnyCast::what() const noexcept {
    return "bad any cast";
}

Any::Base* Any::clone(const Any& rhs) {
  return rhs.ptr ? rhs.ptr->clone() : nullptr;
}

Any::Any(const Any& rhs) : ptr(Any::clone(rhs)) {
}

Any& Any::operator=(const Any& rhs) {
  ptr.reset(Any::clone(rhs));
  return *this;
}

} // namespace cub