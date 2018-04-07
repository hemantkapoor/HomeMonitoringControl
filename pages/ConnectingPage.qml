import QtQuick 2.8
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import "../contents"

Item
{
    property StackView myStack
    id: connectingPageId
    width: parent.width
    height: parent.height
    Rectangle
    {

        anchors.fill: parent
        color: "transparent"
        property int fontSize: connectPageId.width/40
        MyHeadline
        {

        }

        Rectangle
        {
            id: busyRectId
            anchors.centerIn: parent
            color: "black"
            width: parent.height/4
            height: parent.height/4
            radius: width * 0.5
            RotationAnimator
            {
                target: busyRectId;
                from: 0;
                to: 360;
                duration: 1500
                running: true
                loops: Animation.Infinite
            }
            Image {
                id: busyId
                source: "../images/busy.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
/*
            ColorOverlay {
                anchors.fill: busyId
                source: busyId
                color: "#ofofof"
            }
            */
        }

        MyButton
        {
            id: abortConnectButtonId
            anchors
            {
                bottom: parent.bottom
                bottomMargin: 200
                horizontalCenter: parent.horizontalCenter
            }

            myButtonText: "ABORT"
            myFontSize: 30
            onClicked:
            {
                myStack.pop()
            }
        }
    }

}

