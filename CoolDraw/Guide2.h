#pragma once


// CGuide2 对话框

class CGuide2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CGuide2)

public:
	CGuide2();
	virtual ~CGuide2();

// 对话框数据
	enum { IDD = IDD_GUIDE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
