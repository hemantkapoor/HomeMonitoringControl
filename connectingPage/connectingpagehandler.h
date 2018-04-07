#ifndef CONNECTINGPAGEHANDLER_H
#define CONNECTINGPAGEHANDLER_H

#include <QObject>

class ConnectingPageHandler : public QObject
{
    Q_OBJECT
public:
    explicit ConnectingPageHandler(QObject *parent = nullptr);
    ~ConnectingPageHandler();

signals:

public slots:
};

#endif // CONNECTINGPAGEHANDLER_H
