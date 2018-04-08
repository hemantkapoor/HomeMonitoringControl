#include <QDebug>
#include "comms/tcp.h"
#include "messagebase.h"
#include "messagemanager.h"

//static instantiation
MessageManager* MessageManager::m_instance = nullptr;

MessageManager::MessageManager(QObject *parent):
    QThread(parent),
    m_stop(false),
    m_abort(false)
{
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
    while(m_tcp->state() == TcpName::DISCONNECTED && !m_abort)
    {
        m_tcp->reconnect();
    }
    if(m_abort)
    {
        emit connectionAborted();
    }
    else
    {
        emit connectionEstablished();
    }
}

MessageManager::~MessageManager()
{
    //Lets call stop
    stop();
    if(m_tcp != nullptr) { delete m_tcp; }
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
    //If the thread is running then we just set abort to be false
    if(isRunning())
    {
        m_abort = false;
        return;
    }
    m_ipAddress = ipAddress;
    m_port = port;
    m_abort = false;
    start();
}

void MessageManager::run()
{
    m_tcp = new Tcp();
    qDebug() << "Starting Message Manager Thread";
    //Connect to server
    waitForConnection();
    while(!m_stop)
    {
        while(m_abort)
        {
            QThread::msleep(MessageManagerName::THREAD_SLEEP_MS);
        }
        if(m_tcp->state() == TcpName::DISCONNECTED)
        {
            waitForConnection();
            continue;
        }

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
