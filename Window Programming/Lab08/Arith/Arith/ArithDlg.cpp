
// ArithDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Arith.h"
#include "ArithDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CArithDlg 대화 상자



CArithDlg::CArithDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ARITH_DIALOG, pParent)
	, m_nRadio(0)
	, m_strName(_T(""))
	, m_nNum1(0)
	, m_nNum2(0)
	, m_nLimit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CArithDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_ADD_RADIO, m_nRadio);
	DDX_Text(pDX, IDC_ANSWER_EDIT, m_nAnswer);
	DDV_MinMaxInt(pDX, m_nAnswer, 1, 9999);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDV_MaxChars(pDX, m_strName, 10);
	DDX_Text(pDX, IDC_NUM1_EDIT, m_nNum1);
	DDX_Text(pDX, IDC_NUM2_EDIT, m_nNum2);
	
}

BEGIN_MESSAGE_MAP(CArithDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_EXEC_RENEW, &CArithDlg::OnExecRenew)
	ON_COMMAND(ID_EXEC_CHANGELEVEL, &CArithDlg::OnExecChangelevel)
	ON_COMMAND(ID_EXEC_CHECK, &CArithDlg::OnExecCheck)
	ON_COMMAND(ID_EXIT_QUIT, &CArithDlg::OnExitQuit)
	ON_COMMAND(ID_EXIT_SAVEANDQUIT, &CArithDlg::OnExitSaveandquit)
END_MESSAGE_MAP()


// CArithDlg 메시지 처리기

BOOL CArithDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_nLimit = 9;
	m_nRadio = 0;
	srand((int)time(NULL));
	m_nNum1 = 1 + rand() % m_nLimit;
	m_nNum2 = 1 + rand() % m_nLimit;
	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CArithDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CArithDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CArithDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CArithDlg::OnExecRenew()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nNum1 = 1 + rand() % m_nLimit;
	m_nNum2 = 1 + rand() % m_nLimit;
	UpdateData(FALSE);
}


void CArithDlg::OnExecCheck()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int correct_answer;

	UpdateData();
	if (m_nRadio == 0)
		correct_answer = m_nNum1 + m_nNum2;
	else
		correct_answer = m_nNum1 * m_nNum2;

	if (m_nAnswer == correct_answer)
		MessageBox(_T("Correct. Congratulations, ") + m_strName);
	else
		MessageBox(_T("Wrong. Try again ") + m_strName);
}


void CArithDlg::OnExecChangelevel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nLimit = (9 + 99) - m_nLimit;
}


void CArithDlg::OnExitQuit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}


void CArithDlg::OnExitSaveandquit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}
