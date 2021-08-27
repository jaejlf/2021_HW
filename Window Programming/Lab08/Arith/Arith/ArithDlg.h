
// ArithDlg.h: 헤더 파일
//

#pragma once


// CArithDlg 대화 상자
class CArithDlg : public CDialogEx
{
// 생성입니다.
public:
	CArithDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ARITH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nRadio;
	int m_nAnswer;
	CString m_strName;
	int m_nNum1;
	int m_nNum2;
	int m_nLimit;
	afx_msg void OnExecRenew();
	afx_msg void OnExecCheck();
	afx_msg void OnExecChangelevel();
	afx_msg void OnExitQuit();
	afx_msg void OnExitSaveandquit();
};
