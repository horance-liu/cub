cmake_minimum_required(VERSION 3.5)

# Compiler id for Apple Clang is now AppleClang.
cmake_policy(SET CMP0025 NEW)

# if command can use IN_LIST
cmake_policy(SET CMP0057 NEW)

# Project version variables are the empty std::string if version is unspecified
cmake_policy(SET CMP0048 NEW)

project(cub CXX)

add_compile_options(-std=c++14)

# when cub is included as subproject (i.e. using add_subdirectory(cub))
# in the source tree of a project that uses it, install rules are disabled.
if(NOT "^${CMAKE_SOURCE_DIR}$" STREQUAL "^${PROJECT_SOURCE_DIR}$")
  set(CUB_ENABLE_INSTALL FALSE)
else()
  set(CUB_ENABLE_INSTALL TRUE)
endif()

list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_LIST_DIR}/CMake
  ${CMAKE_CURRENT_LIST_DIR}/cub/copts
)

include(cub_install)
include(CMakePackageConfigHelpers)
include(cub_rules)


##
## Using cub targets
##
## all public cub targets are
## exported with the cub:: prefix
##
## e.g cub::base cub::synchronization cub::strings ....
##
## DO NOT rely on the internal targets outside of the prefix


# include current path
list(APPEND CUB_COMMON_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CUB_USING_CLANG ON)
else()
  set(CUB_USING_CLANG OFF)
endif()

# find dependencies
## pthread
find_package(Threads REQUIRED)

option(CUB_USE_CUT_HEAD
  "If ON, cub download HEAD from cut at config time." OFF)

option(CUB_RUN_TESTS "If ON, Cub tests will be run." OFF)

if(${CUB_RUN_TESTS})
  # enable CTest.  This will set BUILD_TESTING to ON unless otherwise specified
  # on the command line
  include(CTest)
  enable_testing()
endif()

## check targets
if(BUILD_TESTING)

  if(${CUB_USE_CUT_HEAD})
    include(cmake/cut/cut_download.cmake)
    set(cub_cut_src_dir ${CMAKE_BINARY_DIR}/cut-src)
    set(cub_cut_build_dir ${CMAKE_BINARY_DIR}/cut-build)
  endif()

  #check_target(cut)
  #check_target(cut_main)

  list(APPEND CUB_TEST_COMMON_LIBRARIES
    cut
    cut_main
    ${CMAKE_THREAD_LIBS_INIT}
  )
endif()

add_subdirectory(cub)

if(CUB_ENABLE_INSTALL)
  # cub:lts-remove-begin(system installation is supported for LTS releases)
  # We don't support system-wide installation
  list(APPEND SYSTEM_INSTALL_DIRS "/usr/local" "/usr" "/opt/" "/opt/local" "c:/Program Files/${PROJECT_NAME}")
  if(NOT DEFINED CMAKE_INSTALL_PREFIX OR CMAKE_INSTALL_PREFIX IN_LIST SYSTEM_INSTALL_DIRS)
    message(WARNING "\
  The default and system-level install directories are unsupported except in LTS \
  releases of Cub.  Please set CMAKE_INSTALL_PREFIX to install Cub in your \
  source or build tree directly.\
    ")
  endif()
  # cub:lts-remove-end

  # install as a subdirectory only
  install(EXPORT ${PROJECT_NAME}Targets
    NAMESPACE cub::
    DESTINATION "${CUB_INSTALL_CONFIGDIR}"
  )

  configure_package_config_file(
    CMake/cubConfig.cmake.in
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CUB_INSTALL_CONFIGDIR}"
  )
  install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    DESTINATION "${CUB_INSTALL_CONFIGDIR}"
  )

  # Cub only has a version in LTS releases.  This mechanism is accomplished
  # Cub's internal Copybara (https://github.com/google/copybara) workflows and
  # isn't visible in the CMake buildsystem itself.
  if(cub_VERSION)
    write_basic_package_version_file(
      "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
      COMPATIBILITY ExactVersion
    )

    install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
      DESTINATION ${CUB_INSTALL_CONFIGDIR}
    )
  endif()  # cub_VERSION

  install(DIRECTORY cub
    DESTINATION ${CUB_INSTALL_INCLUDEDIR}
    FILES_MATCHING
      PATTERN "*.inc"
      PATTERN "*.h"
  )
endif()  # CUB_ENABLE_INSTALL
