configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/cut_config_cmake.in
  ${CMAKE_BINARY_DIR}/cut-download/CMakeLists.txt
)

# Configure and build the downloaded cut source
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cut-download )
if(result)
  message(FATAL_ERROR "CMake step for cut failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cut-download)
if(result)
  message(FATAL_ERROR "Build step for cut failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add cut directly to our build. This defines the gtest and gtest_main
# targets.
add_subdirectory(${CMAKE_BINARY_DIR}/cut-src
                 ${CMAKE_BINARY_DIR}/cut-build
                 EXCLUDE_FROM_ALL)
