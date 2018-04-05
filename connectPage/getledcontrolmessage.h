#ifndef GETLEDCONTROLMESSAGE_H
#define GETLEDCONTROLMESSAGE_H
#include "messageManager/messagebase.h"
class MessageBase;

namespace GetLedControlMessageName
{
    const QString MESSAGE_ID = "GLC";

}

class GetLedControlMessage : public MessageBase
{
    Q_OBJECT
public:
    GetLedControlMessage(QObject *parent = nullptr);
    QByteArray dataToSend() override;
    void dataReceived(QByteArray&) override;

private:
    QByteArray m_message;
};

#endif // GETLEDCONTROLMESSAGE_H
