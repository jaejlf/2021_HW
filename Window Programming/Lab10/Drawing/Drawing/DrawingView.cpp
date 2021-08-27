
// DrawingView.cpp: CDrawingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "CSizeDlg.h"

// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CView)

BEGIN_MESSAGE_MAP(CDrawingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ON_OPTION_SIZE, &CDrawingView::OnOptionSize)
END_MESSAGE_MAP()

// CDrawingView 생성/소멸

CDrawingView::CDrawingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	w = 5;

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDrawingView 그리기

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->Size(); i++) {
		CPoint p = pDoc->GetPoint(i);
		pDC->Rectangle(p.x, p.y, p.x + w, p.y + w);
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDrawingView 인쇄

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CDrawingView 진단

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 메시지 처리기


void CDrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags == MK_LBUTTON) {
		CClientDC dc(this);
		dc.Rectangle(point.x, point.y, point.x + w, point.y + w);
		pDoc->Add(point);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(this, 0, 0);
	}
	CView::OnMouseMove(nFlags, point);
}


void CDrawingView::OnOptionSize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSizeDlg dlg;
	dlg.m_nSize = w;
	if(dlg.DoModal() == IDOK)
		w = dlg.m_nSize;
}


void CDrawingView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->Size();
	if (n > 0) {
		CPoint p = pDoc->GetPoint(n - 1);
		CClientDC dc(this);
		dc.Rectangle(p.x, p.y, p.x + w, p.y + w);
	}
}
