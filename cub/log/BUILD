package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "log",
    hdrs = ["log.h"],
    srcs = ["log.cc"],
    deps = [
        "//cub/env/time",
        "//cub/string:str_utils",
    ],
)

cc_library(
    name = "color",
    hdrs = ["color.h"],
    srcs = ["color.cc"],
)
