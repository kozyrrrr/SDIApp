
// SDIApp.h : ������� ���� ��������� ��� ���������� SDIApp
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSDIAppApp:
// � ���������� ������� ������ ��. SDIApp.cpp
//

class CSDIAppApp : public CWinApp
{
public:
	CSDIAppApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIAppApp theApp;
