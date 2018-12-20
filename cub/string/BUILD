package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "string_view",
    hdrs = ["string_view.h"],
    srcs = ["string_view.cc"],
)

cc_test(
    name = "string_view_test",
    srcs = ["string_view_test.cc"],
    deps = [
        ":string_view",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "str_utils",
    hdrs = ["str_utils.h"],
    srcs = ["str_utils.cc"],    
    deps = [":string_view"],    
)

cc_test(
    name = "str_utils_test",
    srcs = ["str_utils_test.cc"],
    deps = [
        ":str_utils",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "str_printf",
    hdrs = ["str_printf.h"],
    srcs = ["str_printf.cc"],
)

cc_test(
    name = "str_printf_test",
    srcs = ["str_printf_test.cc"],
    deps = [
        ":str_printf",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "char_spec",
    hdrs = ["char_spec.h"],
    srcs = ["char_spec.cc"],
)

cc_library(
    name = "scanner",
    hdrs = ["scanner.h"],
    srcs = ["scanner.cc"],
    deps = [
        ":char_spec",
        ":str_utils"
    ],
)

cc_test(
    name = "scanner_test",
    srcs = ["scanner_test.cc"],
    deps = [
        ":scanner",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

