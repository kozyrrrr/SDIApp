
// SDIAppDoc.cpp : ���������� ������ CSDIAppDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "SDIApp.h"
#endif

#include "SDIAppDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSDIAppDoc

IMPLEMENT_DYNCREATE(CSDIAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDIAppDoc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� CSDIAppDoc

CSDIAppDoc::CSDIAppDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������
	m_bRed = true;

}

CSDIAppDoc::~CSDIAppDoc()
{
}

BOOL CSDIAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)
	/*for (int i=0; i < 1000; i++)
	{
		pt point;
		point.x = i;
		point.y = i*sin(i) / log(i);
		m_Points.push_back(point);
	}*/

	m_pTree->UpdateTree();


	return TRUE;
}




// ������������ CSDIAppDoc

void CSDIAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
		size_t count = m_Points.size();
		ar << count;

		for (size_t i = 0; i < count; i++)
		{
			ar << m_Points[i].x;
			ar << m_Points[i].y;
		}
	}
	else
	{
		// TODO: �������� ��� ��������
		size_t count;
		ar >> count;

		m_Points.clear();
		for (size_t i = 0; i < count; i++)
		{
			pt point;
			ar >> point.x;
			ar >> point.y;
			m_Points.push_back(point);
		}
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CSDIAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CSDIAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CSDIAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CSDIAppDoc

#ifdef _DEBUG
void CSDIAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDIAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CSDIAppDoc
