#include "cub/base/inline_variable.h"
#include "cut/cut.hpp"

using namespace cum;
using namespace cub;

namespace {
  struct Adder {
    int operator()(int t, int u) const {
      return t + u;
    }
  };

  CUB_INLINE_VARIABLE_DEFAULT(Adder, add);
}


FIXTURE(InlineVariableSpec) {
  TEST("constexpr inline variable") {
    ASSERT_EQ(3, add(1, 2));
  }
};

