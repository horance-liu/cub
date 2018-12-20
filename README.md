# CUB(C++ Unified Base) 

CUB(C++ Unified Base) is an open-source collection of modern c++ library. 

## Test 

```bash
$ bazel test //cub/...
```

## Format

```bash
$ tools/clang-format.sh
```

## Help 

```bash
$ echo <<EOF >> WORKSPACE
# curl -L https://github.com/horance-liu/cub/archive/8fabbf1313583080863fea52a6c9b1ff6e1cee91.tar.gz | sha256sum
http_archive(
    name = "github_com_cub",
    sha256 = "2841c3370f68ec91578e93ca168ad4416152af1bb2d30975730c69134128191a",
    strip_prefix = "cub-8fabbf1313583080863fea52a6c9b1ff6e1cee91",
    urls = [
        "https://github.com/horance-liu/cub/archive/8fabbf1313583080863fea52a6c9b1ff6e1cee91.tar.gz",
    ],
)
EOF
```


```bash
cc_test(
    name = "loop_thread_test",
    srcs = [
        "loop_thread_test.cc",
    ],
    deps = [
        "@github_com_cub//cub/env/concurrent:loop_thread",
        "//cub/env/posix",
        "@xunit_cut//:cut",
        "@xunit_cut//:cut_main",        
    ],
)
```
