cmake_minimum_required(VERSION 3.5)
project(libs)
cmake_policy(SET CMP0071 NEW)

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