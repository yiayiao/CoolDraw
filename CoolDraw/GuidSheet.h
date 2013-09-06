#pragma once

#include "Guide1.h"
#include "Guide2.h"
#include "Guide3.h"

// CGuidSheet

class CGuidSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CGuidSheet)

public:
	CGuide1 guide1;
	CGuide2 guide2;
	CGuide3 guide3;

public:
	CGuidSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CGuidSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CGuidSheet();

protected:
	DECLARE_MESSAGE_MAP()
};


