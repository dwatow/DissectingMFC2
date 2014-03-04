#ifndef MY_H
#define MY_H
#include <iostream>
#include "mfc.h"
using namespace std;


class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd()  { Create();
					 cout << "CMyFrameWnd 建構式" << endl; }
    ~CMyFrameWnd() { cout << "CMyFrameWnd 解構式" << endl; }

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
    CMyWinApp()  { cout << "CMyWinApp 建構式" << endl; }
    ~CMyWinApp() { cout << "CMyWinApp 解構式" << endl; }
	
	BOOL InitInstance()
	{
		CMyFrameWnd* pMainWnd;
		cout << "CMyWinApp::InitInstance" << endl;
		pMainWnd = new CMyFrameWnd();  //CMyFrameWnd 建構式
		return TRUE;
	}
};
#endif


