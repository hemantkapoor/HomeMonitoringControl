import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Item {
    id: hadlineId
    width: parent.width
    height: parent.height/8
    Rectangle
    {
        width: parent.width
        height: parent.height
        color: "white"

        //Add Awesome color
        LinearGradient
        {
            anchors.fill: parent
            start: Qt.point(0, 0)
            end: Qt.point(0, parent.height)
            gradient: Gradient
            {
                GradientStop { position: 0.0; color: "white" }
                GradientStop { position: 1.0; color: "black" }
            }
        }

        MyText
        {
            id: headlineText
            width: parent.width /2
            height: parent.height
            myFontSize: parent.height
            myText: "Home Monitoring Control"

        }
        Image {
            id: homeIcon
            anchors.right: parent.right
            height: parent.height
            source: "../images/homeIcon.jpeg"
        }
    }

}
