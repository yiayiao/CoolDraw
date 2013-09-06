#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMapRadio 对话框

class CMapRadio : public CDialogEx
{
	DECLARE_DYNAMIC(CMapRadio)

public:
	CMapRadio(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMapRadio();

// 对话框数据
	enum { IDD = IDD_DIALOG_RADIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_radio;
	CEdit m_editRadio;
	CSliderCtrl m_sliderRadio;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKillfocusEditRadio();
};
