#pragma once


// CGuide1 �Ի���

class CGuide1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CGuide1)

public:
	CGuide1();
	virtual ~CGuide1();

// �Ի�������
	enum { IDD = IDD_GUIDE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
