package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "concurrent_executor",
    hdrs = [
        "executor.h",
        "concurrent_executor.h",
        ],
    srcs = ["concurrent_executor.cc"],
    deps = [
        "//cub/env/concurrent:thread_pool",
    ],
)

cc_library(
    name = "simple_executor",
    hdrs = [
        "executor.h",
        "simple_executor.h",
        ],
    srcs = ["simple_executor.cc"],
    deps = [
        "//cub/env/concurrent",
    ],
)

