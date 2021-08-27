// EdView.cpp: 구현 파일
//

#include "pch.h"
#include "Drawing.h"
#include "EdView.h"


// CEdView

IMPLEMENT_DYNCREATE(CEdView, CEditView)

CEdView::CEdView()
{

}

CEdView::~CEdView()
{
}

BEGIN_MESSAGE_MAP(CEdView, CEditView)
END_MESSAGE_MAP()


// CEdView 진단

#ifdef _DEBUG
void CEdView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CEdView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// CEdView 메시지 처리기
