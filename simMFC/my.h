#ifndef MY_H
#define MY_H
#include <iostream>
#include "mfc.h"
using namespace std;

class CMyWinApp : public CWinApp
{
public:
    CMyWinApp()  { cout << "CMyWinApp 建構式" << endl; }
    ~CMyWinApp() { cout << "CMyWinApp 解構式" << endl; }
};

class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd()  { cout << "CMyFrameWnd 建構式" << endl; }
    ~CMyFrameWnd() { cout << "CMyFrameWnd 解構式" << endl; }
};
#endif


