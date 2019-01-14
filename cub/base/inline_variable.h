#ifndef E19586598_7134_1399_A920_2191C5D35D9F
#define E19586598_7134_1399_A920_2191C5D35D9F

#include "cub/base/identity.h"

// Description:
// You can define inline variable(C++17 feature) using 
// `CUB_INLINE_VARIABLE` based on whether or not the 
// feature is supported.

#ifdef __cpp_inline_variables

// define inline variable with initial value.
#define CUB_INLINE_VARIABLE(type, name, value) \
inline constexpr cub::identity_t<type> name = value;

#else // __cpp_inline_variables

#include "cub/base/static_assert.h"

#define CUB_STATIC_CONST(name) StaticConst_##name

// define inline variable with initial value.
#define CUB_INLINE_VARIABLE(type, name, value)           \
template <typename T = void>                             \
struct CUB_STATIC_CONST(name) {                          \
  static constexpr cub::identity_t<type> inst = value;   \
};                                                       \
                                                         \
template <typename T>                                    \
constexpr cub::identity_t<type>                          \
CUB_STATIC_CONST(name)<T>::inst;                         \
                                                         \
inline namespace {                                       \
  constexpr const cub::identity_t<type>& name =          \
  CUB_STATIC_CONST(name)<>::inst;                        \
  STATIC_ASSERT(sizeof(void(*)(decltype(name))) != 0);   \
} // end namespace

// define inline variable with default constructor.
#define CUB_INLINE_VARIABLE_DEFAULT(type, name) \
CUB_INLINE_VARIABLE(type, name, {})

#endif // __cpp_inline_variables

#endif
