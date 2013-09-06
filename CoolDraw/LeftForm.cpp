// LeftForm.cpp : 实现文件
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
	m_lineWeight = 1;	//线的宽度默认为1
	m_lineColor = RGB(0,0,0);
	m_bkColor = RGB(255,255,255);
	m_mark = 20;
}

CLeftForm::~CLeftForm()
{
}

void CLeftForm::DoDataExchange(CDataExchange* pDX)
{
	//处理mfc 默认的数据交换
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


// CLeftForm 诊断

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

//初始化控件，改变大小，字体和位置
void CLeftForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	SetEditFalse();			//将editbox变为不可输入
	
	//CFont m_font;
	//m_font.CreatePointFont(200,"Arial");	//改变静态文本的样式
	//GetDlgItem(IDC_STATIC_A)->SetFont(&m_font);
	//GetDlgItem(IDC_STATIC_B)->SetFont(&m_font);
	//GetDlgItem(IDC_STATIC_C)->SetFont(&m_font);
	
	cbBox.AddString(_T("y=a*x*x+b*x+c"));		//改变下拉列表
	cbBox.AddString(_T("y=Sin(a*x+b)"));
	cbBox.AddString(_T("y=Cos(a*x+b)"));
	
	m_lineColorStatic.SetWindowTextA(_T("黑色"));
	m_lineBgStatic.SetWindowTextA(_T("背景:"));
	m_lineWightStatic.SetWindowTextA(_T("线宽：一倍线宽"));
}

void CLeftForm::OnClickedDrawbutton()
{
	UpdateData();
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//调用CoolDrawView 中的drawcurve方法，开始打印图形
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
	m_lineWightStatic.SetWindowTextA(_T("线宽：一倍线宽"));
}


void CLeftForm::OnWideThree()
{
	m_lineWeight = 3;
	m_lineWightStatic.SetWindowTextA(_T("线宽：三倍线宽"));
}


void CLeftForm::OnWideTwo()
{
	m_lineWeight = 2;
	m_lineWightStatic.SetWindowTextA(_T("线宽：二倍线宽"));
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
	//如果用户的设置没有完全，消息对话框提示用户输入完整
	/*if(setDialog.m_lineWeight == -1 )
	{
		INT_PTR mes = MessageBox(_T("您的填写不完整"),_T("提示"),MB_ICONQUESTION);
		return ;
	}*/
	//改变设置
	if(setDialog.m_lineWeight != -1)
		m_lineWeight = setDialog.m_lineWeight;
	m_lineColor = setDialog.m_color;
	m_bkColor = setDialog.m_bkColor;
	SetStaticMessage();
}

void CLeftForm::OnBlack()
{
	m_lineColor = RGB(0,0,0);
	m_lineColorStatic.SetWindowTextA("黑色");
	Invalidate();
}


void CLeftForm::OnRed()
{
	m_lineColor = RGB(255,0,0);
	m_lineColorStatic.SetWindowTextA("红色");
	Invalidate();
}


void CLeftForm::OnYellow()
{
	m_lineColor = RGB(255,255,0);
	m_lineColorStatic.SetWindowTextA("黄色");
	Invalidate();
}


void CLeftForm::OnOrange()
{
	m_lineColor = RGB(255,97,0);
	m_lineColorStatic.SetWindowTextA("橙色");
	Invalidate();
}


void CLeftForm::OnGreen()
{
	m_lineColor = RGB(0,255,0);
	m_lineColorStatic.SetWindowTextA("绿色");
	Invalidate();
}


HBRUSH CLeftForm::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	//改变外貌
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

void CLeftForm::OnMark()	//选择调整坐标比例
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
		m_lineWightStatic.SetWindowTextA(_T("线宽：一倍线宽"));
	else if(m_lineWeight == 2)
		m_lineWightStatic.SetWindowTextA(_T("线宽：二倍线宽"));
	else if(m_lineWeight == 3)
		m_lineWightStatic.SetWindowTextA(_T("线宽：三倍线宽"));
	else if(m_lineWeight == 4)
		m_lineWightStatic.SetWindowTextA(_T("线宽：四倍线宽"));
	else if(m_lineWeight == 5)
		m_lineWightStatic.SetWindowTextA(_T("线宽：五倍线宽"));

	if(m_lineColor == RGB(0,0,0))
		m_lineColorStatic.SetWindowTextA(_T("黑色"));
	else if(m_lineColor == RGB(255,0,0))
		m_lineColorStatic.SetWindowTextA(_T("红色"));
	else if(m_lineColor == RGB(255,255,0))
		m_lineColorStatic.SetWindowTextA(_T("黄色"));
	else if(m_lineColor == RGB(255,97,0))
		m_lineColorStatic.SetWindowTextA(_T("橙色"));
	else if(m_lineColor == RGB(0,255,0))
		m_lineColorStatic.SetWindowTextA(_T("绿色"));
	else
		m_lineColorStatic.SetWindowTextA(_T("自定义"));
	Invalidate();
}


void CLeftForm::OnAppAbout()
{
	CAboutDialog about;
	about.DoModal();
}
