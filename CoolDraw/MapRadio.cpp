// MapRadio.cpp : 实现文件
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "MapRadio.h"
#include "afxdialogex.h"


// CMapRadio 对话框

IMPLEMENT_DYNAMIC(CMapRadio, CDialogEx)

CMapRadio::CMapRadio(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMapRadio::IDD, pParent)
{
	m_radio = 20;
}

CMapRadio::~CMapRadio()
{
}

void CMapRadio::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RADIO, m_editRadio);
	DDX_Control(pDX, IDC_SLIDERRADIO, m_sliderRadio);
}


BEGIN_MESSAGE_MAP(CMapRadio, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_KILLFOCUS(IDC_EDIT_RADIO, &CMapRadio::OnKillfocusEditRadio)
END_MESSAGE_MAP()


// CMapRadio 消息处理程序


BOOL CMapRadio::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_editRadio.SetWindowTextA(_T("20"));

	m_sliderRadio.SetRange(1,100);
	m_sliderRadio.SetTicFreq(10);
	m_sliderRadio.SetPos(20);

	return TRUE;
}


void CMapRadio::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	m_radio = m_sliderRadio.GetPos();

	char str[10];
	sprintf_s(str,"%d",m_radio);
	m_editRadio.SetWindowTextA(str);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}



void CMapRadio::OnKillfocusEditRadio()
{
	char str[20];
	m_editRadio.GetWindowTextA(str,20);
	int tmp = 20;
	sscanf_s(str, "%d", &tmp);
	m_radio = tmp;
	if(m_radio>100)
		m_sliderRadio.SetPos(100);
	if(m_radio<0)
	{
		m_radio = 1;
		m_sliderRadio.SetPos(1);
		m_editRadio.SetWindowTextA(_T("1"));
	}
}
