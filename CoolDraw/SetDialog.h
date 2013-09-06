#pragma once
#include "afxwin.h"
#include "LeftForm.h"

// CSetDialog �Ի���

class CSetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDialog)

public:
	CSetDialog(CLeftForm* pParent = NULL);   // ��׼���캯��
	virtual ~CSetDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_lineWeight;
	CComboBox m_lineWeightList;
	COLORREF m_color;
	COLORREF m_bkColor;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboLineweight();
	afx_msg void OnClickedButtonColor();
	//CStatic m_showColor;	//û��ʵ���Լ���Ҫ��Ч������ʱɾ��
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClickedButtonBkc();
};
