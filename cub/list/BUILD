package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "list",
    hdrs = [
        "apr_ring.h",                
        "list_elem.h",        
        "list.h",
    ],
)

cc_test(
    name = "list_test",
    srcs = ["list_test.cc"],
    copts = [
        "-Wno-invalid-offsetof", 
        "-Iexternal/xunit_cut/include"
    ],    
    deps = [
        ":list",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)
