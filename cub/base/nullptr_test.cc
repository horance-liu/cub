#include "cub/base/nullptr.h"
#include "cub/base/static_assert.h"
#include "cut/cut.hpp"

using namespace cum;
using namespace cub;

FIXTURE(NullPtrSpec) {
  TEST("constexpr typed nullptr value") {
    auto p = nullptr_v<int>;
    STATIC_ASSERT_TYPE(int*, p);
  }

  TEST("nullptr literal's type is std::nullptr_t") {
    auto q = nullptr;    
    STATIC_ASSERT_TYPE(std::nullptr_t, q);
  }
};
