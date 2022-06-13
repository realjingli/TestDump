#pragma once


#include <Windows.h>
#include <QString>
#include <QApplication>
#include <QDateTime>
#include <DbgHelp.h>

#pragma comment(lib, "dbghelp.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "version.lib")

namespace helper {


QString appVersion()
{
    QString fullName = qApp->applicationFilePath();
    QString result = "";
    char* pData = nullptr;
    do {
        DWORD dwLen = GetFileVersionInfoSize(fullName.toStdWString().c_str(), 0);
        if (0 == dwLen) {
            break;
        }
        pData = new char [dwLen+1];
        BOOL bSuccess = GetFileVersionInfo(fullName.toStdWString().c_str(), 0, dwLen, pData);
        if (!bSuccess) {
            break;
        }
        struct LANGANDCODEPAGE {
            WORD wLanguage;
            WORD wCodePage;
        } *lpTranslate;
        LPVOID lpBuffer = nullptr;
        UINT uLen = 0;
        bSuccess = VerQueryValue(pData, (TEXT("\\VarFileInfo\\Translation")), (LPVOID*)&lpTranslate, &uLen);
        if(!bSuccess) {
            break;
        }
        QString str1, str2;
        str1.setNum(lpTranslate->wLanguage, 16);
        str2.setNum(lpTranslate->wCodePage, 16);
        str1 = "000" + str1;
        str2 = "000" + str2;
        QString verPath = "\\StringFileInfo\\"+ str1.right(4) + str2.right(4) +"\\FileVersion";
        bSuccess = VerQueryValue(pData, (verPath.toStdWString().c_str()), &lpBuffer, &uLen);
        if(!bSuccess) {
            break;
        }
        result = QString::fromUtf16((const unsigned short int *)lpBuffer);
    } while(false);

    if(nullptr != pData) {
        delete[] pData;
    }
    return result;
}

LONG /*__RPC_CALLEE*/ AppCrashHandler(EXCEPTION_POINTERS *exception)
{
    QString path = qApp->applicationDirPath() + "/";
    QString name = qApp->applicationName() + "_" + appVersion() + "_" + QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss") + ".dmp";

    QString fileName = path + "/" + name;
    //创建 Dump 文件
    HANDLE dumpFileHandle = CreateFileA(fileName.toLocal8Bit().data(),
            GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (dumpFileHandle != INVALID_HANDLE_VALUE) {
        //Dump信息
        MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
        dumpInfo.ExceptionPointers = exception;
        dumpInfo.ThreadId = GetCurrentThreadId();
        dumpInfo.ClientPointers = TRUE;
        //写入Dump文件内容
        ::MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFileHandle, MiniDumpNormal, &dumpInfo, NULL, NULL);
        ::CloseHandle(dumpFileHandle);
    } else {
        ::MessageBox(NULL, L"创建Dump文件失败", L"错误", MB_SYSTEMMODAL | MB_ICONERROR | MB_OK);
    }

    // 弹出错误对话框并退出程序
    EXCEPTION_RECORD* record = exception->ExceptionRecord;
    QString errorCode(QString::number(record->ExceptionCode, 16));
    QString errorAddress(QString::number((long long)record->ExceptionAddress, 16));

    QString text = "对于发生的错误，表示诚挚的歉意。\n"
            + QString("请将【%1/%2】发给厂家分析。\n").arg(path, name)
            + QString("错误代码 【%1】\n").arg(errorCode)
            + QString("错误地址 【%1】\n").arg(errorAddress);
    ::MessageBox(NULL, text.toStdWString().c_str(), L"错误", MB_SYSTEMMODAL | MB_ICONERROR | MB_OK);

    return EXCEPTION_EXECUTE_HANDLER;
}



}
