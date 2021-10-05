
// SDIAppView.cpp : ���������� ������ CSDIAppView
//

#include "stdafx.h"
#include "CTime"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "SDIApp.h"
#endif

#include "SDIAppDoc.h"
#include "SDIAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIAppView

IMPLEMENT_DYNCREATE(CSDIAppView, CView)

BEGIN_MESSAGE_MAP(CSDIAppView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� CSDIAppView

CSDIAppView::CSDIAppView()
{
	// TODO: �������� ��� ��������

	srand(time(NULL));
	l = r = 2 + rand() % 5;
	t = b = 2 + rand() % 5;

}

CSDIAppView::~CSDIAppView()
{
}

BOOL CSDIAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CSDIAppView

void CSDIAppView::OnDraw(CDC* pDC)
{
	CSDIAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pDC->Ellipse(m_rcCircle);

	//CRect rect;
	//GetClientRect(&rect);
	//if (nIDEvent == 1)
	//{
	//	if (m_rcCircle.IsRectNull()) {
	//		// TODO : ��������� ��������� ��������� ������ � ������ ����������� ����� setTimer ��� x � y
	//		double cx, cy;
	//		cx = rand() % (rect.Width());
	//		cy = rand() % (rect.Height());

	//		int radius = 50;

	//		/*pDC->SelectObject(&pen);
	//		pDC->MoveTo(cx,cy);*/

	//		float x, y;
	//		float pi = 3.14;
	//		pDC->Ellipse(cx + radius, cy + radius, cx - radius, cy - radius);
	//		// ������� �������� ����� ������ � �������� ��� ����� � �� ������ ������ ������������� �������
	//		// ������� bool ���������� �� ������� ���������� ������ �������
	//		pDC->Ellipse(m_rcCircle);
	//		SetTimer(1, 10, NULL);
	//		Invalidate(TRUE);

	//	}
	//}
	//


	//double mx, my;

	//mx = 2 * 3.14 / rect.Width();
	//my = 2.f / rect.Height();



	//CPen pen;
	//if(pDoc->m_bRed)
	//	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	//else
	//	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	//
	//pDC->SelectObject(&pen);
	//
	//pDC->MoveTo(0, rect.Height() / 2);
	//// TODO: �������� ����� ��� ��������� ��� ����������� ������
	//float x, y;
	//for (int i=0;i<rect.Width();i++)
	//{
	//	 x = (float)i*mx;
	//	 y = sin(x)/my;
	//	 pDC->LineTo(i, rect.Height() / 2 - y);
	//}
}


// ������ CSDIAppView

BOOL CSDIAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CSDIAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CSDIAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CSDIAppView

#ifdef _DEBUG
void CSDIAppView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIAppDoc* CSDIAppView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIAppDoc)));
	return (CSDIAppDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CSDIAppView


void CSDIAppView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	int radius = 25;
	int step = 40;
	if (nIDEvent == 1)
	{
		CRect rc;
		GetClientRect(&rc);

		if (m_rcCircle.IsRectNull())
		{
			// �����
			m_rcCircle.left = rc.Width() / 2 - radius;
			m_rcCircle.bottom = rc.Height() / 2 - radius;
			m_rcCircle.top = rc.Height() / 2 + radius;
			m_rcCircle.right = rc.Width() / 2 + radius;
		}

		if (m_rcCircle.bottom > rc.Height() - radius * 2)
		{
			b *= -1;
			t *= -1;
		}
		if (m_rcCircle.right > rc.Width())
		{
			l *= -1;
			r *= -1;
		}
		if (m_rcCircle.top <= radius * 2)
		{
			b *= -1;
			t *= -1;
		}
		if (m_rcCircle.left <= 0)
		{
			l *= -1;
			r *= -1;
		}

		m_rcCircle.bottom += b;
		m_rcCircle.top += t;
		m_rcCircle.right += r;
		m_rcCircle.left += l;

	}
	Invalidate(TRUE);
	CRect rect;
	GetClientRect(&rect);



	int mx, my;
	mx = rect.Width() / 2;
	my = rect.Height() / 2;

	CView::OnTimer(nIDEvent);

}


void CSDIAppView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	// ������� �������� ����� ������ � �������� ��� ����� � �� ������ ������ ������������� �������
	// ������� bool ���������� �� ������� ���������� ������ �������
	if (point.x >= m_rcCircle.left && point.x <= m_rcCircle.right && point.y <= m_rcCircle.top && point.y >= m_rcCircle.bottom)
	{
		if (isCircMove) KillTimer(1);
		else SetTimer(1, 50, NULL);

		isCircMove = !isCircMove;


		CView::OnLButtonUp(nFlags, point);
	}
}
