#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMapRadio �Ի���

class CMapRadio : public CDialogEx
{
	DECLARE_DYNAMIC(CMapRadio)

public:
	CMapRadio(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMapRadio();

// �Ի�������
	enum { IDD = IDD_DIALOG_RADIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_radio;
	CEdit m_editRadio;
	CSliderCtrl m_sliderRadio;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKillfocusEditRadio();
};
