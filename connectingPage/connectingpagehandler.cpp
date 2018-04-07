#include <QDebug>
#include "connectingpagehandler.h"

ConnectingPageHandler::ConnectingPageHandler(QObject *parent) : QObject(parent)
{
    qDebug() <<"ConnectingPageHandler Constructor called";
}

ConnectingPageHandler::~ConnectingPageHandler()
{
    qDebug() <<"ConnectingPageHandler Destructor called";
}
