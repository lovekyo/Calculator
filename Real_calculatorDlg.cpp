// Real_calculatorDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Real_calculator.h"
#include "Real_calculatorDlg.h"
#include "Expression.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReal_calculatorDlg dialog

CReal_calculatorDlg::CReal_calculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReal_calculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReal_calculatorDlg)
	m_num = _T("");
	m_out = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReal_calculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReal_calculatorDlg)
	DDX_Control(pDX, IDC_OUTEDIT, m_OutFont);
	DDX_Control(pDX, IDC_DISPLAYEDIT, m_Font);
	DDX_Text(pDX, IDC_DISPLAYEDIT, m_num);
	DDX_Text(pDX, IDC_OUTEDIT, m_out);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReal_calculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CReal_calculatorDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Num1, OnNum1)
	ON_BN_CLICKED(IDC_Num2, OnNum2)
	ON_BN_CLICKED(IDC_Num3, OnNum3)
	ON_BN_CLICKED(IDC_Num4, OnNum4)
	ON_BN_CLICKED(IDC_Num5, OnNum5)
	ON_BN_CLICKED(IDC_Num6, OnNum6)
	ON_BN_CLICKED(IDC_Num7, OnNum7)
	ON_BN_CLICKED(IDC_Num8, OnNum8)
	ON_BN_CLICKED(IDC_Num9, OnNum9)
	ON_BN_CLICKED(IDC_Num0, OnNum0)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SUB, OnSub)
	ON_BN_CLICKED(IDC_MUL, OnMul)
	ON_BN_CLICKED(IDC_DIV, OnDiv)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	ON_BN_CLICKED(IDC_FLOAT, OnFloat)
	ON_BN_CLICKED(IDC_END, OnEnd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_DELALL, OnDelall)
	ON_BN_CLICKED(IDC_CHANEL, OnChanel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReal_calculatorDlg message handlers

BOOL CReal_calculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	my_Font.CreatePointFont(320, "宋体");
	m_Font.SetFont(&my_Font);
	
	m_OutFont.SetFont(&my_Font);


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReal_calculatorDlg::OnPaint() 
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
HCURSOR CReal_calculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReal_calculatorDlg::OnNum1() 
{
	UpdateData(TRUE);
	m_num += "1";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum2() 
{
	UpdateData(TRUE);
	m_num += "2";
	UpdateData(FALSE);	
}

void CReal_calculatorDlg::OnNum3() 
{
	UpdateData(TRUE);
	m_num += "3";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum4() 
{
	UpdateData(TRUE);
	m_num += "4";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum5() 
{
	UpdateData(TRUE);
	m_num += "5";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum6() 
{
	UpdateData(TRUE);
	m_num += "6";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum7() 
{
	UpdateData(TRUE);
	m_num += "7";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum8() 
{
	UpdateData(TRUE);
	m_num += "8";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum9() 
{
	UpdateData(TRUE);
	m_num += "9";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnNum0() 
{
	UpdateData(TRUE);
	m_num += "0";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnAdd() 
{
	UpdateData(TRUE);
	m_num += "+";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnSub() 
{
	UpdateData(TRUE);
	m_num += "-";
	UpdateData(FALSE);
	
}

void CReal_calculatorDlg::OnMul() 
{
	UpdateData(TRUE);
	m_num += "*";
	UpdateData(FALSE);
	
}

void CReal_calculatorDlg::OnDiv() 
{
	UpdateData(TRUE);
	m_num += "/";
	UpdateData(FALSE);
	
}
	

void CReal_calculatorDlg::OnLeft() 
{
	UpdateData(TRUE);
	m_num += "(";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnRight() 
{
	UpdateData(TRUE);
	m_num += ")";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnFloat() 
{
	UpdateData(TRUE);
	m_num += ".";
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnEnd() 
{
	UpdateData(TRUE);
	std::string exp_str;
	exp_str = m_num.GetBuffer(0);

	if (exp_str != "")
    {
        Expression e(exp_str);  
        if(e.test())  
        {  
            string tmp;  
            stringstream ss;  
            ss << e.calculate();  
            ss >> tmp;  
            m_out = tmp.c_str();  
        }  
        else  
        {  
            m_out = "输入错误";  
        }
		UpdateData(FALSE);
	}
}

void CReal_calculatorDlg::OnDelete() 
{
	UpdateData(TRUE);
	m_num = m_num.Left(m_num.GetLength() - 1);
	UpdateData(FALSE);
}

void CReal_calculatorDlg::OnDelall() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_num = "";
	m_out = 0.0;
	UpdateData(FALSE);
}



void CReal_calculatorDlg::OnChanel() 
{
	if( MessageBox( "确认退出", "", MB_YESNO | MB_ICONQUESTION ) == IDYES  ){
		this->SendMessage( WM_CLOSE );
	}	
}
