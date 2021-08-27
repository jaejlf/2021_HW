#include <afxwin.h>
#define IDC_BUTTON0 100
#define IDC_BUTTON1 101
#define IDC_BUTTON2 102
#define IDC_BUTTON3 103
#define IDC_BUTTON4 104
#define IDC_BUTTON5 105
#define IDC_BUTTON6 106
#define IDC_BUTTON7 107
#define IDC_BUTTON8 108

enum { X, O };

class CTicTacToeApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

CTicTacToeApp TTTApp;

class CTTTWindow : public CFrameWnd {
	CButton* button[9];
	int status[9];
	int turn;
	void init();
public:
	CTTTWindow();
	afx_msg void HandleButton(int);
	afx_msg void HandleButton0();
	afx_msg void HandleButton1();
	afx_msg void HandleButton2();
	afx_msg void HandleButton3();
	afx_msg void HandleButton4();
	afx_msg void HandleButton5();
	afx_msg void HandleButton6();
	afx_msg void HandleButton7();
	afx_msg void HandleButton8();

	DECLARE_MESSAGE_MAP();
};

BOOL CTicTacToeApp::InitInstance()
{
	m_pMainWnd = new CTTTWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CTTTWindow, CFrameWnd)
	ON_BN_CLICKED(IDC_BUTTON0, HandleButton0)
	ON_BN_CLICKED(IDC_BUTTON1, HandleButton1)
	ON_BN_CLICKED(IDC_BUTTON2, HandleButton2)
	ON_BN_CLICKED(IDC_BUTTON3, HandleButton3)
	ON_BN_CLICKED(IDC_BUTTON4, HandleButton4)
	ON_BN_CLICKED(IDC_BUTTON5, HandleButton5)
	ON_BN_CLICKED(IDC_BUTTON6, HandleButton6)
	ON_BN_CLICKED(IDC_BUTTON7, HandleButton7)
	ON_BN_CLICKED(IDC_BUTTON8, HandleButton8)
END_MESSAGE_MAP()

void CTTTWindow::init()
{
	for (int i = 0; i < 9; i++) {
		status[i] = -1;
	}
	turn = 0;
}

CTTTWindow::CTTTWindow()
{
	int x = 6;
	int y = 6;
	int z = 34;
	int k = 34;

	Create(NULL, _T("Tic-Tac-Toe"), WS_OVERLAPPEDWINDOW, CRect(200, 200, 600, 600));

	init();

	for (int i = 0; i < 9; i++) {

		if (i % 3 == 0) {
			x = 6;
			z = 34;
		}
		else if (i % 3 == 1) {
			x = 36;
			z = 64;
		}
		else {
			x = 66;
			z = 94;
		}

		if (i < 3) {
			y = 6;
			k = 34;
		}
		else if (i >= 3 && i < 6) {
			y = 36;
			k = 64;
		}
		else {
			y = 66;
			k = 94;
		}


		button[i] = new CButton();
		button[i]->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(x,y,z,k), this, IDC_BUTTON0 + i);
		
	} 
	
}

void CTTTWindow::HandleButton(int bt_num) {
	
	
	if (status[bt_num] != -1) { //잘못 누름
		MessageBeep(-1);
	}

	else { 
		if (turn % 2 == 0) { //X's turn
			button[bt_num]->SetWindowText(_T("X"));
			status[bt_num] = X;
		}
		else { //O's turn
			button[bt_num]->SetWindowText(_T("O"));
			status[bt_num] = O;
		}

		turn++;
	}

}
void CTTTWindow::HandleButton0()
{
	HandleButton(0);
}
void CTTTWindow::HandleButton1()
{
	HandleButton(1);
}
void CTTTWindow::HandleButton2()
{
	HandleButton(2);
}
void CTTTWindow::HandleButton3()
{
	HandleButton(3);
}
void CTTTWindow::HandleButton4()
{
	HandleButton(4);
}
void CTTTWindow::HandleButton5()
{
	HandleButton(5);
}
void CTTTWindow::HandleButton6()
{
	HandleButton(6);
}
void CTTTWindow::HandleButton7()
{
	HandleButton(7);
}
void CTTTWindow::HandleButton8()
{
	HandleButton(8);
}