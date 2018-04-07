#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QTcpSocket>

namespace TcpName
{
    const int CONNECTION_WAIT_TIME_MSEC = 5000;
    const int WRITE_WAIT_TIME_MSEC = 500;
    const int READ_WAIT_TIME_MSEC = 500;
    const int MAX_NUMBER_OF_RETRY = 5;

    enum ConnectionStateEnum
    {
        NOT_INITIALISED = 0,
        DISCONNECTED,
        CONNECTED
    };

}

class Tcp : public QObject
{
    Q_OBJECT
public:
    explicit Tcp(QObject *parent = nullptr);
    ~Tcp();
    TcpName::ConnectionStateEnum state() const;

signals:

public slots:
    bool connect(QString ipAddress, quint16 port);
    bool reconnect();
    bool send(const QByteArray&);
    QByteArray receive();

private:
    QTcpSocket* m_socket = nullptr;
    TcpName::ConnectionStateEnum m_state = TcpName::NOT_INITIALISED;
    QString m_ipAddress;
    quint16 m_port;

};

#endif // TCP_H
