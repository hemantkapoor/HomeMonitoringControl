import QtQuick 2.7

Item
{
    id: myTextAreaId
    property int myFontSize: 50
    property string myText
    signal valueChanged
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
            id: textInputId
            anchors.fill: parent
            selectByMouse: true
            selectionColor: 'darkgray'
            selectedTextColor: 'white'
            validator: myValidator
            onEditingFinished:
            {
                myTextAreaId.myText = text
                valueChanged()
            }

            font
            {
                family: "Helvetica"
                pointSize: myTextAreaId.myFontSize
            }

        }
    }

}
