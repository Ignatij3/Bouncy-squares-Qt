import QtQuick
import QtQuick.Controls
import libs.MyRectangle 1.0

ApplicationWindow {
    id: root
    title: qsTr("Bouncy Squares")
    color: "lightgray"
    width: 1200
    height: 720
    visible: true

    Rectangle {
        x: rect1.centre.x - rect1.width
        y: rect1.centre.y - rect1.height
        width: rect1.width*2
        height: rect1.height*2
        color: rect1.color
    }

    Rectangle {
        x: rect2.centre.x - rect2.width
        y: rect2.centre.y - rect2.height
        width: rect2.width*2
        height: rect2.height*2
        color: rect2.color
    }

    Rectangle {
        x: rect3.centre.x - rect3.width
        y: rect3.centre.y - rect3.height
        width: rect3.width*2
        height: rect3.height*2
        color: rect3.color
    }

    Rectangle {
        x: rect4.centre.x - rect4.width
        y: rect4.centre.y - rect4.height
        width: rect4.width*2
        height: rect4.height*2
        color: rect4.color
    }

    Rectangle {
        x: rect5.centre.x - rect5.width
        y: rect5.centre.y - rect5.height
        width: rect5.width*2
        height: rect5.height*2
        color: rect5.color
    }
}