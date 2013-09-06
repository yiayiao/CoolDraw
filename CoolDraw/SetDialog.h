#pragma once
#include "afxwin.h"
#include "LeftForm.h"

// CSetDialog 对话框

class CSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDialog)

public:
	CSetDialog(CLeftForm* pParent = NULL);   // 标准构造函数
	virtual ~CSetDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_lineWeight;
	CComboBox m_lineWeightList;
	COLORREF m_color;
	COLORREF m_bkColor;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboLineweight();
	afx_msg void OnClickedButtonColor();
	//CStatic m_showColor;	//没有实现自己想要的效果，暂时删除
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClickedButtonBkc();
};
