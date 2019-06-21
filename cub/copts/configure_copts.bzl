"""cub specific copts.

This file simply selects the correct options from the generated files.  To
change Abseil copts, edit cub/copts/copts.py
"""

load(
    "//cub:copts/GENERATED_copts.bzl",
    "CUB_GCC_EXCEPTIONS_FLAGS",
    "CUB_GCC_FLAGS",
    "CUB_GCC_TEST_FLAGS",
    "CUB_LLVM_EXCEPTIONS_FLAGS",
    "CUB_LLVM_FLAGS",
    "CUB_LLVM_TEST_FLAGS",
    "CUB_MSVC_EXCEPTIONS_FLAGS",
    "CUB_MSVC_FLAGS",
    "CUB_MSVC_LINKOPTS",
    "CUB_MSVC_TEST_FLAGS",
)

CUB_DEFAULT_COPTS = select({
    "//cub:windows": CUB_MSVC_FLAGS,
    "//cub:llvm_compiler": CUB_LLVM_FLAGS,
    "//conditions:default": CUB_GCC_FLAGS,
})

# in absence of modules (--compiler=gcc or -c opt), cc_tests leak their copts
# to their (included header) dependencies and fail to build outside cub
CUB_TEST_COPTS = CUB_DEFAULT_COPTS + select({
    "//cub:windows": CUB_MSVC_TEST_FLAGS,
    "//cub:llvm_compiler": CUB_LLVM_TEST_FLAGS,
    "//conditions:default": CUB_GCC_TEST_FLAGS,
})

CUB_EXCEPTIONS_FLAG = select({
    "//cub:windows": CUB_MSVC_EXCEPTIONS_FLAGS,
    "//cub:llvm_compiler": CUB_LLVM_EXCEPTIONS_FLAGS,
    "//conditions:default": CUB_GCC_EXCEPTIONS_FLAGS,
})

CUB_EXCEPTIONS_FLAG_LINKOPTS = select({
    "//conditions:default": [],
})

CUB_DEFAULT_LINKOPTS = select({
    "//cub:windows": CUB_MSVC_LINKOPTS,
    "//conditions:default": [],
})
