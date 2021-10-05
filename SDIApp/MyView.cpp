// MyView.cpp: файл реализации
//

#include "stdafx.h"
#include "SDIApp.h"
#include "MyView.h"
#include "SDIAppDoc.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CTreeView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// диагностика CMyView

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// обработчики сообщений CMyView

void CMyView::UpdateTree()
{
	CTreeCtrl &tree = GetTreeCtrl();

	tree.DeleteAllItems();

	m_hRoot = tree.InsertItem(L"Root", -1, -1, NULL, TVI_FIRST);

	m_hItem1 = tree.InsertItem(L"Item1", -1, -1, m_hRoot, TVI_LAST);
	m_hItem2 = tree.InsertItem(L"Item2", -1, -1, m_hRoot, TVI_LAST);

	tree.Expand(m_hRoot, TVE_EXPAND);

	tree.SetItemData(m_hItem1, 1);
	tree.SetItemData(m_hItem2, 0);


	int n = tree.GetItemData(m_hItem1);



}


int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания


	return 0;
}


void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeCtrl &tree = GetTreeCtrl();

	HTREEITEM sel = tree.GetSelectedItem();

	

	pDoc->m_bRed = tree.GetItemData(sel);

	pDoc->m_pView->Invalidate(FALSE);

	CTreeView::OnLButtonDown(nFlags, point);
}
