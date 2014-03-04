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
	m_pMainWnd = new CMyFrameWnd();  //CMyFrameWnd �غc��
	//CWnd ���СA���V�غc�X�Ӫ�CMyFrameWnd�C
	//Create() �OCWnd �֦���virtual ��ơA�ҥH�ݬݳq��CMyFrameWnd ���U�@�h���S����g�C
	//CFrameWnd ����g�A�A�U�@�h��CMyFrameWnd �S����g�C
	//�ҥH�I�sCFrameWnd��Create()

	//�bCWnd->CFrameWnd::Create() �I�s CreateEx()
	//�N�OCWnd->CreateEx()�A���S��virtual�A�ӥB�U�@�h��CFrameWnd �]�S����g
	//�bCWnd::CreateEx()�U�I�sPreCreateWindow()

	//�N�OCWnd->PreCreateWindow()�A���Ovirtual�A�ҥH�n���U��C
	//CFrameWnd::PreCreateWindow()���I��virtual�A�ҥH�n���U��C
	//CMyFrameWnd::PreCreateWindow()�S���I�p�G���O���楦�F�C���O�{�b�O����W�@�h�C

	return TRUE;
}

