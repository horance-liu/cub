package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "posix",
    hdrs = [
        "posix_concurrent.h",
        "posix_time.h",
        "posix_filesystem.h",  
    ],
    srcs = [
        "env.cc",
        "posix_concurrent.cc",
        "posix_time.cc",
        "posix_filesystem.cc",        
    ],
    linkopts = ["-lpthread"],    
    deps = [
        "//cub/env/time",
        "//cub/env/concurrent",
        "//cub/env/fs",
        "//cub/env/fs:path",
        "//cub/string:string_view",
        "//cub/base:assertions",
    ],
)

cc_library(
    name = "byte_order",
    hdrs = ["byte_order.h"],
    deps = ["//cub/env"],
)

cc_library(
    name = "library_loader",
    hdrs = ["library_loader.h"],
    deps = ["//cub/env"],
)

cc_library(
    name = "type_name",
    hdrs = ["type_name.h"],
    srcs = ["type_name.cc"],
    deps = ["//cub/env"],
)

cc_test(
    name = "type_name_test",
    srcs = ["type_name_test.cc"],
    deps = [
        ":type_name",
        "//cub/env/posix",        
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)
