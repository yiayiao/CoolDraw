// Guide1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "Guide1.h"
#include "afxdialogex.h"


// CGuide1 �Ի���

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


// CGuide1 ��Ϣ�������


BOOL CGuide1::OnSetActive()
{
	CPropertySheet * psheet = (CPropertySheet*) GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}
