cmake_minimum_required(VERSION 3.14)
project(bouncy_square_tests)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/../bin")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/054a986a8513149e8374fc669a5fe40117ca6b41.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(
    "src/object_handler"
    "src/point"
    "src/rectangle"
    "src/shape"
    "src/vector"
)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

add_executable(main "main.cpp" ${SOURCES} ${HEADERS})
target_link_libraries(main gtest_main)
add_test(NAME example_test COMMAND main)