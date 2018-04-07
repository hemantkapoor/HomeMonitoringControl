#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H
#include<atomic>
#include <QThread>
#include <QQueue>

class Tcp;
class MessageBase;

namespace MessageManagerName
{
    const quint32 SIGNAL_SLEEP_MS = 100;
    const quint32 THREAD_SLEEP_MS = 2000;
    const quint32 THREAD_EXIT_WAIT_MS = 500;
}

class MessageManager : public QThread
{
    Q_OBJECT
public:

    //Destructor
    ~MessageManager();
    //Singleton pattern
    //Assignment operator
    MessageManager& operator=(const MessageManager&) = delete;
    //copy constructor
    MessageManager (const MessageManager&) = delete;

    static MessageManager* instance(QObject *parent = nullptr);
    void connectToServer(const QString&,const quint16);
    void run() override;
    void stop();

signals:
    void connectingToServer();
    void connectionEstablished();
    void connectionError();
    void reConnecting();

private:
    MessageManager(QObject *parent = nullptr);
    void waitForConnection();



    static MessageManager* m_instance;
    QQueue<MessageBase*> m_messageQueue;

    //For thread
    std::atomic<bool> m_stop;

    //For Comms
    Tcp* m_tcp;

    QString m_ipAddress;
    quint16 m_port;
};

#endif // MESSAGEMANAGER_H
