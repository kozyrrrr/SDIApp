
// MainFrm.cpp : ���������� ������ CMainFrame
//

#include "stdafx.h"
#include "SDIApp.h"
#include "SDIAppView.h"
#include "MyView.h"
#include "SDIAppDoc.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ��������� ������ ���������
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// ��������/����������� CMainFrame

CMainFrame::CMainFrame()
{
	// TODO: �������� ��� ������������� �����
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1;      // �� ������� �������
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("�� ������� ������� ������ ���������\n");
		return -1;      // �� ������� �������
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ������� ��� ��� ������, ���� �� ����������� ���������� ������ ������������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return TRUE;
}

// ����������� CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// ����������� ��������� CMainFrame



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �������� ������������������ ��� ��� ����� �������� ������
	m_wndSplitter.CreateStatic(this, 1, 2);

	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(200, 50), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CSDIAppView), CSize(0, 0), pContext);

	m_wndSplitter.SetColumnInfo(0, 400, 10);

	SetActiveView((CView*)m_wndSplitter.GetPane(0,1));

	CSDIAppDoc *pDoc = (CSDIAppDoc *)GetActiveDocument();

	pDoc->m_pTree = (CMyView*)m_wndSplitter.GetPane(0, 0);

	pDoc->m_pTree->pDoc = pDoc;
	pDoc->m_pView = (CSDIAppView*)m_wndSplitter.GetPane(0, 1);

	pDoc->m_pView->SetTimer(1,10000,NULL);
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	return TRUE;
}
