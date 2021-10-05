
// SDIAppDoc.h : интерфейс класса CSDIAppDoc
//
#include <vector>
#include "MyView.h"
#include "SDIAppView.h"

#pragma once

using namespace std;

struct pt
{
	int x, y;
};

class CSDIAppDoc : public CDocument
{
protected: // создать только из сериализации
	CSDIAppDoc();
	DECLARE_DYNCREATE(CSDIAppDoc)

// Атрибуты
public:
	bool m_bRed;
	vector <pt> m_Points;

	CMyView *m_pTree;
	CSDIAppView *m_pView;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSDIAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
