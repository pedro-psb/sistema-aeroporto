# basic setup
cmake_minimum_required(VERSION 3.5)
project(baz VERSION 0.0.1)

# automatic fetch Catch2
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#cmake-targets

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# automatic test registration
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
