// Guide2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "Guide2.h"
#include "afxdialogex.h"


// CGuide2 �Ի���

IMPLEMENT_DYNAMIC(CGuide2, CPropertyPage)

CGuide2::CGuide2()
	: CPropertyPage(CGuide2::IDD)
{

}

CGuide2::~CGuide2()
{
}

void CGuide2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGuide2, CPropertyPage)
END_MESSAGE_MAP()


// CGuide2 ��Ϣ�������


BOOL CGuide2::OnSetActive()
{
	CPropertySheet * psheet = (CPropertySheet*) GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
//	psheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}
