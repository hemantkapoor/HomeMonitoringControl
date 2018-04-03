#ifndef MESSAGEBASE_H
#define MESSAGEBASE_H

#include <QObject>

class MessageBase : public QObject
{
    Q_OBJECT
public:
    explicit MessageBase(QObject *parent = nullptr);
    virtual QByteArray dataToSend() = 0;
    virtual void dataReceived(QByteArray&) = 0;

signals:

public slots:
};

#endif // MESSAGEBASE_H
