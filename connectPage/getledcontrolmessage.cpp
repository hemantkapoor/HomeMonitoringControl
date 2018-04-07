#include <QDebug>
#include "getledcontrolmessage.h"

GetLedControlMessage::GetLedControlMessage(QObject *parent):MessageBase(parent)
{
    m_message.append(GetLedControlMessageName::MESSAGE_ID);
}

QByteArray GetLedControlMessage::dataToSend()
{
    return QByteArray();
}



void GetLedControlMessage::dataReceived(QByteArray& msg)
{
    qDebug() << "Received message = "<<msg;

}
