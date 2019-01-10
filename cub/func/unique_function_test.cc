#include "cub/func/unique_function.h"
#include "cut/cut.hpp"

using namespace cum;
using namespace cub;

namespace {

using IntFun = UniqueFunction<int()>;

int fourty() {
  return 40; 
}

} // end namespace

FIXTURE(UniqueFunctionSpec) {
  TEST("default cons") {
    IntFun f;
    ASSERT_TRUE(f.isNull());
    ASSERT_FALSE(f.isWrapped());
  }

  TEST("c function") {
    IntFun f(fourty);
    ASSERT_FALSE(f.isNull());
    ASSERT_FALSE(f.isWrapped());
  }

  TEST("stateless lambda") {
    IntFun f([]{ return 40; });
    ASSERT_TRUE(!f.isNull());
    ASSERT_FALSE(f.isWrapped());    
  }

  TEST("stateful lambda") {
    int value = 40;
    IntFun f([value]{ return value; });
    ASSERT_FALSE(f.isNull());
    ASSERT_TRUE(f.isWrapped());
  }

  TEST("move cons: stateless lambda") {
    IntFun f([]{ return 40; });
    IntFun g(std::move(f));

    ASSERT_TRUE(f.isNull());
    ASSERT_FALSE(f.isWrapped());

    ASSERT_FALSE(g.isNull());
    ASSERT_FALSE(g.isWrapped());    
  }

  TEST("move assignment: stateless lambda") {
    IntFun f([]{ return 40; });
    IntFun g;
    g = std::move(f);

    ASSERT_TRUE(f.isNull());
    ASSERT_FALSE(f.isWrapped());

    ASSERT_FALSE(g.isNull());
    ASSERT_FALSE(g.isWrapped());    
  }


  TEST("move assignment: stateful lambda") {
    int value = 40;
    IntFun f([value]{ return value; });
    IntFun g;
    g = std::move(f);

    ASSERT_TRUE(f.isNull());
    ASSERT_FALSE(f.isWrapped());    

    ASSERT_FALSE(g.isNull());
    ASSERT_TRUE(g.isWrapped());
  }
};