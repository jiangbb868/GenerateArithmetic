// GenerateArithmeticDlg.h : header file
//

#if !defined(AFX_GENERATEARITHMETICDLG_H__1ED748D7_5C1F_4BDC_BD47_564E854CFCC4__INCLUDED_)
#define AFX_GENERATEARITHMETICDLG_H__1ED748D7_5C1F_4BDC_BD47_564E854CFCC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGenerateArithmeticDlg dialog

class CGenerateArithmeticDlg : public CDialog
{
// Construction
public:
	CGenerateArithmeticDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGenerateArithmeticDlg)
	enum { IDD = IDD_GENERATEARITHMETIC_DIALOG };
	CComboBox	m_comboMDDegree;
	CComboBox	m_comboDegree;
	int		m_nCountEachUnit;
	int		m_nMultiCountEachUnit;
	int		m_nNumberMax;
	int		m_nNumberMin;
	int		m_nResultMax;
	int		m_nResultMin;
	int		m_nUnitCount;
	int		m_nMDCountEachUnit;
	int		m_nMDNumberMax;
	int		m_nMDNumberMin;
	int		m_nMDResultMax;
	int		m_nMDResultMin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenerateArithmeticDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGenerateArithmeticDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERATEARITHMETICDLG_H__1ED748D7_5C1F_4BDC_BD47_564E854CFCC4__INCLUDED_)
