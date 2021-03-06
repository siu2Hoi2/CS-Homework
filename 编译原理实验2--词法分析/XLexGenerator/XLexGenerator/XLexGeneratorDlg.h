
// XLexGeneratorDlg.h: 头文件
//

#pragma once
// CXLexGeneratorDlg 对话框
class CXLexGeneratorDlg : public CDialogEx
{
// 构造
public:
	CXLexGeneratorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XLEXGENERATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	char *exp;
	char *post;
	char *edge;
	int edgeNumber;
	int **DStates;
	int **Dtran;
	int *AcceptStates;
	int DStatesNumber;
	int DtranNumber;
	int NFAStatesNumber;
	int DFAStatesNumber;
	int Precedence(char symbol);
	int CompArray(int *t1, int *t2);
	int MinimizeDFAStates(int **Dtran, int *AcceptStates, int DtranNumber, int edgeNumber);

public:

	afx_msg void OnBnClickedNfa();
	afx_msg void OnBnClickedDfa();
	afx_msg void OnBnClickedMinDfa();
	afx_msg void OnBnClickedPrograme();

	// 获取输入的正则表达式
	CEdit Regexp;
	// 输出数据
	CListCtrl ShowDate;
	//判断是否已经生成过了，避免重复生成相同的正则表达式
	bool hasNFA;
	bool hasDFA;
	bool hasMinDFA;
	bool hasPrograme;
	CString preRegexp;
	CString nowRegexp;
	void GetRegExp();
	void InsertCatNode();
	void RegExpToPost();
	void GetEdgeNumber();
	void ThompsonConstruction();
	void SubsetConstruction();
	void init();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedSave();
};
