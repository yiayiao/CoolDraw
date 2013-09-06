// SetDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "SetDialog.h"
#include "afxdialogex.h"


// CSetDialog �Ի���

IMPLEMENT_DYNAMIC(CSetDialog, CDialogEx)

CSetDialog::CSetDialog(CLeftForm* pParent /*=NULL*/)
	: CDialogEx(CSetDialog::IDD, pParent)
{
	m_lineWeight = pParent->m_lineWeight;
	m_color = pParent->m_lineColor;
	m_bkColor = pParent->m_bkColor;
	/*
	m_lineWeight = -1;
	m_color = RGB(255,0,0);
	m_color = RGB(255,255,255);
	*/
}

CSetDialog::~CSetDialog()
{
}

void CSetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_LINEWEIGHT, m_lineWeightList);
}


BEGIN_MESSAGE_MAP(CSetDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_LINEWEIGHT, &CSetDialog::OnSelchangeComboLineweight)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CSetDialog::OnClickedButtonColor)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_BKC, &CSetDialog::OnClickedButtonBkc)
END_MESSAGE_MAP()


// CSetDialog ��Ϣ�������


BOOL CSetDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_lineWeightList.InsertString(0,_T("һ���߿�"));
	m_lineWeightList.InsertString(1,_T("�����߿�"));
	m_lineWeightList.InsertString(2,_T("�����߿�"));
	m_lineWeightList.InsertString(3,_T("�ı��߿�"));
	m_lineWeightList.InsertString(4,_T("�屶�߿�"));

	//m_showColor.SetWindowTextA(_T("Ԥ��"));

	return true;
}


void CSetDialog::OnSelchangeComboLineweight()
{
	m_lineWeight = m_lineWeightList.GetCurSel() + 1;
}


void CSetDialog::OnClickedButtonColor()
{
	CColorDialog dlg;
	INT_PTR res = dlg.DoModal();
	if(res == IDOK)
	{
		m_color=dlg.GetColor(); //���ѡ�����ɫ
	}
	Invalidate();
}

void CSetDialog::OnClickedButtonBkc()
{
	CColorDialog dlg;
	INT_PTR res = dlg.DoModal();
	if(res == IDOK)
	{
		m_bkColor=dlg.GetColor(); //���ѡ�����ɫ
	}
	Invalidate();
}

HBRUSH CSetDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	//�ı���ò
	if(pWnd->GetDlgCtrlID() == IDC_STATIC_SETC)
	{
		pDC->SetTextColor(m_color);
		pDC->SetBkColor(m_color);
	}
	if(pWnd->GetDlgCtrlID() == IDC_STATIC_BKC2)
	{
		pDC->SetTextColor(m_bkColor);
		pDC->SetBkColor(m_bkColor);
	}
	return hbr;
}


