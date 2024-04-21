cmake_minimum_required(VERSION 3.16)
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
qt_standard_project_setup()

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

install(TARGETS bouncy_square
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/../bin"
)

qt_generate_deploy_app_script(
    TARGET ${PROJECT_NAME}
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})