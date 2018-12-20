package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "notification",
    hdrs = ["notification.h"],
    srcs = ["notification.cc"],
    deps = [
        ":condition_variable",
    ],
)

cc_library(
    name = "mutex",
    hdrs = ["mutex.h"],
    srcs = ["mutex.cc"],
    deps = [
        "@nsync//:nsync_cpp",        
    ],
)


cc_library(
    name = "auto_lock",
    hdrs = ["auto_lock.h"],
    deps = [
        ":mutex",
    ],
)

cc_library(
    name = "shared_lock",
    hdrs = ["shared_lock.h"],
    deps = [
        ":mutex",
    ],
)


cc_library(
    name = "condition_variable",
    hdrs = ["condition_variable.h"],
    srcs = ["condition_variable.cc"],
    deps = [
        ":auto_lock",
    ],
)

cc_library(
    name = "concurrent",
    hdrs = [
        "concurrent.h",
        "thread.h",
    ],
    srcs = ["thread.cc"],
    deps = [
        "//cub/dci",
        "//cub/env",        
    ],
)

cc_library(
    name = "loop_thread",
    hdrs = ["loop_thread.h"],
    srcs = ["loop_thread.cc"],
    deps = [
        ":concurrent",
        ":notification",
        "//cub/env/time",
        "//cub/env/posix",
    ],
)

cc_test(
    name = "loop_thread_test",
    srcs = [
        "loop_thread_test.cc",
    ],
    deps = [
        ":loop_thread",
        "//cub/env/posix",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "thread_pool",
    hdrs = ["thread_pool.h"],
    srcs = ["thread_pool.cc"],
    deps = [
        "//cub/env",  
        ":concurrent",
        "//third_party/eigen3",
    ],
)

