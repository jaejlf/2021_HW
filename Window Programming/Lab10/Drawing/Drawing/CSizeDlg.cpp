// CSizeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Drawing.h"
#include "CSizeDlg.h"
#include "afxdialogex.h"


// CSizeDlg 대화 상자

IMPLEMENT_DYNAMIC(CSizeDlg, CDialogEx)

CSizeDlg::CSizeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_nSize(0)
{

}

CSizeDlg::~CSizeDlg()
{
}

void CSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nSize);
	DDV_MinMaxInt(pDX, m_nSize, 2, 50);
}


BEGIN_MESSAGE_MAP(CSizeDlg, CDialogEx)
END_MESSAGE_MAP()


// CSizeDlg 메시지 처리기
