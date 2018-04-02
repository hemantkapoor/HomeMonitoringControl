import QtQuick 2.0

Item {
    property int myFontSize: 50
    property string myText: "Hello World"
    Text
    {
        text: myText
        font
        {
            family: "Helvetica"
            pointSize: myFontSize
        }

        //For Shading effect
        layer.enabled: true
                layer.samplerName: "maskSource"
                layer.effect: ShaderEffect {
                    property var colorSource: gradientRect;
                    fragmentShader: "
                                uniform lowp sampler2D colorSource;
                                uniform lowp sampler2D maskSource;
                                uniform lowp float qt_Opacity;
                                varying highp vec2 qt_TexCoord0;
                                void main() {
                                    gl_FragColor =
                                        texture2D(colorSource, qt_TexCoord0)
                                        * texture2D(maskSource, qt_TexCoord0).a
                                        * qt_Opacity;
                                }
                            "
                }
    }


    //For Text Gradient effect
    Rectangle
    {
        id: gradientRect;
        width: 10
        height: 10
        gradient: Gradient
        {
            GradientStop { position: 0; color: "Black" }
            GradientStop { position: 1; color: "White" }

        }
        visible: false;
        layer.enabled: true;
        layer.smooth: true
    }

}
