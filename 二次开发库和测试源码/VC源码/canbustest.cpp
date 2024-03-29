
// canbustest.cpp : 定义应用程序的类行为。
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

// canbustestApp 构造


canbustestApp::canbustestApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 canbustestApp 对象

canbustestApp theApp;
CcanbustestDlg *pdig;


void func_hotplugs(void)
{
	printf("func_hotplugs\r\n");
	pdig->hotplugs();
}

// canbustestApp 初始化

BOOL canbustestApp::InitInstance()
{
	CWinApp::InitInstance();


	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));


	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	CcanbustestDlg dlg;
	m_pMainWnd = &dlg;
	pdig = &dlg;
	Reg_HotPlug_Func(&func_hotplugs);
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
	
	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

