
// CoolDrawView.h : CCoolDrawView ��Ľӿ�
//

#pragma once

#include "CoolDrawDoc.h"


class CCoolDrawView : public CView
{
protected: // �������л�����
	CCoolDrawView();
	DECLARE_DYNCREATE(CCoolDrawView)

// ����
public:
	int m_weight;
	COLORREF m_color;
	COLORREF m_bkColor;
	CPtrArray m_array;
	int m_mark;		//������Ŀ̶Ⱦ���
	CCoolDrawDoc* GetDocument() const;
	CPoint origin;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CCoolDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool DrawCurve(char str[]);		//
	bool DrawSysCurve(void);//
	bool DrawCoordinate(void);	//����������
	void DrawSin(double a,double b,CDC *pDC);
	void DrawCos(double a,double b,CDC *pDC);
	void DrawLine(double a,double b,double c,CDC *pDC);
//	afx_msg void OnEditUndo();
//	afx_msg void OnEditUndoall();
	void DeleteOne(void);
	void DeleteAll(void);
	void DrawExpCurve(char str[],CDC *pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // CoolDrawView.cpp �еĵ��԰汾
inline CCoolDrawDoc* CCoolDrawView::GetDocument() const
   { return reinterpret_cast<CCoolDrawDoc*>(m_pDocument); }
#endif

