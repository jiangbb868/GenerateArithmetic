// GenerateArithmeticDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GenerateArithmetic.h"
#include "GenerateArithmeticDlg.h"
#include "def.h"
#include "ArithmeticFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{	
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGenerateArithmeticDlg dialog

CGenerateArithmeticDlg::CGenerateArithmeticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGenerateArithmeticDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGenerateArithmeticDlg)
	m_nCountEachUnit = 0;
	m_nMultiCountEachUnit = 0;
	m_nNumberMax = 0;
	m_nNumberMin = 0;
	m_nResultMax = 0;
	m_nResultMin = 0;
	m_nUnitCount = 0;
	m_nMDCountEachUnit = 0;
	m_nMDNumberMax = 0;
	m_nMDNumberMin = 0;
	m_nMDResultMax = 0;
	m_nMDResultMin = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenerateArithmeticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGenerateArithmeticDlg)
	DDX_Control(pDX, IDC_COMBO_MD_DEGREE, m_comboMDDegree);
	DDX_Control(pDX, IDC_COMBO_DEGREE, m_comboDegree);
	DDX_Text(pDX, IDC_EDIT_COUNT_EACH_UNIT, m_nCountEachUnit);
	DDV_MinMaxInt(pDX, m_nCountEachUnit, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_MULTI_COUNT_EACH_UNIT, m_nMultiCountEachUnit);
	DDV_MinMaxInt(pDX, m_nMultiCountEachUnit, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_NUMBER_MAX, m_nNumberMax);
	DDV_MinMaxInt(pDX, m_nNumberMax, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_NUMBER_MIN, m_nNumberMin);
	DDV_MinMaxInt(pDX, m_nNumberMin, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_RESULT_MAX, m_nResultMax);
	DDV_MinMaxInt(pDX, m_nResultMax, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_RESULT_MIN, m_nResultMin);
	DDV_MinMaxInt(pDX, m_nResultMin, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_UNIT_COUNT, m_nUnitCount);
	DDV_MinMaxInt(pDX, m_nUnitCount, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_MD_COUNT_EACH_UNIT, m_nMDCountEachUnit);
	DDX_Text(pDX, IDC_EDIT_MD_NUMBER_MAX, m_nMDNumberMax);
	DDX_Text(pDX, IDC_EDIT_MD_NUMBER_MIN, m_nMDNumberMin);
	DDX_Text(pDX, IDC_EDIT_MD_RESULT_MAX, m_nMDResultMax);
	DDX_Text(pDX, IDC_EDIT_MD_RESULT_MIN, m_nMDResultMin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGenerateArithmeticDlg, CDialog)
	//{{AFX_MSG_MAP(CGenerateArithmeticDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGenerateArithmeticDlg message handlers

BOOL CGenerateArithmeticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_comboDegree.InsertString(0, "1");
	m_comboDegree.InsertString(1, "2");
	m_comboDegree.InsertString(2, "3");
	m_comboDegree.InsertString(3, "4");	
	m_comboDegree.InsertString(4, "5");

	m_comboMDDegree.InsertString(0, "1");
	m_comboMDDegree.InsertString(1, "2");
	m_comboMDDegree.InsertString(2, "3");
	m_comboMDDegree.InsertString(3, "4");	
	m_comboMDDegree.InsertString(4, "5");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGenerateArithmeticDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGenerateArithmeticDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGenerateArithmeticDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGenerateArithmeticDlg::OnOK() 
{
	// TODO: Add extra validation here
	THEME_PROPERTY property;
	CString str;
	GetDlgItemText(IDC_EDIT_COUNT_EACH_UNIT, str);
	property.nCountEachUnit = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_MULTI_COUNT_EACH_UNIT, str);
	property.nMultiCountEachUnit = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_NUMBER_MAX, str);
	property.nNumberMax = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_NUMBER_MIN, str);
	property.nNumberMin = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_RESULT_MAX, str);
	property.nResultMax = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_RESULT_MIN, str);
	property.nResultMin = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_UNIT_COUNT, str);
	property.nUnitCount = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_COMBO_DEGREE, str);
	property.nDegree = atoi(str.GetBuffer(str.GetLength()));

	GetDlgItemText(IDC_EDIT_MD_COUNT_EACH_UNIT, str);
	property.nMDCountEachUnit = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_MD_NUMBER_MAX, str);
	property.nMDNumberMax = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_MD_NUMBER_MIN, str);
	property.nMDNumberMin = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_MD_RESULT_MAX, str);
	property.nMDResultMax = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_EDIT_MD_RESULT_MIN, str);
	property.nMDResultMin = atoi(str.GetBuffer(str.GetLength()));
	GetDlgItemText(IDC_COMBO_MD_DEGREE, str);
	property.nMDDegree = atoi(str.GetBuffer(str.GetLength()));

	ArithmeticFactory factory;
	factory.Init(&property);
	factory.Run();

	CDialog::OnOK();
}
