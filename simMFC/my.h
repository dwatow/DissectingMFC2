#ifndef MY_H
#define MY_H
#include <iostream>
#include "mfc.h"
using namespace std;


class CMyFrameWnd : public CFrameWnd
{
public:
    CMyFrameWnd()  { cout << "CMyFrameWnd 建構式" << endl; Create();}
    ~CMyFrameWnd() { cout << "CMyFrameWnd 解構式" << endl; }

	virtual BOOL CreateEx(){ cout << "最後一層試試看！" << endl; return TRUE; }
	virtual BOOL PreCreateWindow()
	{
		cout << "猜中了！是CMyFrameWnd::PreCreateWindow" << endl;
		return TRUE;
	}
};


class CMyWinApp : public CWinApp
{
public:
    CMyWinApp()  { cout << "CMyWinApp 建構式" << endl; }
    ~CMyWinApp() { cout << "CMyWinApp 解構式" << endl; }
	
	BOOL InitInstance();  //  -->  CMyFrameWnd::CMyFrameWnd()
};
#endif


