// GenerateArithmetic.h : main header file for the GENERATEARITHMETIC application
//

#if !defined(AFX_GENERATEARITHMETIC_H__00299C1A_E2DC_4EBD_BEAD_D8168EC85D93__INCLUDED_)
#define AFX_GENERATEARITHMETIC_H__00299C1A_E2DC_4EBD_BEAD_D8168EC85D93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGenerateArithmeticApp:
// See GenerateArithmetic.cpp for the implementation of this class
//

class CGenerateArithmeticApp : public CWinApp
{
public:
	CGenerateArithmeticApp();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenerateArithmeticApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGenerateArithmeticApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERATEARITHMETIC_H__00299C1A_E2DC_4EBD_BEAD_D8168EC85D93__INCLUDED_)
