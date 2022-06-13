#include "MainWindow.h"

#include <QApplication>
#include <QDir>
#include <QDateTime>

#include <Windows.h>
#include <DbgHelp.h>

#include "helper.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 注冊异常捕获函数
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)helper::AppCrashHandler);

    MainWindow w;
    w.show();
    return a.exec();
}
