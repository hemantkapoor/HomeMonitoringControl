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

QString ConnectingPageHandler::ipAddress() const
{
    return m_ipAddress;
}

quint16 ConnectingPageHandler::port() const
{
    return m_port;
}

void ConnectingPageHandler::handleConnectButtonClick()
{

}

void ConnectingPageHandler::setIpAddress(QString ipAddress)
{
    if (m_ipAddress == ipAddress)
        return;

    m_ipAddress = ipAddress;
    if(!m_ipAddress.isEmpty() && !m_port!=0)
    {
        emit connectButtonControl(true);
    }
    else
    {
        emit connectButtonControl(false);
    }
    emit ipAddressChanged(m_ipAddress);
}

void ConnectingPageHandler::setPort(quint16 port)
{
    if (m_port == port)
        return;

    m_port = port;
    if(!m_ipAddress.isEmpty() && !m_port!=0)
    {
        emit connectButtonControl(true);
    }
    else
    {
        emit connectButtonControl(false);
    }
    emit portChanged(m_port);
}
