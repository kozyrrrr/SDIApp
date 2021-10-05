#pragma once
//#include "SDIAppDoc.h"


// представление CMyView
class CSDIAppDoc;
class CMyView : public CTreeView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyView();

public:
	HTREEITEM m_hRoot, m_hItem1, m_hItem2;

	CSDIAppDoc * pDoc;

	void UpdateTree();

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


