#ifndef H5B60114C_61E3_4600_971C_356DB8AD102C
#define H5B60114C_61E3_4600_971C_356DB8AD102C

/////////////////////////////////////////////////////////////////
#define CUB_STRINGIZE_IMPL(s) #s
#define CUB_STRINGIZE(s) CUB_STRINGIZE_IMPL(s)

/////////////////////////////////////////////////////////////////
#define CUB_JOIN_AGAIN(s1, s2) s1##s2
#define CUB_JOIN_IMPL(s1, s2) CUB_JOIN_AGAIN(s1, s2)
#define CUB_JOIN(s1, s2) CUB_JOIN_IMPL(s1, s2)

/////////////////////////////////////////////////////////////////
#ifdef __COUNTER__
#  define CUB_UNIQUE_ID __COUNTER__
#else
#  define CUB_UNIQUE_ID __LINE__
#endif

/////////////////////////////////////////////////////////////////
#define CUB_UNIQUE_NAME(prefix) CUB_JOIN(prefix, CUB_UNIQUE_ID)

/////////////////////////////////////////////////////////////////
#define CUB_FRONT_IMPL(e0, ...) e0
#define CUB_FRONT(...) CUB_FRONT_IMPL(__VA_ARGS__, )

/////////////////////////////////////////////////////////////////
#define CUB_POP_FRONT(e0, ...) __VA_ARGS__   

#endif
