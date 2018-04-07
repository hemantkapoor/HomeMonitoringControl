#include <QDebug>
#include "tcp.h"

Tcp::Tcp(QObject *parent) : QObject(parent)
{

}

Tcp::~Tcp()
{
    if(m_socket != nullptr)
    {
        delete m_socket;
    }
    qDebug() << "Socket deleted";
}

bool Tcp::connect(QString ipAddress, quint16 port)
{
    m_socket = new QTcpSocket(this);
    m_ipAddress = ipAddress;
    m_port = port;
    m_socket->connectToHost(ipAddress, port);
    if (m_socket->waitForConnected(TcpName::CONNECTION_WAIT_TIME_MSEC))
    {
        m_state = TcpName::CONNECTED;
        return true;
    }
    return false;
}

bool Tcp::reconnect()
{
    if(m_state == TcpName::CONNECTED) { return true;}

    int counter(0);
    while(counter < TcpName::MAX_NUMBER_OF_RETRY && m_state == TcpName::DISCONNECTED)
    {
        m_socket->connectToHost(m_ipAddress, m_port);
        if (m_socket->waitForConnected(TcpName::CONNECTION_WAIT_TIME_MSEC))
        {
            m_state = TcpName::CONNECTED;
        }
    }
    if(m_state == TcpName::DISCONNECTED) { return false;}
    return true;
}

bool Tcp::send(const QByteArray& data)
{
    if(m_state == TcpName::DISCONNECTED) { return false;}
    qint64 count(0);
    while(count < data.length())
    {
        count += m_socket->write(data);
        if (!m_socket->waitForBytesWritten(TcpName::WRITE_WAIT_TIME_MSEC))
        {
            m_state = TcpName::DISCONNECTED;
            return false;
        }
    }
    return true;
}

QByteArray Tcp::receive()
{
    QByteArray dataReceived;
    if(m_state == TcpName::DISCONNECTED) { return dataReceived;}
    if (!m_socket->waitForReadyRead(TcpName::READ_WAIT_TIME_MSEC))
    {
        //Send empty array to indicate nothing received.
        return dataReceived;
    }
    dataReceived = m_socket->readAll();
    return dataReceived;
}

TcpName::ConnectionStateEnum Tcp::state() const
{
    return m_state;
}
