
// canbustest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// canbustestApp: 
// �йش����ʵ�֣������ canbustest.cpp
//

class canbustestApp : public CWinApp
{
public:
	canbustestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern canbustestApp theApp;