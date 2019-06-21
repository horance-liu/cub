#cub_cc_library(
#    NAME
#        any
#    HDRS
#        any.h
#    SRCS
#        any.cc
#    DEPS
#        cub::dci
#    COPTS
#      ${CUB_DEFAULT_COPTS}
#    PUBLIC
#)

#cub_cc_test(
#    NAME
#        any_test
#    SRCS
#        any_test.cc
#    DEPS
#        cub::any
#        cub::static_assert
#        cut
#        cut_main            
#)

cub_cc_library(
    NAME
        assertions
    HDRS
        assertions.h
    DEPS
        cub::status
        cub::log  
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC    
)

cub_cc_library(
    NAME
        comparator
    HDRS
        comparator.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        fwddecl
    HDRS
        fwddecl.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        inplace
    HDRS
        inplace.h
    SRCS
        inplace.cc
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC
)

cub_cc_library(
    NAME
        default
    HDRS
        default.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        keywords
    HDRS
        keywords.h
    DEPS
        cub::default
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        nullptr
    HDRS
        nullptr.h   
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC         
)

cub_cc_test(
    NAME
        nullptr_test
    SRCS
        nullptr_test.cc
    DEPS
        cub::nullptr
        cub::static_assert
        cut
        cut_main        
    
)

#cub_cc_library(
#    NAME
#        optional
#    HDRS
#        optional.h
#        inplace.h
#    
#    SRCS
#        optional.cc    
#    DEPS
#        cub::placement
#    COPTS
#        ${CUB_DEFAULT_COPTS}
#    PUBLIC        
#)

#cub_cc_test(
#    NAME
#        optional_test
#    SRCS
#        optional_test.cc
#    DEPS
#        cub::optional
#        cut
#        cut_main            
#)

cub_cc_library(
    NAME
        placement
    HDRS
        placement.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_test(
    NAME
        placement_test
    SRCS
        placement_test.cc
    DEPS
        cub::placement
        cub::loop
        cub::dci      
        cut
        cut_main        
    
)

cub_cc_library(
    NAME
        ref_counter
    HDRS
        ref_counter.h
        scoped_unref.h        
    
    SRCS
        ref_counter.cc
        scoped_unref.cc            
    
    DEPS
        cub::uncloneable
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_test(
    NAME
        ref_counter_test
    SRCS
        ref_counter_test.cc
    DEPS
        ref_counter   
        cut
        cut_main        
    
)

#cub_cc_library(              
#    NAME
#        safe_equal   
#    HDRS
#        safe_equal.h
#    COPTS
#        ${CUB_DEFAULT_COPTS}
#    PUBLIC        
#)

#cub_cc_test(
#    NAME
#        safe_equal_test
#    SRCS
#        safe_equal_test.cc
#    DEPS
#        cub::safe_equal
#        cub::static_assert
#        cut
#        cut_main            
#)

cub_cc_library(
    NAME
        static_assert
    HDRS
        static_assert.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        status
    HDRS
        status.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        scoped_exit
    HDRS
        scoped_exit.h
    DEPS
        cub::symbol
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_test(
    NAME
        scoped_exit_test
    SRCS
        scoped_exit_test.cc
    DEPS
        cub::scoped_exit
        cut
        cut_main        
    
)

cub_cc_library(
    NAME
        struct_wrapper
    HDRS
        struct_wrapper.h
    DEPS
        cub::static_assert
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_test(
    NAME
        struct_wrapper_test
    SRCS
        struct_wrapper_test.cc
    DEPS
        cub::struct_wrapper
        cut
        cut_main        
    
)

cub_cc_library(
    NAME
        symbol
    HDRS
        symbol.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        uncloneable
    HDRS
        uncloneable.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        hash
    HDRS
        hash.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_library(
    NAME
        identity
    HDRS
        identity.h
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC      
)

cub_cc_library(
    NAME
        inline_variable
    HDRS
        inline_variable.h
    DEPS
        cub::identity
        cub::static_assert
    COPTS
        ${CUB_DEFAULT_COPTS}
    PUBLIC        
)

cub_cc_test(
    NAME
        inline_variable_test
    SRCS
        inline_variable_test.cc
    DEPS
        cub::inline_variable
        cut
        cut_main
    
)
