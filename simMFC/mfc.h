#ifndef MFC_H
#define MFC_H

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#include <iostream>

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

	virtual BOOL InitInstance()
	{
		cout << "CWinThread::InitInstance()" << endl;
		return TRUE;
	}

	virtual int Run()
	{
		cout << "CWinThread::Run()" << endl;
		return 1;
	}

};

class CWnd;

class CWinApp : public CWinThread
{
public:
    CWinApp* m_pCurrentWinApp;
	CWnd* m_pMainWnd;

public:
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

    virtual BOOL CreateEx();  // -->   PreCreateWindow();
	virtual BOOL Create();
	virtual BOOL PreCreateWindow();
};

class CFrameWnd : public CWnd
{
public:
    CFrameWnd()  { cout << "CFrameWnd �غc��" << endl; }
    ~CFrameWnd() { cout << "CFrameWnd �Ѻc��" << endl; }
	virtual BOOL Create();  //  --> CreateEx(); (CWnd::CreateEx()  -->  CWnd::PreCreateWindow();)
	virtual BOOL CreateEx(){ cout << "�]���S����g�աI" << endl; return TRUE; }
	virtual BOOL PreCreateWindow();
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
