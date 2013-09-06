
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "CoolDraw.h"

#include "MainFrm.h"

//edit by coolness ����������ͼ��ӵ����ҷִ���
#include "CoolDrawView.h"
#include "CoolDrawDoc.h"
#include "LeftForm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_Menu, &CMainFrame::OnMenu)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	if(!m_wndSplitter.CreateStatic(this,1,2))
		return FALSE;
	CRect rect;
	GetClientRect(&rect);
	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftForm),CSize(rect.Width()/3,rect.Height()),pContext))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CCoolDrawView),CSize(rect.Width()*2/3,rect.Height()),pContext))
		return FALSE;
	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.cx = 900;
	cs.cy = 600;

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::OnMenu()
{
	
	// TODO: �ڴ���������������
}
