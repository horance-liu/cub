#ifndef E7BC139B2_C134_1399_AF2C_517D6B0D7716
#define E7BC139B2_C134_1399_AF2C_517D6B0D7716

#include <cmath>
#include <limits>
#include <type_traits>

namespace cub {
  
template <typename T, typename U>
constexpr bool has_float() {
  return std::is_floating_point<T>()
      || std::is_floating_point<U>();
} 

template <typename T, typename U>
std::enable_if_t<!has_float<T, U>(), bool> 
inline safe_equal(const T& lhs, const U& rhs) {
  return lhs == rhs;
}

template <typename T, typename U>
std::enable_if_t<has_float<T, U>(), bool>
inline safe_equal(const T& lhs, const U& rhs) {
  using result_type = decltype(lhs - rhs);
  return std::fabs(lhs - rhs) <= std::numeric_limits<result_type>::epsilon();
}

} // namespace cub


#endif
