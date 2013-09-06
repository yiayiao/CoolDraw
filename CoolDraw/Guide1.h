#pragma once


// CGuide1 对话框

class CGuide1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CGuide1)

public:
	CGuide1();
	virtual ~CGuide1();

// 对话框数据
	enum { IDD = IDD_GUIDE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
