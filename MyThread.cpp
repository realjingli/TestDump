#include "MyThread.h"

#include <QDebug>

MyThread::MyThread()
{
    m_count = 0;
}

void MyThread::start()
{
    m_count = 0;
    QThread::start();
}

void MyThread::run()
{
    while (!isInterruptionRequested()) {
        m_count++;

        if (m_count > 100)
            break;
        if (m_count == 10) {
            QString *s = nullptr;


            int a = 0;
            int b = 2;
            int c = 3;

            a + b;
            b + c;


            a + b;
            b + c;


            a + b;
            b + c;


            a + b;
            b + c;


            a + b;
            b + c;

            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃
            // 测试程序崩溃



            QString str = "abcdefg";
            int len = str.length();

            qDebug() << "len of str: " << len;

            s->append("aaaaa");

            *s += "bbbb";
            *s += "cccc";
        }

        QString text = QString("thread is testing %1").arg(m_count);
        emit testing(text);

        QThread::msleep(500);
    }
}
