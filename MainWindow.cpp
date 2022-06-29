#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

#include "MyThread.h"
#include "Data.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化版本v1.0.0
    // master分支未添加Data class


    // 增加贮藏测试

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

void MainWindow::on_showDataButton_clicked()
{
    Data *data = new Data;
    QString name = data->name();
    QString text = data->text();


    QMessageBox::information(this, "ss", name + " " + text);

    ui->scrollArea;
}

