#pragma once


// CGuide2 �Ի���

class CGuide2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CGuide2)

public:
	CGuide2();
	virtual ~CGuide2();

// �Ի�������
	enum { IDD = IDD_GUIDE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
