
// CoolDrawView.h : CCoolDrawView 类的接口
//

#pragma once

#include "CoolDrawDoc.h"


class CCoolDrawView : public CView
{
protected: // 仅从序列化创建
	CCoolDrawView();
	DECLARE_DYNCREATE(CCoolDrawView)

// 特性
public:
	int m_weight;
	COLORREF m_color;
	COLORREF m_bkColor;
	CPtrArray m_array;
	int m_mark;		//坐标轴的刻度距离
	CCoolDrawDoc* GetDocument() const;
	CPoint origin;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CCoolDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool DrawCurve(char str[]);		//
	bool DrawSysCurve(void);//
	bool DrawCoordinate(void);	//绘制坐标轴
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

#ifndef _DEBUG  // CoolDrawView.cpp 中的调试版本
inline CCoolDrawDoc* CCoolDrawView::GetDocument() const
   { return reinterpret_cast<CCoolDrawDoc*>(m_pDocument); }
#endif

