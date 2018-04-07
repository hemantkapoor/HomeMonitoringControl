#include <QDebug>
#include "comms/tcp.h"
#include "messagebase.h"
#include "messagemanager.h"

//static instantiation
MessageManager* MessageManager::m_instance = nullptr;

MessageManager::MessageManager(QObject *parent):
    QThread(parent),
    m_stop(false)
{
    m_tcp = new Tcp(parent);
}

void MessageManager::waitForConnection()
{
    if(m_tcp->state() == TcpName::NOT_INITIALISED)
    {
        emit connectingToServer();
        //Wait for signal to be handled
        QThread::msleep(MessageManagerName::SIGNAL_SLEEP_MS);
        m_tcp->connect(m_ipAddress,m_port);
    }
    //Indefinite loop for connection to be establised
    while(m_tcp->state() == TcpName::DISCONNECTED)
    {
        m_tcp->reconnect();
    }
    emit connectionEstablished();
}

MessageManager::~MessageManager()
{
    //Lets call stop
    stop();
}

MessageManager *MessageManager::instance(QObject *parent)
{

    if(m_instance == nullptr)
    {
        m_instance = new MessageManager(parent);
    }
    return m_instance;
}

void MessageManager::connectToServer(const QString & ipAddress, const quint16 port)
{
    m_ipAddress = ipAddress;
    m_port = port;
    start();
}

void MessageManager::run()
{
    qDebug() << "Starting Message Manager Thread";
    //Connect to server
    waitForConnection();
    while(!m_stop)
    {
        QThread::msleep(MessageManagerName::THREAD_SLEEP_MS);

    }
    qDebug() << "Message Manager Thread Stopped";
}

void MessageManager::stop()
{
    qDebug() << "Stopping Message Manager Thread";
    m_stop = true;
    QThread::exit();
    //Wait for thread to be finished
    while(!QThread::wait(MessageManagerName::THREAD_EXIT_WAIT_MS));
    qDebug() << "Message Manager Thread has been stopped";
}
