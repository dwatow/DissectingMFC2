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

	virtual BOOL CreateEx(){ cout << "�̫�@�h�ոլݡI" << endl; return TRUE; }
	virtual BOOL PreCreateWindow()
	{
		cout << "�q���F�I�OCMyFrameWnd::PreCreateWindow" << endl;
		return TRUE;
	}
};


class CMyWinApp : public CWinApp
{
public:
    CMyWinApp()  { cout << "CMyWinApp �غc��" << endl; }
    ~CMyWinApp() { cout << "CMyWinApp �Ѻc��" << endl; }
	
	BOOL InitInstance();  //  -->  CMyFrameWnd::CMyFrameWnd()
};
#endif


