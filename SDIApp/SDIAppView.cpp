
// SDIAppView.cpp : реализация класса CSDIAppView
//

#include "stdafx.h"
#include "CTime"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// создание/уничтожение CSDIAppView

CSDIAppView::CSDIAppView()
{
	// TODO: добавьте код создания


}

CSDIAppView::~CSDIAppView()
{
}

BOOL CSDIAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CSDIAppView

void CSDIAppView::OnDraw(CDC* pDC)
{
	CSDIAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	time(NULL);
	if (nIDEvent == 1)
	{
		if (m_rcCircle.IsRectNull())
		{
			CRect rc;
			GetClientRect(&rc);

			m_rcCircle.left = rc.Width() / 2 - 25;
			m_rcCircle.bottom = rc.Height() / 2 - 25;
			m_rcCircle.top = rc.Height() / 2 + 25;
			m_rcCircle.right = rc.Width() / 2 + 25;
		}
		m_rcCircle.top += 20;
		m_rcCircle.bottom += 20;
		m_rcCircle.right += 20;
		m_rcCircle.left += 20;
	}
	Invalidate(TRUE);
	CRect rect;
	GetClientRect(&rect);



	int mx, my;
	mx = rect.Width() / 2;
	my = rect.Height() / 2;

	pDC->Ellipse(m_rcCircle);
	//CRect rect;
	//GetClientRect(&rect);
	//if (nIDEvent == 1)
	//{
	//	if (m_rcCircle.IsRectNull()) {
	//		// TODO : посчитать начальное положение центра и задать перемещение через setTimer для x и y
	//		double cx, cy;
	//		cx = rand() % (rect.Width());
	//		cy = rand() % (rect.Height());

	//		int radius = 50;

	//		/*pDC->SelectObject(&pen);
	//		pDC->MoveTo(cx,cy);*/

	//		float x, y;
	//		float pi = 3.14;
	//		pDC->Ellipse(cx + radius, cy + radius, cx - radius, cy - radius);
	//		// сделать проверку клика внутри и извнутри для круга и по щелчку внутри останавливать рисовку
	//		// завести bool переменную по которой определять работу рисовки
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
	//// TODO: добавьте здесь код отрисовки для собственных данных
	//float x, y;
	//for (int i=0;i<rect.Width();i++)
	//{
	//	 x = (float)i*mx;
	//	 y = sin(x)/my;
	//	 pDC->LineTo(i, rect.Height() / 2 - y);
	//}
}


// печать CSDIAppView

BOOL CSDIAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSDIAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSDIAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CSDIAppView

#ifdef _DEBUG
void CSDIAppView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIAppDoc* CSDIAppView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIAppDoc)));
	return (CSDIAppDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CSDIAppView


void CSDIAppView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	

	CView::OnTimer(nIDEvent);

}
