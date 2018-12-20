package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "fs",
    hdrs = [
        "file_system.h",
    ],
    deps = [
        "//cub/dci",
        "//cub/env",
        "//cub/base:status",
    ],
)

cc_library(
    name = "uri",
    hdrs = ["uri.h"],
    srcs = ["uri.cc"],    
    deps = [
        "//cub/string:string_view",
        "//cub/string:scanner",
    ],
)

cc_test(
    name = "uri_test",
    srcs = ["uri_test.cc"],
    deps = [
        ":uri",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "path",
    hdrs = ["path.h"],
    srcs = ["path.cc"],    
    deps = [
        ":uri",
        "//cub/string:string_view",
    ],
)

cc_test(
    name = "path_test",
    srcs = ["path_test.cc"],
    deps = [
        ":path",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)
