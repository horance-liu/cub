load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Sanitize a dependency so that it works correctly from code that includes
# TensorFlow as a submodule.
def clean_dep(dep):
  return str(Label(dep))

def cub_workspace(path_prefix="", cub_repo_name=""):
  # using cut for xunit test framework.
  # curl -L https://github.com/horance-liu/cut/archive/v1.0.tar.gz | sha256sum
  http_archive(
      name = "xunit_cut",
      sha256 = "ade2831913d5be97edaa87c3f7d047262a59e266c30ff0a5f2d3edac08b4480e",
      strip_prefix = "cut-release-v1.0",
      urls = [ 
          "https://github.com/horance-liu/cut/archive/release-v1.0.tar.gz",
      ],  
  )

  http_archive(
      name = "nsync",
      urls = [
          "https://mirror.bazel.build/github.com/google/nsync/archive/1.20.0.tar.gz",
          "https://github.com/google/nsync/archive/1.20.0.tar.gz",
      ],
      sha256 = "0c1b03962b2f8450f21e74a5a46116bf2d6009a807c57eb4207e974a8c4bb7dd",
      strip_prefix = "nsync-1.20.0",
  )

  http_archive(
      name = "eigen_archive",
      urls = [
          "https://mirror.bazel.build/bitbucket.org/eigen/eigen/get/fd6845384b86.tar.gz",
          "https://bitbucket.org/eigen/eigen/get/fd6845384b86.tar.gz",
      ],
      sha256 = "d956415d784fa4e42b6a2a45c32556d6aec9d0a3d8ef48baee2522ab762556a9",
      strip_prefix = "eigen-eigen-fd6845384b86",
      build_file = clean_dep("//third_party:eigen.BUILD"),
  )
