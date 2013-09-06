// GuidSheet.cpp : 实现文件
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "GuidSheet.h"


// CGuidSheet

IMPLEMENT_DYNAMIC(CGuidSheet, CPropertySheet)

CGuidSheet::CGuidSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&guide1);
	AddPage(&guide2);
	AddPage(&guide3);
}

CGuidSheet::CGuidSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&guide1);
	AddPage(&guide2);
	AddPage(&guide3);
}

CGuidSheet::~CGuidSheet()
{
}


BEGIN_MESSAGE_MAP(CGuidSheet, CPropertySheet)
END_MESSAGE_MAP()


// CGuidSheet 消息处理程序
