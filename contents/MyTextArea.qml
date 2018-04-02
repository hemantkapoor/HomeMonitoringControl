import QtQuick 2.0

Item
{
    id: myTextAreaId
    property int myFontSize: 50
    property RegExpValidator myValidator : RegExpValidator
    {
        regExp: /^.*/
    }
    width: 50
    height: 20
    Rectangle
    {
        anchors.fill: parent
        color: "white"
        border.color: "grey"
        border.width: 2
        TextInput
        {
            anchors.fill: parent
            selectByMouse: true
            selectionColor: 'darkgray'
            selectedTextColor: 'white'
            validator: myValidator

            font
            {
                family: "Helvetica"
                pointSize: myTextAreaId.myFontSize
            }

        }
    }

}
