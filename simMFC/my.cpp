#include "my.h"
#include "mfc.h"
using namespace std;
CMyWinApp theApp; //global object

int main()
{
	cout << "main �}�l����" << endl;
	
	CWinApp* pApp = AfxGetApp();
	pApp->InitApplication();  //CWinApp::InitApplication
	pApp->InitInstance();     //CMyWinApp::InitInstance
	pApp->Run();              //CwinApp::Run


	cout << "main ��������" << endl;
	return 0;
}

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pMainWnd;
	cout << "CMyWinApp::InitInstance" << endl;
	pMainWnd = new CMyFrameWnd();  //CMyFrameWnd �غc��
	return TRUE;
}

