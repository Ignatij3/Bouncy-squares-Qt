cmake_minimum_required(VERSION 3.5)
project(bouncy_square LANGUAGES CXX)

cmake_policy(SET CMP0071 NEW)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/../bin")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 COMPONENTS Qml Core Gui Quick REQUIRED)
find_package(Qt6 COMPONENTS Qml Core Gui Quick REQUIRED)

add_subdirectory("libs")
add_subdirectory("tests" EXCLUDE_FROM_ALL)

list(APPEND SOURCES
    "src/main.cpp"
    "main.qrc"
)

qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Qml
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    libs
)