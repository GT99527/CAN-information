
// canbustestDlg.cpp : ʵ���ļ�
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

// CcanbustestDlg �Ի���

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
		str.Format(_T("ͨ�� %d"),i);
		m_combox1.AddString(str);
	}
	m_combox1.SetCurSel(0);
	printf("hotplugs:devs = %d",devs);
}

// CcanbustestDlg ��Ϣ�������
BOOL CcanbustestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcanbustestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcanbustestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcanbustestDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcanbustestDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	cancfg.configs |= 0x0001;  //��ͨ�ڲ�ƥ�����
	cancfg.configs |= 0x0002;  //�������߻���ģʽ
	cancfg.configs |= 0x0004;  //�����Զ��ش�
	cancfg.baudrate = tmp;
	rtn = CAN_Init(devnum,&cancfg);
	tm2 = cancfg.baudrate / 1000.0;
	printf("real baudrate is = %.2f\r\n", tm2);
	return  rtn;
}

void CcanbustestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!canopened) return;
	canopened = FALSE;
	Sleep(100);
	CAN_CloseDevice(devnum);
}


void CcanbustestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
				tmpstr.Format(_T("ʱ��: %010d "), rmgs[i].TimeStamp);
				str = tmpstr;
				tmpstr.Format(_T("  ID: %08x "), rmgs[i].ID);
				str += tmpstr;
				str += "   ֡����: ";
				if (rmgs[i].ExternFlag == 0) { tmpstr = "��׼֡ "; }
				else { tmpstr = "��չ֡ "; }
				str += tmpstr;
				str += "   ֡��ʽ: ";
				if (rmgs[i].RemoteFlag == 0) { tmpstr = "����֡ "; }
				else { tmpstr = "Զ��֡ "; }
				str += tmpstr;
				str += "   ֡����: ";
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
