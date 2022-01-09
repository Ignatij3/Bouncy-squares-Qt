#include "object_handler.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty>
#include <QSurfaceFormat>
#include <thread>

int main(int argc, char* argv[])
{
    WINDOW_WIDTH  = 1200;
    WINDOW_HEIGHT = 720;
    ObjectHandler handler(210);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    shape::MyRectangle rect1(shape::Movement::DYNAMIC, 100, 220, 40, 40, 135);
    shape::MyRectangle rect2(shape::Movement::STATIC, 200, 520, 500, 5, 330);
    shape::MyRectangle rect3(shape::Movement::DYNAMIC, 1200, 520, 35, 35, 30);
    shape::MyRectangle rect4(shape::Movement::DYNAMIC, 600, 400, 50, 50, 180);
    shape::MyRectangle rect5(shape::Movement::DYNAMIC, 100, 20, 5, 5, 350);

    handler.add_object({ { &rect1, "darkred" }, { &rect2, "orange" }, { &rect3, "green" }, { &rect4, "blue" }, { &rect5, "yellow" } });

    engine.rootContext()->setContextProperty("rect1", &rect1);
    engine.rootContext()->setContextProperty("rect2", &rect2);
    engine.rootContext()->setContextProperty("rect3", &rect3);
    engine.rootContext()->setContextProperty("rect4", &rect4);
    engine.rootContext()->setContextProperty("rect5", &rect5);
    engine.load(":/main/qml/main.qml");

    std::thread t1([&]() { return handler.run(); });
    return app.exec();
}

// TODO - написать загрузку внешней конфигурации фигур