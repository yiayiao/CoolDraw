#pragma once


// CGuide3 对话框

class CGuide3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CGuide3)

public:
	CGuide3();
	virtual ~CGuide3();

// 对话框数据
	enum { IDD = IDD_GUIDE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
