"""GENERATED! DO NOT MANUALLY EDIT THIS FILE.

(1) Edit cub/copts/copts.py.
(2) Run `python <path_to_cub>/copts/generate_copts.py`.
"""

CUB_CLANG_CL_EXCEPTIONS_FLAGS = [
    "/U_HAS_EXCEPTIONS",
    "/D_HAS_EXCEPTIONS=1",
    "/EHsc",
]

CUB_CLANG_CL_FLAGS = [
    "/W3",
    "-Wno-c++98-compat-pedantic",
    "-Wno-conversion",
    "-Wno-covered-switch-default",
    "-Wno-deprecated",
    "-Wno-disabled-macro-expansion",
    "-Wno-double-promotion",
    "-Wno-comma",
    "-Wno-extra-semi",
    "-Wno-extra-semi-stmt",
    "-Wno-packed",
    "-Wno-padded",
    "-Wno-sign-compare",
    "-Wno-float-conversion",
    "-Wno-float-equal",
    "-Wno-format-nonliteral",
    "-Wno-gcc-compat",
    "-Wno-global-constructors",
    "-Wno-exit-time-destructors",
    "-Wno-nested-anon-types",
    "-Wno-non-modular-include-in-module",
    "-Wno-old-style-cast",
    "-Wno-range-loop-analysis",
    "-Wno-reserved-id-macro",
    "-Wno-shorten-64-to-32",
    "-Wno-switch-enum",
    "-Wno-thread-safety-negative",
    "-Wno-unknown-warning-option",
    "-Wno-unreachable-code",
    "-Wno-unused-macros",
    "-Wno-weak-vtables",
    "-Wno-zero-as-null-pointer-constant",
    "-Wbitfield-enum-conversion",
    "-Wbool-conversion",
    "-Wconstant-conversion",
    "-Wenum-conversion",
    "-Wint-conversion",
    "-Wliteral-conversion",
    "-Wnon-literal-null-conversion",
    "-Wnull-conversion",
    "-Wobjc-literal-conversion",
    "-Wno-sign-conversion",
    "-Wstring-conversion",
    "/DNOMINMAX",
    "/DWIN32_LEAN_AND_MEAN",
    "/D_CRT_SECURE_NO_WARNINGS",
    "/D_SCL_SECURE_NO_WARNINGS",
    "/D_ENABLE_EXTENDED_ALIGNED_STORAGE",
]

CUB_CLANG_CL_TEST_FLAGS = [
    "-Wno-c99-extensions",
    "-Wno-deprecated-declarations",
    "-Wno-missing-noreturn",
    "-Wno-missing-prototypes",
    "-Wno-missing-variable-declarations",
    "-Wno-null-conversion",
    "-Wno-shadow",
    "-Wno-shift-sign-overflow",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-member-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
    "-Wno-unused-template",
    "-Wno-used-but-marked-unused",
    "-Wno-zero-as-null-pointer-constant",
    "-Wno-gnu-include-next",
    "-Wno-gnu-zero-variadic-macro-arguments",
]

CUB_GCC_EXCEPTIONS_FLAGS = [
    "-fexceptions",
]

CUB_GCC_FLAGS = [
    "-Wall",
    "-Wextra",
    "-Wcast-qual",
    "-Wconversion-null",
    "-Wmissing-declarations",
    "-Woverlength-strings",
    "-Wpointer-arith",
    "-Wunused-local-typedefs",
    "-Wunused-result",
    "-Wvarargs",
    "-Wvla",
    "-Wwrite-strings",
    "-Wno-missing-field-initializers",
    "-Wno-sign-compare",
]

CUB_GCC_TEST_FLAGS = [
    "-Wno-conversion-null",
    "-Wno-deprecated-declarations",
    "-Wno-missing-declarations",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
]

CUB_LLVM_EXCEPTIONS_FLAGS = [
    "-fexceptions",
]

CUB_LLVM_FLAGS = [
    "-Wall",
    "-Wextra",
    "-Weverything",
    "-Wno-c++98-compat-pedantic",
    "-Wno-conversion",
    "-Wno-covered-switch-default",
    "-Wno-deprecated",
    "-Wno-disabled-macro-expansion",
    "-Wno-double-promotion",
    "-Wno-comma",
    "-Wno-extra-semi",
    "-Wno-extra-semi-stmt",
    "-Wno-packed",
    "-Wno-padded",
    "-Wno-sign-compare",
    "-Wno-float-conversion",
    "-Wno-float-equal",
    "-Wno-format-nonliteral",
    "-Wno-gcc-compat",
    "-Wno-global-constructors",
    "-Wno-exit-time-destructors",
    "-Wno-nested-anon-types",
    "-Wno-non-modular-include-in-module",
    "-Wno-old-style-cast",
    "-Wno-range-loop-analysis",
    "-Wno-reserved-id-macro",
    "-Wno-shorten-64-to-32",
    "-Wno-switch-enum",
    "-Wno-thread-safety-negative",
    "-Wno-unknown-warning-option",
    "-Wno-unreachable-code",
    "-Wno-unused-macros",
    "-Wno-weak-vtables",
    "-Wno-zero-as-null-pointer-constant",
    "-Wbitfield-enum-conversion",
    "-Wbool-conversion",
    "-Wconstant-conversion",
    "-Wenum-conversion",
    "-Wint-conversion",
    "-Wliteral-conversion",
    "-Wnon-literal-null-conversion",
    "-Wnull-conversion",
    "-Wobjc-literal-conversion",
    "-Wno-sign-conversion",
    "-Wstring-conversion",
]

CUB_LLVM_TEST_FLAGS = [
    "-Wno-c99-extensions",
    "-Wno-deprecated-declarations",
    "-Wno-missing-noreturn",
    "-Wno-missing-prototypes",
    "-Wno-missing-variable-declarations",
    "-Wno-null-conversion",
    "-Wno-shadow",
    "-Wno-shift-sign-overflow",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-member-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
    "-Wno-unused-template",
    "-Wno-used-but-marked-unused",
    "-Wno-zero-as-null-pointer-constant",
    "-Wno-gnu-include-next",
    "-Wno-gnu-zero-variadic-macro-arguments",
]

CUB_MSVC_EXCEPTIONS_FLAGS = [
    "/U_HAS_EXCEPTIONS",
    "/D_HAS_EXCEPTIONS=1",
    "/EHsc",
]

CUB_MSVC_FLAGS = [
    "/W3",
    "/DNOMINMAX",
    "/DWIN32_LEAN_AND_MEAN",
    "/D_CRT_SECURE_NO_WARNINGS",
    "/D_SCL_SECURE_NO_WARNINGS",
    "/D_ENABLE_EXTENDED_ALIGNED_STORAGE",
    "/wd4005",
    "/wd4068",
    "/wd4180",
    "/wd4244",
    "/wd4267",
    "/wd4503",
    "/wd4800",
]

CUB_MSVC_LINKOPTS = [
    "-ignore:4221",
]

CUB_MSVC_TEST_FLAGS = [
    "/wd4018",
    "/wd4101",
    "/wd4503",
    "/wd4996",
    "/DNOMINMAX",
]
