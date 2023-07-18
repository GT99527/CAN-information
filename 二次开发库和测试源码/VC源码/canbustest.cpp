
// canbustest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "canbustest.h"
#include "canbustestDlg.h"
#include "ucanbus.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// canbustestApp

BEGIN_MESSAGE_MAP(canbustestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// canbustestApp ����


canbustestApp::canbustestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� canbustestApp ����

canbustestApp theApp;
CcanbustestDlg *pdig;


void func_hotplugs(void)
{
	printf("func_hotplugs\r\n");
	pdig->hotplugs();
}

// canbustestApp ��ʼ��

BOOL canbustestApp::InitInstance()
{
	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));


	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	CcanbustestDlg dlg;
	m_pMainWnd = &dlg;
	pdig = &dlg;
	Reg_HotPlug_Func(&func_hotplugs);
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
	
	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

