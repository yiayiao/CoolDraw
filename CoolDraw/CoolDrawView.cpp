
// CoolDrawView.cpp : CCoolDrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "CoolDraw.h"
#endif

#include "CoolDrawDoc.h"
#include "CoolDrawView.h"

#include "MainFrm.h"
#include "LeftForm.h"

#include "Curve.h"
#include "Calculat.h"

#include <cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCoolDrawView

IMPLEMENT_DYNCREATE(CCoolDrawView, CView)

BEGIN_MESSAGE_MAP(CCoolDrawView, CView)	//����ʧЧ��
//	ON_COMMAND(ID_EDIT_UNDO, &CCoolDrawView::OnEditUndo)
//	ON_COMMAND(ID_EDIT_UNDOALL, &CCoolDrawView::OnEditUndoall)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CCoolDrawView ����/����

CCoolDrawView::CCoolDrawView()
{
	m_mark = 20;
}

CCoolDrawView::~CCoolDrawView()
{
}

BOOL CCoolDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// CCoolDrawView ����
void CCoolDrawView::OnDraw(CDC* pDC)
{
	CCoolDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	////////////////����������
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CLeftForm *pView = (CLeftForm*)(pFrame->m_wndSplitter.GetPane(0,0));
	m_mark = pView->m_mark;
	m_bkColor = pView->m_bkColor;
	OnEraseBkgnd(pDC);	//���ı���	

	CRect rect;
	GetClientRect(&rect);
	double x = (rect.left+rect.right)/2;
	double y = (rect.top+rect.bottom)/2;
	origin = CPoint(x,y);
	int num = m_array.GetSize();
	for(int i=0;i<num;i++)
	{
		CCurve * tmp = (CCurve*) m_array.GetAt(i);
		CPen newPen;
		newPen.CreatePen(PS_SOLID,tmp->m_weight, tmp->m_color);
		//pDC->SelectObject(&newPen);
		CPen *pOldPen = pDC->SelectObject(&newPen);
		if(tmp->rank == -2)
		{
			DrawExpCurve(tmp->str,pDC);	
		}
		else if(tmp->rank == 0)
		{
			DrawLine(tmp->a,tmp->b,tmp->c,pDC);
		}
		else if(tmp->rank == 1)
		{
			DrawCos(tmp->a,tmp->b,pDC);
		}
		else if(tmp->rank == 2)
		{
			DrawSin(tmp->a,tmp->b,pDC);
		}
		pDC->SelectObject(pOldPen);			//��סһ��Ҫд���
		newPen.DeleteObject();
		newPen.DeleteObject();
	}	
}

BOOL CCoolDrawView::OnEraseBkgnd(CDC* pDC)
{
	//����brushΪϣ���ı�����ɫ
	CBrush backBrush(m_bkColor);

	//����ɵ�brush
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect;
	pDC->GetClipBox(&rect);

	//����Ҫ������
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);

	//�軭����ϵ
	DrawCoordinate();	
	return CView::OnEraseBkgnd(pDC);
}


// CCoolDrawView ���

#ifdef _DEBUG
void CCoolDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CCoolDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoolDrawDoc* CCoolDrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoolDrawDoc)));
	return (CCoolDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CCoolDrawView ��Ϣ�������



bool CCoolDrawView::DrawCurve(char str[])
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawDoc *pDoc = (CCoolDrawDoc*)(pFrame->GetActiveDocument());
	CLeftForm *pView = (CLeftForm*)(pFrame->m_wndSplitter.GetPane(0,0));

	m_color = pView->m_lineColor;
	m_weight = pView->m_lineWeight;
	//////////////////��û���
	CDC *pDC = GetDC();
	CPen newPen;
	newPen.CreatePen(PS_SOLID,m_weight,m_color);
	CPen *pOldPen = pDC->SelectObject(&newPen);
	DrawExpCurve(str, pDC);
	//��ʾ������û�б�ҪpDC->TextOutA(10,10,str);

	CCurve * m_curve;
	m_curve = new CCurve(str,m_color,m_weight);
	m_array.Add(m_curve);
	
	pDC->SelectObject(pOldPen);
	newPen.DeleteObject();
	return TRUE;
}


bool CCoolDrawView::DrawSysCurve(void)
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CCoolDrawDoc *pDoc = (CCoolDrawDoc*)(pFrame->GetActiveDocument());
	CLeftForm *pView = (CLeftForm*)(pFrame->m_wndSplitter.GetPane(0,0));
	if(pView->m_pos == -1)
		return FALSE;
	m_color = pView->m_lineColor;
	m_weight = pView->m_lineWeight;
	//////////////////��û���
	CDC *pDC = GetDC();
	CPen newPen;
	newPen.CreatePen(PS_SOLID,m_weight,m_color);
	CPen *pOldPen = pDC->SelectObject(&newPen);
	///////////////////���ݲ�ͬ��ѡ�л��Ʋ�ͬ����
	double a = pView->a;
	double b = pView->b;
	if(pView->m_pos == 0)
	{
		double c = pView->c;
		DrawLine(a,b,c,pDC);
		CCurve * m_curve;
		m_curve = new CCurve(a,b,c,m_color,m_weight,0);
		m_array.Add(m_curve);
	}
	else if(pView->m_pos == 1)
	{
		DrawCos(a,b,pDC);
		CCurve * m_curve;
		m_curve = new CCurve(a,b,0,m_color,m_weight,1);
		m_array.Add(m_curve);
	}
	else if(pView->m_pos == 2)
	{
		DrawSin(a,b,pDC);
		CCurve * m_curve;
		m_curve = new CCurve(a,b,0,m_color,m_weight,2);
		m_array.Add(m_curve);
	}
	pDC->SelectObject(pOldPen);	//?about thisd
	newPen.DeleteObject();
	return TRUE;
}


bool CCoolDrawView::DrawCoordinate(void)
{
	CRect rect;
	GetClientRect(&rect);

	CDC *pDC = GetDC();
	pDC->SetBkMode(TRANSPARENT);	//����͸����
	//���������
	CPoint origin( (rect.left+rect.right)/2,(rect.top+rect.bottom)/2);
	pDC->MoveTo(origin);
	pDC->TextOutA(origin.x-10,origin.y,_T("O"));
	pDC->LineTo(origin.x , rect.bottom-5);
	pDC->MoveTo(origin);
	pDC->LineTo(origin.x , rect.top + 5);
	pDC->TextOutA(origin.x-10,rect.top + 5, _T("Y"));
	pDC->MoveTo(origin);
	pDC->LineTo(rect.left+5 , origin.y);
	pDC->MoveTo(origin);
	pDC->LineTo(rect.right-5, origin.y);
	pDC->TextOutA(rect.right-20 ,origin.y , _T("X"));
	//���̶�
	for(int i=0;i<=origin.x-5;i+=m_mark)
	{
		pDC->MoveTo(CPoint(origin.x+i , origin.y-2));
		pDC->LineTo(CPoint(origin.x+i , origin.y));
		pDC->MoveTo(CPoint(origin.x-i , origin.y-2));
		pDC->LineTo(CPoint(origin.x-i , origin.y));
	}
	for(int i=0;i<=origin.y-5;i+=m_mark)
	{
		pDC->MoveTo(CPoint(origin.x+2 , origin.y-i));
		pDC->LineTo(CPoint(origin.x , origin.y-i));
		pDC->MoveTo(CPoint(origin.x+2 , origin.y+i));
		pDC->LineTo(CPoint(origin.x , origin.y+i));
	}
	return TRUE;
}


void CCoolDrawView::DrawSin(double a,double b, CDC *pDC)
{
	double x = origin.x;
	double y = origin.y;

	pDC->MoveTo(origin.x, origin.y - b*m_mark);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)i/m_mark;
		x = origin.x + i;
		y = origin.y - (a * sin(tmp))*m_mark - b*m_mark ;
		pDC->LineTo(x, y);
		pDC->MoveTo(x, y);
	}
	pDC->MoveTo(origin.x, origin.y - b*m_mark);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)-i/m_mark;
		x = origin.x - i;
		y = origin.y - (a * sin(tmp))*m_mark - b*m_mark ;
		pDC->LineTo(x, y);
		pDC->MoveTo(x, y);
	}
}


void CCoolDrawView::DrawCos(double a,double b ,CDC *pDC)
{
	double x = origin.x;
	double y = origin.y;

	pDC->MoveTo(origin.x, origin.y - b*m_mark - a*m_mark);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)i/m_mark;
		x = origin.x + i;
		y = origin.y - (a * cos(tmp))*m_mark - b*m_mark ;
		pDC->LineTo(x, y);
		pDC->MoveTo(x, y);
	}
	pDC->MoveTo(origin.x, origin.y - b*m_mark - a*m_mark);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)-i/m_mark;
		x = origin.x - i;
		y = origin.y - (a * cos(tmp))*m_mark - b*m_mark ;
		pDC->LineTo(x, y);
		pDC->MoveTo(x, y);
	}
}


void CCoolDrawView::DrawLine(double a,double b,double c ,CDC *pDC)
{
	double x = origin.x;
	double y = origin.y;

	pDC->MoveTo(origin.x, origin.y - c*m_mark);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)i/m_mark;
		x = origin.x + i;
		y =  origin.y - ((a * tmp * tmp)*m_mark + b*i + c*m_mark);
		pDC->LineTo(x, y);
		pDC->MoveTo(x, y);
	}
	pDC->MoveTo(origin.x, origin.y - c*m_mark);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)-i/m_mark;
		x = origin.x - i;
		y =  origin.y - ((a * tmp * tmp)*m_mark - b*i + c*m_mark);
		pDC->LineTo(x, y);
		pDC->MoveTo(x, y);
	}
}

void CCoolDrawView::DrawExpCurve(char str[],CDC *pDC)
{
	double x = origin.x;
	double y = origin.y;

	Calculat ca;
	bool flag = TRUE, ff2 = true;
	double ty = ca.solve(str, 0, flag)*m_mark;
	if(flag == TRUE)
		pDC->MoveTo(origin.x, origin.y - ty);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)i/m_mark;
		x = origin.x + i;
		ty = ca.solve(str, tmp, flag)*m_mark;
		if(flag)
		{	
			y = origin.y -  ty;
			if(ff2 )
				pDC->LineTo(x, y);
			ff2 = true;
			pDC->MoveTo(x, y);
		}
		else
		{
			pDC->TextOutA(5,5,"ERROR");
			ff2 = false;
		}
	}
	ty = ca.solve(str, 0, flag)*m_mark;
	if(flag == TRUE)
		pDC->MoveTo(origin.x, origin.y - ty);
	for(int i=0;i<=origin.x-5;i+=1)
	{
		double tmp = (double)-i/m_mark;
		x = origin.x - i;
		ty = ca.solve(str, tmp, flag)*m_mark;
		if(flag)
		{
			y = origin.y - ty;
			if(ff2)
				pDC->LineTo(x, y);
			ff2 = true;
			pDC->MoveTo(x, y);
		}
		else
		{
			pDC->TextOutA(5,5,"ERROR");
			ff2 = false;
		}
	}
}

void CCoolDrawView::DeleteOne(void)
{
	int upper = m_array.GetUpperBound();
	if(upper < 0 ) return ;
	CCurve *curve = (CCurve*)(m_array.GetAt(upper));
	delete curve;
	m_array.RemoveAt(upper);
	Invalidate();
}


void CCoolDrawView::DeleteAll(void)
{
	int cot = m_array.GetSize();
	for(int i=0;i<cot;i++)
		delete m_array.GetAt(i);
	m_array.RemoveAll();
	Invalidate();
}


