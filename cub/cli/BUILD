package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "option",
    hdrs = ["option.h"],
    srcs = ["option.cc"],
    deps = [
        "//cub/base:keywords",
        "//cub/string:string_view",
        "//cub/string:str_utils",
        "//cub/string:str_printf",        
        "//cub/string:scanner",
    ],
)

cc_library(
    name = "option_set",
    hdrs = ["option_set.h"],
    srcs = ["option_set.cc"],
    deps = [
        ":option",
    ],
)

cc_test(
    name = "option_set_test",
    srcs = ["option_set_test.cc"],
    deps = [
        ":option_set",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "program_options",
    hdrs = ["program_options.h"],
    srcs = ["program_options.cc"],
    deps = [
        ":option_set",
    ],
)