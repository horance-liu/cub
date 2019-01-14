#include "cub/base/safe_equal.h"
#include "cub/base/static_assert.h"
#include "cut/cut.hpp"

using namespace cum;
using namespace cub;

FIXTURE(SafeEqualSpec) {
  TEST("1 == 1") {
    STATIC_ASSERT_TYPE(bool, safe_equal(1, 1));
    ASSERT_TRUE(safe_equal(1, 1));
  }

  TEST("1 == 1.0") {
    STATIC_ASSERT_TYPE(bool, safe_equal(1, 1.0));
    ASSERT_TRUE(safe_equal(1, 1.0));
  }
};
