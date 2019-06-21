
cub_cc_library(
    NAME
        array_size
    HDRS
        array_size.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        array
    HDRS
        array.h
    DEPS
        cub::static_assert
        cub::comparator
        cub::placement
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_test(
    NAME
        array_test
    SRCS
        array_test.cc
    DEPS
        cub::array
        cut
        cut_main        
    
)
