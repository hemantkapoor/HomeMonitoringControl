#include "messagebase.h"
#include "messagemanager.h"

//static instantiation
MessageManager* MessageManager::m_instance = nullptr;

MessageManager::MessageManager(QObject *parent):QThread(parent)
{

}

MessageManager *MessageManager::instance()
{
    if(m_instance == nullptr)
    {
        m_instance = new MessageManager;
    }
    return m_instance;
}

void MessageManager::run()
{

}
