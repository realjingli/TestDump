#pragma once

#include <QMainWindow>

class MyThread;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_startThreadButton_clicked();

private:
    Ui::MainWindow *ui;

    MyThread *m_thread;

public slots:
    void thread_testing(const QString &text);

};
