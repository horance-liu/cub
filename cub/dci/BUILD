package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "dci",
    hdrs = [
        "role.h", 
        "interp/decl_role_interp.h",
        "interp/has_role_interp.h",
        "interp/impl_role_interp.h",
        "interp/roles_undef.h",
    ],
    deps = [
        ":unknown",
        "//cub/base:keywords",
    ],
)

cc_test(
    name = "dci_test",
    srcs = [
        "role_test.cc",
        "has_role_test.cc",
    ],
    deps = [
        ":dci",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)

cc_library(
    name = "unknown",
    hdrs = [
        "interface_def.h",
        "unknown.h",
    ],
)
