#ifndef MY_H
#define MY_H
#include <iostream>
#include "mfc.h"
using namespace std;


class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd()  { Create();
					 cout << "CMyFrameWnd �غc��" << endl; }
    ~CMyFrameWnd() { cout << "CMyFrameWnd �Ѻc��" << endl; }

	BOOL Create()
	{
		cout << "CFrameWnd::Create()" << endl;
		CreateEx(); //Wnd::CreateEx();
		return TRUE;
	}

	BOOL CreateEx()
	{
		cout << "CFrameWnd::CreateEx()" << endl;
		return TRUE;
	}

	BOOL PreCreateWindow()
	{
		cout << "CFrameWnd::PreCreateWindow()" << endl;
		return TRUE;
	}
};


class CMyWinApp : public CWinApp
{
public:
    CMyWinApp()  { cout << "CMyWinApp �غc��" << endl; }
    ~CMyWinApp() { cout << "CMyWinApp �Ѻc��" << endl; }
	
	BOOL InitInstance()
	{
		CMyFrameWnd* pMainWnd;
		cout << "CMyWinApp::InitInstance" << endl;
		pMainWnd = new CMyFrameWnd();  //CMyFrameWnd �غc��
		return TRUE;
	}
};
#endif


