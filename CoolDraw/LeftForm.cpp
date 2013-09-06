// LeftForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "LeftForm.h"

#include "CoolDrawView.h"
#include "MainFrm.h"
#include "CoolDrawDoc.h"

#include "SetDialog.h"
#include "MapRadio.h"
#include "AboutDialog.h"

// CLeftForm

IMPLEMENT_DYNCREATE(CLeftForm, CFormView)

CLeftForm::CLeftForm()
	: CFormView(CLeftForm::IDD)
	, a(0), b(0), c(0), d(0), e(0), f(0)
{
	m_pos = -1;
	m_lineWeight = 1;	//�ߵĿ��Ĭ��Ϊ1
	m_lineColor = RGB(0,0,0);
	m_bkColor = RGB(255,255,255);
	m_mark = 20;
}

CLeftForm::~CLeftForm()
{
}

void CLeftForm::DoDataExchange(CDataExchange* pDX)
{
	//����mfc Ĭ�ϵ����ݽ���
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITA, a);
	DDX_Text(pDX, IDC_EDITB, b);
	DDX_Text(pDX, IDC_EDITC, c);
	DDX_Text(pDX, IDC_EDITD, d);
	DDX_Text(pDX, IDC_EDITE, e);
	DDX_Text(pDX, IDC_EDITF, f);
	DDX_Text(pDX, IDC_EDITF, f);

	DDX_Control(pDX, IDC_COMBO1, cbBox);
	DDX_Control(pDX, IDC_STATIC_WIDE, m_lineWightStatic);
	DDX_Control(pDX, IDC_STATIC_COLOR, m_lineColorStatic);
	DDX_Control(pDX, IDC_STATIC_BG, m_lineBgStatic);
	DDX_Control(pDX, IDC_EDIT_EXP, m_exp);
}

BEGIN_MESSAGE_MAP(CLeftForm, CFormView)
	ON_BN_CLICKED(IDC_DRAWBUTTON, &CLeftForm::OnClickedDrawbutton)
	ON_BN_CLICKED(IDC_DRAWBUTTONSYS, &CLeftForm::OnClickedDrawbuttonsys)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLeftForm::OnSelchangeCombo1)
	ON_COMMAND(ID_WIDE_ONE, &CLeftForm::OnWideOne)
	ON_COMMAND(ID_WIDE_THREE, &CLeftForm::OnWideThree)
	ON_COMMAND(ID_WIDE_TWO, &CLeftForm::OnWideTwo)
	ON_UPDATE_COMMAND_UI(ID_WIDE_ONE, &CLeftForm::OnUpdateWideOne)
	ON_UPDATE_COMMAND_UI(ID_WIDE_THREE, &CLeftForm::OnUpdateWideThree)
	ON_UPDATE_COMMAND_UI(ID_WIDE_TWO, &CLeftForm::OnUpdateWideTwo)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CLeftForm::OnBnClickedButtonSet)
	ON_COMMAND(ID_BLACK, &CLeftForm::OnBlack)
	ON_COMMAND(ID_RED, &CLeftForm::OnRed)
	ON_COMMAND(ID_YELLOW, &CLeftForm::OnYellow)
	ON_COMMAND(ID_ORANGE, &CLeftForm::OnOrange)
	ON_COMMAND(ID_GREEN, &CLeftForm::OnGreen)
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_EDIT_UNDO, &CLeftForm::OnEditUndo)
	ON_COMMAND(ID_EDIT_UNDOALL, &CLeftForm::OnEditUndoall)
	ON_COMMAND(ID_MARK, &CLeftForm::OnMark)
	ON_COMMAND(ID_APP_ABOUT, &CLeftForm::OnAppAbout)
END_MESSAGE_MAP()


// CLeftForm ���

#ifdef _DEBUG
void CLeftForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

int CLeftForm::SetEditFalse(void)
{
	GetDlgItem(IDC_EDITA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDITB)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDITC)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDITD)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDITE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDITF)->EnableWindow(FALSE);
	return 0;
}

//��ʼ���ؼ����ı��С�������λ��
void CLeftForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	SetEditFalse();			//��editbox��Ϊ��������
	
	//CFont m_font;
	//m_font.CreatePointFont(200,"Arial");	//�ı侲̬�ı�����ʽ
	//GetDlgItem(IDC_STATIC_A)->SetFont(&m_font);
	//GetDlgItem(IDC_STATIC_B)->SetFont(&m_font);
	//GetDlgItem(IDC_STATIC_C)->SetFont(&m_font);
	
	cbBox.AddString(_T("y=a*x*x+b*x+c"));		//�ı������б�
	cbBox.AddString(_T("y=Sin(a*x+b)"));
	cbBox.AddString(_T("y=Cos(a*x+b)"));
	
	m_lineColorStatic.SetWindowTextA(_T("��ɫ"));
	m_lineBgStatic.SetWindowTextA(_T("����:"));
	m_lineWightStatic.SetWindowTextA(_T("�߿�һ���߿�"));
}

void CLeftForm::OnClickedDrawbutton()
{
	UpdateData();
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//����CoolDrawView �е�drawcurve��������ʼ��ӡͼ��
	CCoolDrawView *pView = (CCoolDrawView*)(pFrame->m_wndSplitter.GetPane(0,1));
	
	char str[200];
	GetDlgItem(IDC_EDIT_EXP)->GetWindowTextA(str,200);
	pView->DrawCurve(str);
}

void CLeftForm::OnClickedDrawbuttonsys()
{
	UpdateData();
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawView *pView = (CCoolDrawView*)(pFrame->m_wndSplitter.GetPane(0,1));
	pView->DrawSysCurve();
}


void CLeftForm::OnSelchangeCombo1()
{
	SetEditFalse();
	m_pos = cbBox.GetCurSel();
	CString str;
	cbBox.GetLBText(cbBox.GetCurSel(),str);
	
	int len = str.GetLength();
	for(int i=0;i<len;i++)
	{
		if(str[i] == 'a')
			GetDlgItem(IDC_EDITA)->EnableWindow(TRUE);
		else if(str[i] == 'b')
			GetDlgItem(IDC_EDITB)->EnableWindow(TRUE);
		else if(str[i] == 'c')
			GetDlgItem(IDC_EDITC)->EnableWindow(TRUE);
		else if(str[i] == 'd')
			GetDlgItem(IDC_EDITD)->EnableWindow(TRUE);
		else if(str[i] == 'e')
			GetDlgItem(IDC_EDITE)->EnableWindow(TRUE);
		else if(str[i] == 'f')
			GetDlgItem(IDC_EDITF)->EnableWindow(TRUE);
	}
}

void CLeftForm::OnWideOne()
{
	m_lineWeight = 1;
	m_lineWightStatic.SetWindowTextA(_T("�߿�һ���߿�"));
}


void CLeftForm::OnWideThree()
{
	m_lineWeight = 3;
	m_lineWightStatic.SetWindowTextA(_T("�߿������߿�"));
}


void CLeftForm::OnWideTwo()
{
	m_lineWeight = 2;
	m_lineWightStatic.SetWindowTextA(_T("�߿������߿�"));
}


void CLeftForm::OnUpdateWideOne(CCmdUI *pCmdUI)
{
	if(m_lineWeight == 1)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

void CLeftForm::OnUpdateWideThree(CCmdUI *pCmdUI)
{
	if(m_lineWeight == 3)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

void CLeftForm::OnUpdateWideTwo(CCmdUI *pCmdUI)
{
	if(m_lineWeight == 2)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}


void CLeftForm::OnBnClickedButtonSet()
{
	INT_PTR nRes;
	CSetDialog setDialog(this);
	nRes = setDialog.DoModal();
	if(IDCANCEL == nRes)
		return ;
	UpdateData(TRUE);
	//����û�������û����ȫ����Ϣ�Ի�����ʾ�û���������
	/*if(setDialog.m_lineWeight == -1 )
	{
		INT_PTR mes = MessageBox(_T("������д������"),_T("��ʾ"),MB_ICONQUESTION);
		return ;
	}*/
	//�ı�����
	if(setDialog.m_lineWeight != -1)
		m_lineWeight = setDialog.m_lineWeight;
	m_lineColor = setDialog.m_color;
	m_bkColor = setDialog.m_bkColor;
	SetStaticMessage();
}

void CLeftForm::OnBlack()
{
	m_lineColor = RGB(0,0,0);
	m_lineColorStatic.SetWindowTextA("��ɫ");
	Invalidate();
}


void CLeftForm::OnRed()
{
	m_lineColor = RGB(255,0,0);
	m_lineColorStatic.SetWindowTextA("��ɫ");
	Invalidate();
}


void CLeftForm::OnYellow()
{
	m_lineColor = RGB(255,255,0);
	m_lineColorStatic.SetWindowTextA("��ɫ");
	Invalidate();
}


void CLeftForm::OnOrange()
{
	m_lineColor = RGB(255,97,0);
	m_lineColorStatic.SetWindowTextA("��ɫ");
	Invalidate();
}


void CLeftForm::OnGreen()
{
	m_lineColor = RGB(0,255,0);
	m_lineColorStatic.SetWindowTextA("��ɫ");
	Invalidate();
}


HBRUSH CLeftForm::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	//�ı���ò
	if(pWnd->GetDlgCtrlID() == IDC_STATIC_FCO)
	{
		pDC->SetBkColor(m_lineColor);
		pDC->SetTextColor(m_lineColor);
	}
	if(pWnd->GetDlgCtrlID() == IDC_STATIC_BKC)
	{
		pDC->SetTextColor(m_bkColor);
		pDC->SetBkColor(m_bkColor);
	}

	//UpdateData();
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawView *pView = (CCoolDrawView*)(pFrame->m_wndSplitter.GetPane(0,1));
	pView->Invalidate();

	return hbr;
}

void CLeftForm::OnEditUndo()
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawView *pView = (CCoolDrawView*)(pFrame->m_wndSplitter.GetPane(0,1));
	pView->DeleteOne();
}


void CLeftForm::OnEditUndoall()
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawView *pView = (CCoolDrawView*)(pFrame->m_wndSplitter.GetPane(0,1));
	pView->DeleteAll();
}

void CLeftForm::OnMark()	//ѡ������������
{
	INT_PTR nRes;
	CMapRadio mapdialog;
	nRes = mapdialog.DoModal();
	if(IDCANCEL == nRes)
		return ;
	UpdateData(TRUE);
	
	m_mark = mapdialog.m_radio;

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawView *pView = (CCoolDrawView*)(pFrame->m_wndSplitter.GetPane(0,1));
	pView->Invalidate();
}

void CLeftForm::SetStaticMessage(void)
{
	if(m_lineWeight == 1)
		m_lineWightStatic.SetWindowTextA(_T("�߿�һ���߿�"));
	else if(m_lineWeight == 2)
		m_lineWightStatic.SetWindowTextA(_T("�߿������߿�"));
	else if(m_lineWeight == 3)
		m_lineWightStatic.SetWindowTextA(_T("�߿������߿�"));
	else if(m_lineWeight == 4)
		m_lineWightStatic.SetWindowTextA(_T("�߿��ı��߿�"));
	else if(m_lineWeight == 5)
		m_lineWightStatic.SetWindowTextA(_T("�߿��屶�߿�"));

	if(m_lineColor == RGB(0,0,0))
		m_lineColorStatic.SetWindowTextA(_T("��ɫ"));
	else if(m_lineColor == RGB(255,0,0))
		m_lineColorStatic.SetWindowTextA(_T("��ɫ"));
	else if(m_lineColor == RGB(255,255,0))
		m_lineColorStatic.SetWindowTextA(_T("��ɫ"));
	else if(m_lineColor == RGB(255,97,0))
		m_lineColorStatic.SetWindowTextA(_T("��ɫ"));
	else if(m_lineColor == RGB(0,255,0))
		m_lineColorStatic.SetWindowTextA(_T("��ɫ"));
	else
		m_lineColorStatic.SetWindowTextA(_T("�Զ���"));
	Invalidate();
}


void CLeftForm::OnAppAbout()
{
	CAboutDialog about;
	about.DoModal();
}
