#pragma once


// CGuide3 �Ի���

class CGuide3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CGuide3)

public:
	CGuide3();
	virtual ~CGuide3();

// �Ի�������
	enum { IDD = IDD_GUIDE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
