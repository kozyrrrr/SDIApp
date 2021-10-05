
// SDIApp.h : главный файл заголовка для приложения SDIApp
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSDIAppApp:
// О реализации данного класса см. SDIApp.cpp
//

class CSDIAppApp : public CWinApp
{
public:
	CSDIAppApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIAppApp theApp;
