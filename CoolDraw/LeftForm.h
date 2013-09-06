#pragma once
#include "afxwin.h"



// CLeftForm ������ͼ

class CLeftForm : public CFormView
{
	DECLARE_DYNCREATE(CLeftForm)

protected:
	CLeftForm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CLeftForm();

public:
	enum { IDD = IDD_LEFTFORM };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedDrawbutton();
	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
	virtual void OnInitialUpdate();
	afx_msg void OnClickedDrawbuttonsys();
	CComboBox cbBox;
	afx_msg void OnSelchangeCombo1();
	int SetEditFalse(void);
	int m_pos;		//ѡ�е�λ��
	int m_lineWeight;	//�����Ŀ��
	COLORREF m_lineColor;
	COLORREF m_bkColor;
	afx_msg void OnWideOne();
	afx_msg void OnWideThree();
	afx_msg void OnWideTwo();
	afx_msg void OnUpdateWideOne(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWideThree(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWideTwo(CCmdUI *pCmdUI);
	afx_msg void OnBnClickedButtonSet();
	CStatic m_lineWightStatic;
	CStatic m_lineColorStatic;
	CStatic m_lineBgStatic;
	afx_msg void OnBlack();
	afx_msg void OnRed();
	afx_msg void OnYellow();
	afx_msg void OnOrange();
	afx_msg void OnGreen();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnEditUndo();
	afx_msg void OnEditUndoall();
	void SetStaticMessage(void);
	int m_mark;
	afx_msg void OnMark();
	CEdit m_exp;
	afx_msg void OnAppAbout();
};


