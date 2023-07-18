
// canbustestDlg.h : 头文件
//

#pragma once
#include "ucanbus.h"

// CcanbustestDlg 对话框
class CcanbustestDlg : public CDialogEx
{
// 构造
public:
	CcanbustestDlg(CWnd* pParent = NULL);	// 标准构造函数
	static UINT receive_thread(void *param);
	int str2u8(char* data, CString str);
	void hotplugs(void);
	Can_Msg  tmsg[100];
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CANBUSTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CComboBox	m_combox1;
	CComboBox	m_combox2;
	CComboBox	m_combox3;
	CComboBox	m_combox4;
	CComboBox	m_combox5;
	CString	    m_Edit1;
	CString	    m_Edit2;
	CListBox	m_List;
	int baudrate;
	BOOL canopened;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg int winitcan(void);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
