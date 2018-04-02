import QtQuick 2.0
import "../contents"

Item
{
    id: connectPageId
    width: parent.width
    height: parent.height
    Rectangle
    {
        anchors.fill: parent
        color: "transparent"
        MyHeadline
        {

        }
        Row
        {
            anchors.verticalCenter: parent.verticalCenter
            spacing: 100
            MyText
            {
                id: ipAddressText
                width: (connectPageId.width/30)*6
                height: 1
                myFontSize: connectPageId.width/30
                myText: "IP ADDRESS"
            }
            MyTextArea
            {
                width: connectPageId.width /4
                height: connectPageId.width/25
                myFontSize: connectPageId.width/30
                myValidator:  RegExpValidator
                {
                    regExp:  /^((?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.){0,3}(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$/
                }

            }
            MyText
            {
                id: portText
                width: (connectPageId.width/30)*2
                height: 1
                myFontSize: connectPageId.width/30
                myText: "Port"

            }
            MyTextArea
            {
                width: connectPageId.width /12
                height: connectPageId.width/25
                myFontSize: connectPageId.width/30
                myValidator:  RegExpValidator
                {
                    regExp:  /^([0-9][0-9][0-9][0-9])$/
                }

            }

        }//End of Row
        Row
        {
            spacing: (parent.width - (connectButtonId.width*2))/2
            width: parent.width
            id: buttonClicks
            anchors
            {
                bottom: parent.bottom
                bottomMargin: 200
                left: parent.left
                leftMargin: 100
            }
            MyButton
            {
                id: connectButtonId
                myButtonText: "Connect"
                myFontSize: 50
            }
            MyButton
            {
                id: exitButtonId
                myButtonText: "Exit"
                myFontSize: 50
                onClicked:
                {
                   Qt.quit()
                }
            }
        }
    }

}