#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariant>
#include "messageManager/messagemanager.h"
#include "connectingPage/connectingpagehandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    ConnectingPageHandler* connectingPage = new ConnectingPageHandler(&app);
    //ConnectingPageHandler connectingPage(&app);
    auto temp = MessageManager::instance(&app);
    temp->start();
    //engine.rootContext()->setContextProperty("app", &app);


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theConnectingPage", connectingPage);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
