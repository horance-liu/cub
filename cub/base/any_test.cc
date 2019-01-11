#include "cub/base/any.h"
#include "cub/base/static_assert.h"
#include "cut/cut.hpp"

using namespace cum;
using namespace cub;

FIXTURE(AnySpec) {
  TEST("empty any") {
    Any any;
    ASSERT_TRUE(any.empty());
  }

  TEST("failed: any(int) -> float") {
    Any any(2);
    ASSERT_TRUE(any.cast<float>() == nullptr);
  }

  TEST("any: int") {
    Any any(2);
    auto result = any.cast<int>();
    
    STATIC_ASSERT_TYPE(int*, result);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("const any") {
    const Any any(2);
    auto result = any.cast<int>();

    STATIC_ASSERT_TYPE(const int*, result);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("copy cons") {
    Any a(2);
    Any b(a);

    auto result = b.cast<int>();
    STATIC_ASSERT_TYPE(int*, result);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("move assignment") {
    Any a(2);

    std::string value("string value");
    a = std::move(value);

    auto result = a.cast<std::string>();
    STATIC_ASSERT_TYPE(std::string*, result);
    ASSERT_TRUE(*result == "string value");    
  }

  TEST("move cons") {
    Any a(2);
    Any b(std::move(a));

    ASSERT_TRUE(a.empty());
    ASSERT_FALSE(b.empty());

    auto result = b.cast<int>();
    STATIC_ASSERT_TYPE(int*, result);
    ASSERT_TRUE(*result == 2);    
  }

  TEST("self-defined value object") {
    struct Integer {
      Integer(int value) : value(value) {
      }

      int value = 0;
    };

    const Any any(Integer(2));
    auto result = any.cast<Integer>();

    STATIC_ASSERT_TYPE(const Integer*, result);
    ASSERT_TRUE(result->value == 2);    
  }
};