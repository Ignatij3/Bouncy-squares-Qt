cmake_minimum_required(VERSION 3.14)
project(bouncy_square_tests)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/../bin")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 COMPONENTS Qml Core Gui Quick REQUIRED)
find_package(Qt6 COMPONENTS Qml Core Gui Quick REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/054a986a8513149e8374fc669a5fe40117ca6b41.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if (NOT TARGET libs)
    add_subdirectory("../libs" "build")
endif()

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

add_executable(main
    "main.cpp"
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(main PRIVATE
    "src/object_handler"
    "src/point"
    "src/rectangle"
    "src/shape"
    "src/vector"
)

target_link_libraries(main PRIVATE
    Qt6::Qml
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    gtest_main
    libs
)

add_test(NAME example_test COMMAND main)