#include "my.h"
#include "mfc.h"
using namespace std;

CMyWinApp theApp; //global object

int main()
{
	cout << "main 開始執行" << endl;
	
	CWinApp* pApp = AfxGetApp();
	pApp->InitApplication();  //CWinApp::InitApplication
	pApp->InitInstance();     //CMyWinApp::InitInstance --> CMyFrameWnd
	pApp->Run();              //CwinApp::Run

	cout << "main 結束執行" << endl;
	return 0;
}

/*
CObject 建構式
CComTarget 建構式
CWinThread 建構式
CWinApp 建構式
CMyWinApp 建構式
main 開始執行
	CWinApp::InitApplication()
	CMyWinApp::InitInstance
	CObject 建構式
	CComTarget 建構式
	CWnd 建構式
	CFrameWnd 建構式
	CMyFrameWnd 建構式
		CFrameWnd::Create()
		Cwnd::CreateEx()
		CFrameWnd::PreCreateWindow()  //又回到CFrameWnd
	CWinApp::Run()
main 結束執行
Press any key to continue
*/

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

BOOL CMyWinApp::InitInstance()
{
	cout << "CMyWinApp::InitInstance" << endl;
	m_pMainWnd = new CMyFrameWnd();  //CMyFrameWnd 建構式
	//CWnd 指標，指向建構出來的CMyFrameWnd。
	//Create() 是CWnd 擁有的virtual 函數，所以看看通往CMyFrameWnd 的下一層有沒有改寫。
	//CFrameWnd 有改寫，再下一層的CMyFrameWnd 沒有改寫。
	//所以呼叫CFrameWnd的Create()

	//在CWnd->CFrameWnd::Create() 呼叫 CreateEx()
	//就是CWnd->CreateEx()，它沒有virtual，而且下一層的CFrameWnd 也沒有改寫
	//在CWnd::CreateEx()下呼叫PreCreateWindow()

	//就是CWnd->PreCreateWindow()，它是virtual，所以要往下找。
	//CFrameWnd::PreCreateWindow()有！有virtual，所以要往下找。
	//CMyFrameWnd::PreCreateWindow()沒有！如果有是執行它了。但是現在是執行上一層。

	return TRUE;
}

