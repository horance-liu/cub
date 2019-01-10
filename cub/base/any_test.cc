#include "cub/base/any.h"
#include "cut/cut.hpp"

using namespace cum;
using namespace cub;

FIXTURE(AnySpec) {
  TEST("empty any") {
    Any any;
    ASSERT_TRUE(any.empty());
  }

  TEST("any: int&&") {
    Any any(2);
    ASSERT_TRUE(any_cast<float>(&any) == nullptr);

    auto result = any_cast<int>(&any);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("copy cons") {
    Any a(2);
    Any b(a);

    auto result = any_cast<int>(&b);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("move assignment") {
    Any a(2);

    int value = 10;
    a = std::move(value);

    auto result = any_cast<int>(&a);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(*result == 10);    
  }

  TEST("move cons") {
    Any a(2);
    Any b(std::move(a));

    ASSERT_TRUE(a.empty());
    ASSERT_FALSE(b.empty());

    auto result = any_cast<int>(&b);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("self-defined value object") {
    struct Integer {
      Integer(int value) : value(value) {
      }

      bool operator==(const Integer& rhs) const {
        return value == rhs.value;
      }
    private:
      int value = 0;
    };

    Any any(Integer(2));
    ASSERT_TRUE(any_cast<int>(&any) == nullptr);

    auto result = any_cast<Integer>(&any);
    ASSERT_TRUE(result != nullptr);
    ASSERT_TRUE(*result == Integer(2));    
  }
};