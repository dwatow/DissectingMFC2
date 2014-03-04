#ifndef MFC_H
#define MFC_H
#include <iostream>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

using namespace std;
/*
CObject
  +--CComTarget
  |    +--CWinThread  
  |        +--CWinApp -> CMyApp
  +--CWnd
  |   +--CView        -> CMyView
  |   +--CFrameWnd    -> CMyFrameWnd
  +--CDocument        -> CMyDoc
*/

class CObject
{
public:
    CObject()  { cout << "CObject 建構式" << endl; }
    ~CObject() { cout << "CObject 解構式" << endl; }
};

class CComTarget : public CObject
{
public:
    CComTarget()  { cout << "CComTarget 建構式" << endl; }
    ~CComTarget() { cout << "CComTarget 解構式" << endl; }
};

class CWinThread : public CComTarget
{
public:
    CWinThread()  { cout << "CWinThread 建構式" << endl; }
    ~CWinThread() { cout << "CWinThread 解構式" << endl; }
};

class CWinApp : public CWinThread
{
public:
    CWinApp* m_pCurrentWinApp;
    CWinApp()  { m_pCurrentWinApp = this; 
                 cout << "CWinApp 建構式" << endl; }
    ~CWinApp() { cout << "CWinApp 解構式" << endl; }

	BOOL InitApplication()
	{
		cout << "CWinApp::InitApplication()" << endl;
		return TRUE;
	}

	BOOL InitInstance()
	{
		cout << "CWinApp::InitInstance()" << endl;
		return TRUE;
	}

	BOOL Run()
	{
		cout << "CWinApp::Run()" << endl;
		return TRUE;
	}
};

class CDocument : public CComTarget
{
public:
    CDocument()  { cout << "CDocument 建構式" << endl; }
    ~CDocument() { cout << "CDocument 解構式" << endl; }
};

class CWnd : public CComTarget
{
public:
    CWnd()  { cout << "CWnd 建構式" << endl; }
    ~CWnd() { cout << "CWnd 解構式" << endl; }

    BOOL CreateEx()
	{
		cout << "Cwnd::CreateEx()" << endl;
		PreCreateWindow(); //Cwnd有定義，CFrameWnd也有定義
		return TRUE;
	}

	BOOL PreCreateWindow()
	{
		cout << "CWnd::PreCreateWindow()" << endl;
		return TRUE;
	}
};

class CFrameWnd : public CWnd
{
public:
    CFrameWnd()  { cout << "CFrameWnd 建構式" << endl; }
    ~CFrameWnd() { cout << "CFrameWnd 解構式" << endl; }
};

class CView : public CWnd
{
public:
    CView()  { cout << "CView 建構式" << endl; }
    ~CView() { cout << "CView 解構式" << endl; }
};

//global function
CWinApp* AfxGetApp();

#endif
