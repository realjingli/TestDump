#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>


#include "MyThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_thread = new MyThread;
    QObject::connect(m_thread, &MyThread::testing, this, &MainWindow::thread_testing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString *s = nullptr;
    s->append("ssfsdsabc");
}

void MainWindow::on_startThreadButton_clicked()
{
    m_thread->start();
}


void MainWindow::thread_testing(const QString &text)
{
    ui->label->setText(text + " 次");
}
