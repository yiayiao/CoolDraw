// AboutDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CoolDraw.h"
#include "AboutDialog.h"
#include "afxdialogex.h"

#include "GuidSheet.h"


// CAboutDialog 对话框

IMPLEMENT_DYNAMIC(CAboutDialog, CDialogEx)

CAboutDialog::CAboutDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAboutDialog::IDD, pParent)
{

}

CAboutDialog::~CAboutDialog()
{
}

void CAboutDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDialog, CDialogEx)
	ON_BN_CLICKED(ID_GUIDE, &CAboutDialog::OnClickedGuide)
END_MESSAGE_MAP()


// CAboutDialog 消息处理程序


void CAboutDialog::OnClickedGuide()
{
	CGuidSheet sheet(_T(""));
	sheet.SetWizardMode();
	sheet.DoModal();
}
