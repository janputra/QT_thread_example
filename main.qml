import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button{
        id : but1
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 30
        anchors.leftMargin: 30

        height: 50
        width: 100
        text: "Start"
        onClicked: Controller.start()

    }

    Button{

        anchors.top: parent.top
        anchors.left: but1.right
        anchors.topMargin: 30
        anchors.leftMargin: 30

        height: 50
        width: 100
        text: "Stop"
        onClicked: Controller.stop()
    }

    Text {
        anchors.top: but1.bottom
        anchors.left: but1.left
        anchors.topMargin: 30
        anchors.leftMargin: 100
        id: name
        text: Controller.qml_count
    }
}
