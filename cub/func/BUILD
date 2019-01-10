package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "unique_function",
    hdrs = ["unique_function.h"],
    deps = ["//cub/dci"],
)

cc_test(
    name = "unique_function_test",
    srcs = ["unique_function_test.cc"],
    deps = [
        ":unique_function",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)
