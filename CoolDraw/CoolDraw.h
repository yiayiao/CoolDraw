
// CoolDraw.h : CoolDraw Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCoolDrawApp:
// �йش����ʵ�֣������ CoolDraw.cpp
//

class CCoolDrawApp : public CWinApp
{
public:
	CCoolDrawApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCoolDrawApp theApp;
