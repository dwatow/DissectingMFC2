#ifndef MY_H
#define MY_H
#include <iostream>
#include "mfc.h"
using namespace std;


class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd()  { cout << "CMyFrameWnd �غc��" << endl; Create();}
    ~CMyFrameWnd() { cout << "CMyFrameWnd �Ѻc��" << endl; }
};


class CMyWinApp : public CWinApp
{
public:
    CMyWinApp()  { cout << "CMyWinApp �غc��" << endl; }
    ~CMyWinApp() { cout << "CMyWinApp �Ѻc��" << endl; }
	
	BOOL InitInstance();  //  -->  CMyFrameWnd::CMyFrameWnd()
};
#endif


