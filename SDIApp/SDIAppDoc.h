
// SDIAppDoc.h : ��������� ������ CSDIAppDoc
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
protected: // ������� ������ �� ������������
	CSDIAppDoc();
	DECLARE_DYNCREATE(CSDIAppDoc)

// ��������
public:
	bool m_bRed;
	vector <pt> m_Points;

	CMyView *m_pTree;
	CSDIAppView *m_pView;

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CSDIAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
