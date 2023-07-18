
// canbustestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "canbustest.h"
#include "canbustestDlg.h"
#include "afxdialogex.h"
#include "ucanbus.h"
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CcanbustestDlg 对话框

int devnum = 0;

CcanbustestDlg::CcanbustestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CANBUSTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CcanbustestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, combx1, m_combox1);
	DDX_Control(pDX, combx2, m_combox2);
	DDX_Control(pDX, combx3, m_combox3);
	DDX_Control(pDX, combx4, m_combox4);
	DDX_Control(pDX, combx5, m_combox5);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CcanbustestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CcanbustestDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDCANCEL, &CcanbustestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CcanbustestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CcanbustestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CcanbustestDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


void CcanbustestDlg::hotplugs(void)
{
	int i;
	CString str;
	int devs = CAN_ScanDevice();
	m_combox1.ResetContent();
	for (i = 0; i < devs; i++)
	{
		str.Format(_T("通道 %d"),i);
		m_combox1.AddString(str);
	}
	m_combox1.SetCurSel(0);
	printf("hotplugs:devs = %d",devs);
}

// CcanbustestDlg 消息处理程序
BOOL CcanbustestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	hotplugs();
	m_combox2.SetCurSel(0);
	m_combox3.SetCurSel(0);
	m_combox4.SetCurSel(0);
	m_combox5.SetCurSel(0);
	m_Edit1 = "111";
	m_Edit2 = "01 02 03 04 05 06 07 08";
	UpdateData(false);
	canopened = FALSE;
	AfxBeginThread(receive_thread, this);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcanbustestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcanbustestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcanbustestDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcanbustestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
int CcanbustestDlg::winitcan(void)
{
	int rtn;
	int tmp;
	double tm1, tm2;
	CString str;
	Can_Config cancfg;
	cancfg.model = m_combox3.GetCurSel();
	m_combox2.GetLBText(m_combox2.GetCurSel(),str);
	tm1 = _ttof(str);
	baudrate = tm1;
	tmp = tm1 * 1000;
	cancfg.configs = 0;
	cancfg.configs |= 0x0001;  //接通内部匹配电阻
	cancfg.configs |= 0x0002;  //开启离线唤醒模式
	cancfg.configs |= 0x0004;  //开启自动重传
	cancfg.baudrate = tmp;
	rtn = CAN_Init(devnum,&cancfg);
	tm2 = cancfg.baudrate / 1000.0;
	printf("real baudrate is = %.2f\r\n", tm2);
	return  rtn;
}

void CcanbustestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret;
	int devs = CAN_ScanDevice();
	printf("devs = %d\r\n", devs);
	if (devs <= 0) return;
	if (canopened) return;
	devnum = m_combox1.GetCurSel();
	ret = CAN_OpenDevice(devnum);
	if (ret != 0) { printf("CAN_OpenDevice fault:ret = %d\r\n", ret); return; }
	else          { printf("CAN_OpenDevice success:ret = %d\r\n", ret); }
	ret = winitcan();
	if (ret != 0) { printf("winitcan fault:ret = %d\r\n", ret); return;}
	else          { printf("winitcan success:ret = %d\r\n", ret); }
	canopened = TRUE;
}

void CcanbustestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!canopened) return;
	canopened = FALSE;
	Sleep(100);
	CAN_CloseDevice(devnum);
}


void CcanbustestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	char dt[100],i,lenth;
	if (!canopened) return;
	GetDlgItemText(IDC_EDIT2,m_Edit2);
	lenth = str2u8(dt, m_Edit2);
	for (i = 0; i < 8; i++)
	{
         printf(" %02x ", dt[i]);
	}
	
	memcpy(tmsg[0].Data, dt,8);
	tmsg[0].DataLen = lenth;
	tmsg[0].ExternFlag = m_combox4.GetCurSel();
	tmsg[0].RemoteFlag = m_combox5.GetCurSel();
	GetDlgItemText(IDC_EDIT1, m_Edit1);
	tmsg[0].ID = _tcstol(m_Edit1,NULL,16);
	printf("   %x\r\n",tmsg[0].ID);
	CAN_Transmit(devnum,tmsg, 1,100);
}

UINT CcanbustestDlg::receive_thread(void *param)
{
	CString str, tmpstr;
	int lenth = 0,i;
	Can_Msg  rmgs[500];
	CcanbustestDlg *dialog = (CcanbustestDlg*)param;
	CListBox *recbox = (CListBox *)dialog->GetDlgItem(IDC_LIST1);
	while (1)
	{
		Sleep(10);
		if (dialog->canopened)
		{
			lenth = CAN_Receive(devnum,rmgs,200,1000);
			if (lenth <= 0) { continue; }

			for (i = 0; i<lenth; i++)
			{
				tmpstr.Format(_T("时间: %010d "), rmgs[i].TimeStamp);
				str = tmpstr;
				tmpstr.Format(_T("  ID: %08x "), rmgs[i].ID);
				str += tmpstr;
				str += "   帧类型: ";
				if (rmgs[i].ExternFlag == 0) { tmpstr = "标准帧 "; }
				else { tmpstr = "扩展帧 "; }
				str += tmpstr;
				str += "   帧格式: ";
				if (rmgs[i].RemoteFlag == 0) { tmpstr = "数据帧 "; }
				else { tmpstr = "远程帧 "; }
				str += tmpstr;
				str += "   帧数据: ";
				if (rmgs[i].DataLen>8)
					rmgs[i].DataLen = 8;
				for (int j = 0; j<rmgs[i].DataLen; j++)
				{
					tmpstr.Format(_T("%02x "), rmgs[i].Data[j]);
					str += tmpstr;
				}
				recbox->InsertString(recbox->GetCount(), str);
				
			}
			recbox->SetCurSel(recbox->GetCount() - 1);
		}
	}
}

unsigned char findhex_formstr(int *idx, int len, CString str)
{
	char dain;
	while (*idx < len)
	{
		dain = str.GetAt(*idx);
		if ((dain >= '0') && (dain <= '9'))   return(dain - '0');
		else if ((dain >= 'a') && (dain <= 'f'))   return(dain + 10 - 'a');
		else if ((dain >= 'A') && (dain <= 'F'))   return(dain + 10 - 'F');
		else (*idx)++;
	}
	return 0xff;
}

int CcanbustestDlg::str2u8(char* data, CString str)
{
	int ret;
	int da, db;
	int i = 0;
	int lenth;
	CByteArray buf;
	ret = str.GetLength();
	
	while (i < ret)
	{
		da = findhex_formstr(&i, ret, str);
		if (da == 0xff) da = 0;
		i++;
		db = findhex_formstr(&i, ret, str);
		if (db == 0xff) buf.Add(da);
		else buf.Add((da << 4) | db);
		i++;
		if (buf.GetSize() >= 8) break;
	}
	lenth = buf.GetSize();
	memcpy(data, buf.GetData(), lenth);
	return lenth;
}
