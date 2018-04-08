import QtQuick 2.8
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import "./pages"

Window
{
    id: mainWindowId
    visible: true
    width: Screen.width
    height: Screen.height
    //width: 200
    //height: 500
    title: qsTr("Home Monitoring Control")
    visibility: Window.FullScreen
    color: "black"

    StackView
    {
        id: stack
        initialItem: connectPageComponent
        anchors.fill: parent
    }

    Component
    {
        id: connectPageComponent
        ConnectPage
        {
            width: mainWindowId.width
            height: mainWindowId.height
            myStack: stack
        }
    }


}
