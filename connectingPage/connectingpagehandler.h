#ifndef CONNECTINGPAGEHANDLER_H
#define CONNECTINGPAGEHANDLER_H

#include <QObject>

class ConnectingPageHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)

public:
    explicit ConnectingPageHandler(QObject *parent = nullptr);
    ~ConnectingPageHandler();

QString ipAddress() const;
quint16 port() const;

signals:
    void connectButtonControl(const bool enable);
    void ipAddressChanged(QString ipAddress);
    void portChanged(quint16 port);

public slots:
void handleConnectButtonClick();
void setIpAddress(QString ipAddress);

void setPort(quint16 port);

private:
    QString m_ipAddress;
    quint16 m_port;
};

#endif // CONNECTINGPAGEHANDLER_H
