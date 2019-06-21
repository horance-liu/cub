include(CMakeParseArguments)
include(cub_opts)
include(cub_install)

# The IDE folder for Cub that will be used if Cub is included in a CMake
# project that sets
#    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# For example, Visual Studio supports folders.
set(CUB_IDE_FOLDER Cub)

# cub_cc_library()
#
# CMake function to imitate Bazel's cc_library rule.
#
# Parameters:
# NAME: name of target (see Note)
# HDRS: List of public header files for the library
# SRCS: List of source files for the library
# DEPS: List of other libraries to be linked in to the binary targets
# COPTS: List of private compile options
# DEFINES: List of public defines
# LINKOPTS: List of link options
# PUBLIC: Add this so that this library will be exported under cub::
# Also in IDE, target will appear in Cub folder while non PUBLIC will be in Cub/internal.
# TESTONLY: When added, this target will only be built if user passes -DCUB_RUN_TESTS=ON to CMake.
#
# Note:
# By default, cub_cc_library will always create a library named cub_${NAME},
# and alias target cub::${NAME}.  The cub:: form should always be used.
# This is to reduce namespace pollution.
#
# cub_cc_library(
#   NAME
#     awesome
#   HDRS
#     "a.h"
#   SRCS
#     "a.cc"
# )
# cub_cc_library(
#   NAME
#     fantastic_lib
#   SRCS
#     "b.cc"
#   DEPS
#     cub::awesome # not "awesome" !
#   PUBLIC
# )
#
# cub_cc_library(
#   NAME
#     main_lib
#   ...
#   DEPS
#     cub::fantastic_lib
# )
#
# TODO: Implement "ALWAYSLINK"
function(cub_cc_library)
  cmake_parse_arguments(CUB_CC_LIB
    "DISABLE_INSTALL;PUBLIC;TESTONLY"
    "NAME"
    "HDRS;SRCS;COPTS;DEFINES;LINKOPTS;DEPS"
    ${ARGN}
  )

  if(NOT CUB_CC_LIB_TESTONLY OR CUB_RUN_TESTS)
    if(CUB_ENABLE_INSTALL)
      set(_NAME "${CUB_CC_LIB_NAME}")
    else()
      set(_NAME "cub_${CUB_CC_LIB_NAME}")
    endif()

    # Check if this is a header-only library
    # Note that as of February 2019, many popular OS's (for example, Ubuntu
    # 16.04 LTS) only come with cmake 3.5 by default.  For this reason, we can't
    # use list(FILTER...)
    set(CUB_CC_SRCS "${CUB_CC_LIB_SRCS}")
    foreach(src_file IN LISTS CUB_CC_SRCS)
      if(${src_file} MATCHES ".*\\.(h|inc)")
        list(REMOVE_ITEM CUB_CC_SRCS "${src_file}")
      endif()
    endforeach()
    if("${CUB_CC_SRCS}" STREQUAL "")
      set(CUB_CC_LIB_IS_INTERFACE 1)
    else()
      set(CUB_CC_LIB_IS_INTERFACE 0)
    endif()

    if(NOT CUB_CC_LIB_IS_INTERFACE)
      add_library(${_NAME} STATIC "")
      target_sources(${_NAME} PRIVATE ${CUB_CC_LIB_SRCS} ${CUB_CC_LIB_HDRS})
      target_include_directories(${_NAME}
        PUBLIC
          $<BUILD_INTERFACE:${CUB_COMMON_INCLUDE_DIRS}>
          $<INSTALL_INTERFACE:${CUB_INSTALL_INCLUDEDIR}>
      )
      target_compile_options(${_NAME}
        PRIVATE ${CUB_CC_LIB_COPTS})
      target_link_libraries(${_NAME}
        PUBLIC ${CUB_CC_LIB_DEPS}
        PRIVATE
          ${CUB_CC_LIB_LINKOPTS}
          ${CUB_DEFAULT_LINKOPTS}
      )
      target_compile_definitions(${_NAME} PUBLIC ${CUB_CC_LIB_DEFINES})

      # Add all Cub targets to a a folder in the IDE for organization.
      if(CUB_CC_LIB_PUBLIC)
        set_property(TARGET ${_NAME} PROPERTY FOLDER ${CUB_IDE_FOLDER})
      elseif(CUB_CC_LIB_TESTONLY)
        set_property(TARGET ${_NAME} PROPERTY FOLDER ${CUB_IDE_FOLDER}/test)
      else()
        set_property(TARGET ${_NAME} PROPERTY FOLDER ${CUB_IDE_FOLDER}/internal)
      endif()

      # INTERFACE libraries can't have the CXX_STANDARD property set
      set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD ${CUB_CXX_STANDARD})
      set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

      # When being installed, we lose the cub_ prefix.  We want to put it back
      # to have properly named lib files.  This is a no-op when we are not being
      # installed.
      set_target_properties(${_NAME} PROPERTIES
        OUTPUT_NAME "cub_${_NAME}"
      )
    else()
      # Generating header-only library
      add_library(${_NAME} INTERFACE)
      target_include_directories(${_NAME}
        INTERFACE
          $<BUILD_INTERFACE:${CUB_COMMON_INCLUDE_DIRS}>
          $<INSTALL_INTERFACE:${CUB_INSTALL_INCLUDEDIR}>
        )
      target_link_libraries(${_NAME}
        INTERFACE
          ${CUB_CC_LIB_DEPS}
          ${CUB_CC_LIB_LINKOPTS}
          ${CUB_DEFAULT_LINKOPTS}
      )
      target_compile_definitions(${_NAME} INTERFACE ${CUB_CC_LIB_DEFINES})
    endif()

    # TODO currently we don't install googletest alongside cub sources, so
    # installed cub can't be tested.
    if(NOT CUB_CC_LIB_TESTONLY AND CUB_ENABLE_INSTALL)
      install(TARGETS ${_NAME} EXPORT ${PROJECT_NAME}Targets
            RUNTIME DESTINATION ${CUB_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CUB_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CUB_INSTALL_LIBDIR}
      )
    endif()

    add_library(cub::${CUB_CC_LIB_NAME} ALIAS ${_NAME})
  endif()
endfunction()

# cub_cc_test()
#
# CMake function to imitate Bazel's cc_test rule.
#
# Parameters:
# NAME: name of target (see Usage below)
# SRCS: List of source files for the binary
# DEPS: List of other libraries to be linked in to the binary targets
# COPTS: List of private compile options
# DEFINES: List of public defines
# LINKOPTS: List of link options
#
# Note:
# By default, cub_cc_test will always create a binary named cub_${NAME}.
# This will also add it to ctest list as cub_${NAME}.
#
# Usage:
# cub_cc_library(
#   NAME
#     awesome
#   HDRS
#     "a.h"
#   SRCS
#     "a.cc"
#   PUBLIC
# )
#
# cub_cc_test(
#   NAME
#     awesome_test
#   SRCS
#     "awesome_test.cc"
#   DEPS
#     cub::awesome
#     cut
#     cut_main
# )
function(cub_cc_test)
  if(NOT CUB_RUN_TESTS)
    return()
  endif()

  cmake_parse_arguments(CUB_CC_TEST
    ""
    "NAME"
    "SRCS;COPTS;DEFINES;LINKOPTS;DEPS"
    ${ARGN}
  )

  set(_NAME "cub_${CUB_CC_TEST_NAME}")
  add_executable(${_NAME} "")
  target_sources(${_NAME} PRIVATE ${CUB_CC_TEST_SRCS})
  target_include_directories(${_NAME}
    PUBLIC ${CUB_COMMON_INCLUDE_DIRS}
    PRIVATE ${CUT_INCLUDE_DIRS}
  )
  target_compile_definitions(${_NAME}
    PUBLIC ${CUB_CC_TEST_DEFINES}
  )
  target_compile_options(${_NAME}
    PRIVATE ${CUB_CC_TEST_COPTS}
  )
  target_link_libraries(${_NAME}
    PUBLIC ${CUB_CC_TEST_DEPS}
    PRIVATE ${CUB_CC_TEST_LINKOPTS}
  )
  # Add all Cub targets to a a folder in the IDE for organization.
  set_property(TARGET ${_NAME} PROPERTY FOLDER ${CUB_IDE_FOLDER}/test)

  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD ${CUB_CXX_STANDARD})
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

  add_test(NAME ${_NAME} COMMAND ${_NAME})
endfunction()


function(check_target my_target)
  if(NOT TARGET ${my_target})
    message(FATAL_ERROR " CUB: compiling cub requires ${my_target} target in your project")
  endif(NOT TARGET ${my_target})
endfunction()
