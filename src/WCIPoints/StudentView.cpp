
// StudentView.cpp : implementation of the CStudentView class

#include "pch.h"
#include "framework.h"

#include "WCIPoints.h"

#include "WCIPointsDoc.h"
#include "StudentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CStudentView, CFormView)

BEGIN_MESSAGE_MAP(CStudentView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CStudentView construction/destruction

CStudentView::CStudentView() noexcept
	: CFormView(IDD_STUDENT)
{
	// TODO: add construction code here

}

CStudentView::~CStudentView()
{
}

void CStudentView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void CStudentView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// Default created with WS_EX_CLIENTEDGE for some reason
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0);

	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

void CStudentView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CStudentView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CStudentView diagnostics

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWCIPointsDoc* CStudentView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWCIPointsDoc)));
	return (CWCIPointsDoc*)m_pDocument;
}
#endif //_DEBUG

