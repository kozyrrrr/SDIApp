
// SDIAppView.h : ��������� ������ CSDIAppView
//

#pragma once

class CSDIAppDoc;

class CSDIAppView : public CView
{
protected: // ������� ������ �� ������������
	CSDIAppView();
	DECLARE_DYNCREATE(CSDIAppView)

// ��������
public:
	CSDIAppDoc* GetDocument() const;
	CRect m_rcCircle;
	int t = 1, l = 1, r = 1, b = 1;
	bool isCircMove = 1;
// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CSDIAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ���������� ������ � SDIAppView.cpp
inline CSDIAppDoc* CSDIAppView::GetDocument() const
   { return reinterpret_cast<CSDIAppDoc*>(m_pDocument); }
#endif

