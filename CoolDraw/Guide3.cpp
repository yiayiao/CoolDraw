// Guide3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "Guide3.h"
#include "afxdialogex.h"


// CGuide3 �Ի���

IMPLEMENT_DYNAMIC(CGuide3, CPropertyPage)

CGuide3::CGuide3()
	: CPropertyPage(CGuide3::IDD)
{

}

CGuide3::~CGuide3()
{
}

void CGuide3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGuide3, CPropertyPage)
END_MESSAGE_MAP()


// CGuide3 ��Ϣ�������


BOOL CGuide3::OnSetActive()
{
	CPropertySheet * psheet = (CPropertySheet*) GetParent();
	//psheet->SetWizardButtons(PSWIZB_BACK);
	psheet->SetFinishText(_T("���"));
	return CPropertyPage::OnSetActive();
}
