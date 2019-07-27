package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "array_size",
    hdrs = ["array_size.h"],
)

cc_library(
    name = "array",
    hdrs = ["array.h"],
    deps = [
        "//cub/base:static_assert",
        "//cub/base:comparator",
        "//cub/base:placement",
    ], 
)

cc_test(
    name = "array_test",
    srcs = ["array_test.cc"],
    deps = [
        ":array",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)
