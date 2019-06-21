cub_cc_library(
  NAME
    bits
  HDRS
    bits.h
  COPTS
      ${CUB_DEFAULT_COPTS}
  PUBLIC
)

cub_cc_test(
  NAME
    bits_test
  SRCS
    bits_test.cc
  COPTS
    ${CUB_DEFAULT_COPTS}
  DEPS
    bits
    cut
    cut_main
)

cub_cc_library(
    NAME
        bound
    HDRS
        bound.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC
)

cub_cc_test(
    NAME
        bound_test
    SRCS
      bound_test.cc
    DEPS
        bound
        cub::array_size        
        cut
        cut_main        
    
    COPTS
        ${CUB_DEFAULT_COPTS}
)

cub_cc_library(
    NAME
      loop
    HDRS
      loop.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC
)

cub_cc_library(
    NAME
      max_min
    HDRS
      max_min.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC
)

cub_cc_library(
    NAME
      range
    HDRS
      range.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC
)

cub_cc_test(
    NAME
      range_test
    SRCS
      range_test.cc
    DEPS
        range
        cub::static_assert
        cut
        cut_main        
    
    COPTS
        ${CUB_DEFAULT_COPTS}
)

cub_cc_library(
    NAME
      search
    HDRS
      search.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC
)

cub_cc_test(
    NAME
      search_test
    SRCS
      search_test.cc
    DEPS
        search
        cut
        cut_main        
    
    COPTS
        ${CUB_DEFAULT_COPTS}
)