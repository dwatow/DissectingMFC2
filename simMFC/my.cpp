#include "my.h"
#include "mfc.h"
using namespace std;

CMyWinApp theApp; //global object

int main()
{
	cout << "main �}�l����" << endl;
	
	CWinApp* pApp = AfxGetApp();
	pApp->InitApplication();  //CWinApp::InitApplication
	pApp->InitInstance();     //CMyWinApp::InitInstance --> CMyFrameWnd
	pApp->Run();              //CwinApp::Run

	cout << "main ��������" << endl;
	return 0;
}

/*
CObject �غc��
CComTarget �غc��
CWinThread �غc��
CWinApp �غc��
CMyWinApp �غc��
main �}�l����
	CWinApp::InitApplication()
	CMyWinApp::InitInstance
	CObject �غc��
	CComTarget �غc��
	CWnd �غc��
	CFrameWnd �غc��
	CMyFrameWnd �غc��
		CFrameWnd::Create()
		Cwnd::CreateEx()
		CFrameWnd::PreCreateWindow()  //�S�^��CFrameWnd
	CWinApp::Run()
main ��������
Press any key to continue
*/

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pMainWnd;
	cout << "CMyWinApp::InitInstance" << endl;
	pMainWnd = new CMyFrameWnd();  //CMyFrameWnd �غc��
	return TRUE;
}

