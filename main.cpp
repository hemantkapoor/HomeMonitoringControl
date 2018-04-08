#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "messageManager/messagemanager.h"
#include "connectingPage/connectingpagehandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    ConnectingPageHandler* connectingPage = new ConnectingPageHandler(&app);
    auto temp = MessageManager::instance(&app);
    temp->start();
    //engine.rootContext()->setContextProperty("app", &app);
    engine.rootContext()->setContextProperty("connectingPage", connectingPage);

    return app.exec();
}
