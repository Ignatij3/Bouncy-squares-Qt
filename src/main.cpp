#include "object_handler.hpp"
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
    ObjectHandler handler(210, 1200, 720);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    shape::MyRectangle rect1(shape::Movement::DYNAMIC, 100, 220, 40, 40, 135);
    shape::MyRectangle rect2(shape::Movement::STATIC, 200, 520, 75, 75, 330);
    shape::MyRectangle rect3(shape::Movement::DYNAMIC, 1200, 520, 35, 35, 30);
    shape::MyRectangle rect4(shape::Movement::DYNAMIC, 600, 400, 50, 50, 180);
    shape::MyRectangle rect5(shape::Movement::DYNAMIC, 100, 20, 5, 5, 350);

    handler.AddObject(&rect1, "darkred");
    handler.AddObject(&rect2, "orange");
    handler.AddObject(&rect3, "green");
    handler.AddObject(&rect4, "blue");
    handler.AddObject(&rect5, "darkgreen");

    engine.rootContext()->setContextProperty("rect1", &rect1);
    engine.rootContext()->setContextProperty("rect2", &rect2);
    engine.rootContext()->setContextProperty("rect3", &rect3);
    engine.rootContext()->setContextProperty("rect4", &rect4);
    engine.rootContext()->setContextProperty("rect5", &rect5);

    engine.load("qml/main.qml");

    std::thread t1([&]() { return handler.run(); });
    return app.exec();
}
