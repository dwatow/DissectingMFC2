#include "my.h"
#include "mfc.h"
using namespace std;
CMyWinApp theApp; //global object

int main()
{
	cout << "main 開始執行" << endl;
	
	CWinApp* pApp = AfxGetApp();
	pApp->InitApplication();  //CWinApp::InitApplication
	pApp->InitInstance();     //CMyWinApp::InitInstance
	pApp->Run();              //CwinApp::Run


	cout << "main 結束執行" << endl;
	return 0;
}