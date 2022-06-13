#pragma once

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

    void start();
    void run();

private:
    int m_count;

signals:
    void testing(const QString &text);
};

