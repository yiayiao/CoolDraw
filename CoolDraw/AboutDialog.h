#pragma once


// CAboutDialog �Ի���

class CAboutDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutDialog)

public:
	CAboutDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAboutDialog();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedGuide();
};
