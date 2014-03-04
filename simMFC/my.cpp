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

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pMainWnd;
	cout << "CMyWinApp::InitInstance" << endl;
	pMainWnd = new CMyFrameWnd();  //CMyFrameWnd 建構式
	return TRUE;
}

