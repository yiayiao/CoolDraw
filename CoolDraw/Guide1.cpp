// Guide1.cpp : 实现文件
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "Guide1.h"
#include "afxdialogex.h"


// CGuide1 对话框

IMPLEMENT_DYNAMIC(CGuide1, CPropertyPage)

CGuide1::CGuide1()
	: CPropertyPage(CGuide1::IDD)
{

}

CGuide1::~CGuide1()
{
}

void CGuide1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGuide1, CPropertyPage)
END_MESSAGE_MAP()


// CGuide1 消息处理程序


BOOL CGuide1::OnSetActive()
{
	CPropertySheet * psheet = (CPropertySheet*) GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}
