#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H
#include <QThread>
#include <QQueue>

class MessageBase;

class MessageManager : public QThread
{
    Q_OBJECT
public:


    //Singleton pattern
    //Assignment operator
    MessageManager& operator=(const MessageManager&) = delete;
    //copy constructor
    MessageManager (const MessageManager&) = delete;

    static MessageManager* instance();

    void run() override;

private:
    MessageManager(QObject *parent = nullptr);
    static MessageManager* m_instance;
    QQueue<MessageBase*> m_messageQueue;
};

#endif // MESSAGEMANAGER_H
