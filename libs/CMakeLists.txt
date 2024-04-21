cmake_minimum_required(VERSION 3.5)
project(libs)
cmake_policy(SET CMP0071 NEW)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 COMPONENTS Qml Core Gui Quick REQUIRED)
find_package(Qt6 COMPONENTS Qml Core Gui Quick REQUIRED)

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.hpp")

add_library(libs STATIC
    ${SOURCES}
    ${HEADERS}
)

add_subdirectory("rectangle")

target_include_directories(libs PUBLIC
    "float"
    "geometry"
    "logging"
    "object_handler"
    "rectangle"
    "shape"
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt6::Qml
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    rectangle
)