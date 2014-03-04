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
    CObject()  { cout << "CObject �غc��" << endl; }
    ~CObject() { cout << "CObject �Ѻc��" << endl; }
};

class CComTarget : public CObject
{
public:
    CComTarget()  { cout << "CComTarget �غc��" << endl; }
    ~CComTarget() { cout << "CComTarget �Ѻc��" << endl; }
};

class CWinThread : public CComTarget
{
public:
    CWinThread()  { cout << "CWinThread �غc��" << endl; }
    ~CWinThread() { cout << "CWinThread �Ѻc��" << endl; }
};

class CWinApp : public CWinThread
{
public:
    CWinApp* m_pCurrentWinApp;
    CWinApp()  { m_pCurrentWinApp = this; 
                 cout << "CWinApp �غc��" << endl; }
    ~CWinApp() { cout << "CWinApp �Ѻc��" << endl; }

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
    CDocument()  { cout << "CDocument �غc��" << endl; }
    ~CDocument() { cout << "CDocument �Ѻc��" << endl; }
};

class CWnd : public CComTarget
{
public:
    CWnd()  { cout << "CWnd �غc��" << endl; }
    ~CWnd() { cout << "CWnd �Ѻc��" << endl; }

    BOOL CreateEx()
	{
		cout << "Cwnd::CreateEx()" << endl;
		PreCreateWindow(); //Cwnd���w�q�ACFrameWnd�]���w�q
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
    CFrameWnd()  { cout << "CFrameWnd �غc��" << endl; }
    ~CFrameWnd() { cout << "CFrameWnd �Ѻc��" << endl; }
};

class CView : public CWnd
{
public:
    CView()  { cout << "CView �غc��" << endl; }
    ~CView() { cout << "CView �Ѻc��" << endl; }
};

//global function
CWinApp* AfxGetApp();

#endif
