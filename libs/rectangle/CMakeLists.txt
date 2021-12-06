find_package(Qt6 COMPONENTS Gui REQUIRED)

qt_add_qml_module(rectangle
    URI libs.MyRectangle
    VERSION 1.0
    PLUGIN_TARGET rectangle
    STATIC
    SOURCES
        "rectangle.cpp"
        "rectangle.hpp"
)

target_link_libraries(rectangle PRIVATE
    Qt6::Gui
)