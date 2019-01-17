#include "cub/base/scoped_exit.h"
#include "cut/cut.hpp"
#include <stdexcept>

using namespace cum;
using namespace cub;

FIXTURE(ScopedExitSpec) {
  TEST("should invoke callback") {
    auto invoked = false;
    {
      CUB_SCOPED_EXIT([&invoked]{
        invoked = true;
      });
    }
    ASSERT_TRUE(invoked);
  }

  TEST("should invoke callback if throw runtime exception") {
    auto invoked = false;
    try {
      CUB_SCOPED_EXIT([&invoked]{
        invoked = true;
      });
      throw std::exception();
    } catch(const std::exception&) {
      ASSERT_TRUE(invoked);
    }
  }
};
