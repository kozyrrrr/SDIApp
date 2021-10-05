
// SDIAppView.h : интерфейс класса CSDIAppView
//

#pragma once

class CSDIAppDoc;

class CSDIAppView : public CView
{
protected: // создать только из сериализации
	CSDIAppView();
	DECLARE_DYNCREATE(CSDIAppView)

// Атрибуты
public:
	CSDIAppDoc* GetDocument() const;
	CRect m_rcCircle;
// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSDIAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // отладочная версия в SDIAppView.cpp
inline CSDIAppDoc* CSDIAppView::GetDocument() const
   { return reinterpret_cast<CSDIAppDoc*>(m_pDocument); }
#endif

