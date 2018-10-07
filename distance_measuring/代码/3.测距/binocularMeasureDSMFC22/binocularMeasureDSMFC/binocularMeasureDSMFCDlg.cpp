
// binocularMeasureDSMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "binocularMeasureDSMFC.h"
#include "binocularMeasureDSMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CbinocularMeasureDSMFCDlg �Ի���



CbinocularMeasureDSMFCDlg::CbinocularMeasureDSMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbinocularMeasureDSMFCDlg::IDD, pParent)
	, m_edit_showDistance(_T(""))
	, m_edit_LeftFolder(_T(""))
	, m_edit_RightFolder(_T(""))
	, m_edit_ParmFileName(_T(""))
	, m_edit_NumOfImg(0)
	, m_nBoardSize_X(0)
	, m_nBoardSize_Y(0)
	, m_nSquareSize(0)
	, m_nDelayTime(0)
	, m_nMinDisp(0)
	, m_nPreFiltCap(0)
	, m_nNumDisp(0)
	, m_nSADWinSiz(0)
	, m_nTextThres(0)
	, m_nDisp12MaxDiff(0)
	, m_nUniqRatio(0)
	, m_nSpeckRange(0)
	, m_nSpeckWinSiz(0)
	, m_bModeHH(FALSE)
	, m_pCheck(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbinocularMeasureDSMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_Left, m_showImg_left);
	DDX_Control(pDX, IDC_PIC_Right, m_showImg_right);
	DDX_Control(pDX, IDC_PIC_Disparity, m_showImg_disparity);
	DDX_Text(pDX, IDC_EDIT_ShowDistance, m_edit_showDistance);
	DDX_Text(pDX, IDC_EDIT_LeftFlder, m_edit_LeftFolder);
	DDX_Text(pDX, IDC_EDIT_RightFolder, m_edit_RightFolder);
	DDX_Text(pDX, IDC_EDIT_ParmFolder, m_edit_ParmFileName);
	DDX_Text(pDX, IDC_EDIT_NumOfImg, m_edit_NumOfImg);
	DDX_Control(pDX, IDC_EDIT_ShowDistance, m_ctrl_edit_showDistance);
	DDX_Control(pDX, IDC_EDIT_Show, m_ctrl_edit_show);
	DDX_Control(pDX, IDC_COMBO_CamList_L, m_COMBO_CamList_L);
	DDX_Control(pDX, IDC_COMBO_CamList_R, m_COMBO_CamList_R);
	DDX_Control(pDX, IDC_COMBO_MethodList, m_COMBO_MethodList);
	DDX_Text(pDX, IDC_EDIT_BoardWidth, m_nBoardSize_X);
	DDX_Text(pDX, IDC_EDIT_BoardHeight, m_nBoardSize_Y);
	DDX_Text(pDX, IDC_EDIT_SquareSize, m_nSquareSize);
	DDX_Text(pDX, IDC_EDIT_DelayTime, m_nDelayTime);
	DDX_Text(pDX, IDC_EDIT_minDisp, m_nMinDisp);
	DDX_Text(pDX, IDC_EDIT_preFiltCap, m_nPreFiltCap);
	DDX_Text(pDX, IDC_EDIT_numDisp, m_nNumDisp);
	DDX_Text(pDX, IDC_EDIT_SADWinSize, m_nSADWinSiz);
	DDX_Text(pDX, IDC_EDIT_textThres, m_nTextThres);
	DDX_Text(pDX, IDC_EDIT_disp12MaxDiff, m_nDisp12MaxDiff);
	DDX_Text(pDX, IDC_EDIT_uniqRatio, m_nUniqRatio);
	DDX_Text(pDX, IDC_EDIT_speckRange, m_nSpeckRange);
	DDX_Text(pDX, IDC_EDIT_speckWinSize, m_nSpeckWinSiz);
	DDX_Check(pDX, IDC_CHK_ModeHH, m_bModeHH);
}

BEGIN_MESSAGE_MAP(CbinocularMeasureDSMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_Execute, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnExecute)
ON_BN_CLICKED(IDC_BTN_SelectLeftFolder, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnSelectleftfolder)
ON_BN_CLICKED(IDC_BTN_SelectRightFolder, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnSelectrightfolder)
ON_BN_CLICKED(IDC_BTN_SelectParmFolder, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnSelectparmfolder)
ON_CBN_SELCHANGE(IDC_COMBO_CamList_L, &CbinocularMeasureDSMFCDlg::OnCbnSelchangeComboCamlistL)
ON_CBN_SELCHANGE(IDC_COMBO_CamList_R, &CbinocularMeasureDSMFCDlg::OnCbnSelchangeComboCamlistR)
ON_BN_CLICKED(IDC_BTN_OpenCam, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnOpencam)
ON_BN_CLICKED(IDC_BTN_CloseCam, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnClosecam)
ON_BN_CLICKED(IDC_BTN_Snapshot, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnSnapshot)
ON_WM_TIMER()
ON_CBN_SELCHANGE(IDC_COMBO_MethodList, &CbinocularMeasureDSMFCDlg::OnCbnSelchangeComboMethodlist)
ON_BN_CLICKED(IDC_BTN_DefaultCamCalibParam, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnDefaultcamcalibparam)
ON_BN_CLICKED(IDC_BTN_Calib, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnCalib)
ON_BN_CLICKED(IDC_BTN_ReadCalibParm, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnReadcalibparm)
ON_BN_CLICKED(IDC_BTN_Rectify, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnRectify)
ON_BN_CLICKED(IDC_BTN_DefaultStereoParm, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnDefaultstereoparm)
ON_BN_CLICKED(IDC_BTN_ReadImg, &CbinocularMeasureDSMFCDlg::OnBnClickedBtnReadimg)
ON_BN_CLICKED(IDC_RADIO_BM, &CbinocularMeasureDSMFCDlg::OnBnClickedRadioBm)
ON_BN_CLICKED(IDC_RADIO_SGBM, &CbinocularMeasureDSMFCDlg::OnBnClickedRadioSgbm)
ON_BN_CLICKED(IDC_RADIO_DispFromCam, &CbinocularMeasureDSMFCDlg::OnBnClickedRadioDispfromcam)
ON_BN_CLICKED(IDC_RADIO_DispFromImg, &CbinocularMeasureDSMFCDlg::OnBnClickedRadioDispfromimg)
ON_EN_CHANGE(IDC_EDIT_Show, &CbinocularMeasureDSMFCDlg::OnEnChangeEditShow)
ON_EN_CHANGE(IDC_EDIT_speckRange, &CbinocularMeasureDSMFCDlg::OnEnChangeEditspeckrange)
ON_STN_CLICKED(IDC_PIC_Right, &CbinocularMeasureDSMFCDlg::OnStnClickedPicRight)
ON_BN_CLICKED(IDCANCEL, &CbinocularMeasureDSMFCDlg::OnBnClickedCancel)
ON_EN_CHANGE(IDC_EDIT_SADWinSize, &CbinocularMeasureDSMFCDlg::OnEnChangeEditSadwinsize)
ON_EN_CHANGE(IDC_EDIT_speckWinSize, &CbinocularMeasureDSMFCDlg::OnEnChangeEditspeckwinsize)
END_MESSAGE_MAP()


// CbinocularMeasureDSMFCDlg ��Ϣ�������

BOOL CbinocularMeasureDSMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_showImg_left.OnInit();
	m_showImg_right.OnInit();
	m_showImg_disparity.OnInit();

	writeImgindex = 1;//�����ͼ�����ʼ���

	m_edit_NumOfImg = 13;//Ĭ�ϵ�ͼƬ����

	data_Loaded = false;
	img_Loaded = false;
	cam_opened = false;
	parm_selected = false;

	picIndex = 1;

	m_workDir = F_InitWorkDir();

	// Ĭ��ͼ������Ϊ��ʾԭʼͼ��
	m_ProcMethod = SHOW_ORIGINAL_FRAME;

	// ��ȡ����ͷ��Ŀ
	m_nCamCount = CCameraDS::CameraCount();
	if (m_nCamCount < 1)
	{
		AfxMessageBox(_T("���������1������ͷ��Ȼ����������"));
	}

	// ����Ͽ�CamList���������ͷ���Ƶ��ַ���
	char camera_name[1024];
	char istr[1024];
	CString camstr;
	for (int i = 0; i < m_nCamCount; i++)
	{
		int retval = CCameraDS::CameraName(i, camera_name, sizeof(camera_name));

		sprintf_s(istr, "#%d ", i);
		strcat_s(istr, camera_name);
		camstr = istr;
		if (retval > 0)
		{
			m_COMBO_CamList_L.AddString(camstr);
			m_COMBO_CamList_R.AddString(camstr);
		}
		else
			AfxMessageBox(_T("���ܻ�ȡ����ͷ������"));
	}
	camstr.ReleaseBuffer();
	if (m_nCamCount <= 1)
		m_COMBO_CamList_R.EnableWindow(FALSE);

	// ����Ͽ�MethodList����Ӹ���֡���������ַ���
	m_COMBO_MethodList.AddString(_T("��ʾԭʼ����"));
	m_COMBO_MethodList.AddString(_T("��Ե���"));
	m_COMBO_MethodList.AddString(_T("�Ҷȴ���"));
	m_COMBO_MethodList.AddString(_T("ͼ��ƽ������"));
	m_COMBO_MethodList.SetCurSel(0);

	// ʹһϵ�а�ťʧЧ
	GetDlgItem(IDC_BTN_OpenCam)->EnableWindow(FALSE);			// ��������ͷʧЧ
	GetDlgItem(IDC_BTN_CloseCam)->EnableWindow(FALSE);			// ֹͣ����ͷʧЧ
	GetDlgItem(IDC_BTN_Execute)->EnableWindow(FALSE);			// �����Ӳ�ʧЧ
	GetDlgItem(IDC_BTN_Snapshot)->EnableWindow(FALSE);			// ����ͼ��ʧЧ
	GetDlgItem(IDC_BTN_ReadImg)->EnableWindow(FALSE);			// ����ͼ��ʧЧ
	GetDlgItem(IDC_BTN_ReadCalibParm)->EnableWindow(FALSE);		// ��������ļ�ʧЧ
	GetDlgItem(IDC_BTN_Rectify)->EnableWindow(FALSE);			// ��ʾУ�����ʧЧ 


	// ��ʼ��˫Ŀƥ������ؼ�����
	CheckRadioButton(IDC_RADIO_BM, IDC_RADIO_SGBM, IDC_RADIO_BM);							// Ĭ��ʹ�� BM �㷨�����Ӳ�
	CheckRadioButton(IDC_RADIO_DispFromCam, IDC_RADIO_DispFromImg, IDC_RADIO_DispFromCam);	// Ĭ�ϴ��������ȡͼ��

	m_nImageWidth = 640;
	m_nImageHeight = 480;

	m_nBoardSize_X = 9;
	m_nBoardSize_Y = 6;
	m_nSquareSize = 25.0f;
	m_nDelayTime = 5;//��λ ��
	m_bModeHH = FALSE;

	// ��ʼ��ͼ����ʾ�ؼ���ͼ��
	m_lfImage = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_riImage = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_disparity = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);

	OnBnClickedBtnDefaultstereoparm();

	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CbinocularMeasureDSMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CbinocularMeasureDSMFCDlg::OnPaint()
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
HCURSOR CbinocularMeasureDSMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbinocularMeasureDSMFCDlg::OnBnClickedBtnExecute()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	// ��������ͷ�������
	FileStorage fs;
	if (parm_selected)
	{
		const char* parmName = NULL;
		parmName = CStringA(m_edit_ParmFileName);
		fs.open(parmName, FileStorage::READ);
	}
	else
		fs.open("calibParms.xml", FileStorage::READ);
	
	cout << fs.isOpened() << endl;

	if (!fs.isOpened())
	{
		data_Loaded = false;
		return;
	}

	cv::FileNodeIterator it = fs["imageSize"].begin();
	it >> imageSize.width >> imageSize.height;
	fs["cameraMatrixL"] >> cameraMatrixL;
	fs["cameraDistcoeffL"] >> distCoeffL;
	fs["cameraMatrixR"] >> cameraMatrixR;
	fs["cameraDistcoeffR"] >> distCoeffR;
	fs["R"] >> R;
	fs["T"] >> T;

	fs.release();
	data_Loaded = true;

	stereoRectify(cameraMatrixL, distCoeffL, cameraMatrixR, distCoeffR, imageSize, R, T, Rl, Rr, Pl, Pr, Mat_Q,
		CALIB_ZERO_DISPARITY, -1, imageSize, &Roi_L, &Roi_R);

	initUndistortRectifyMap(cameraMatrixL, distCoeffL, Rl, Pl, imageSize, CV_16SC2, Mat_Remap_X_L, Mat_Remap_Y_L);
	initUndistortRectifyMap(cameraMatrixR, distCoeffR, Rr, Pr, imageSize, CV_16SC2, Mat_Remap_X_R, Mat_Remap_Y_R);

	Mat_Q.at<double>(3, 2) = -Mat_Q.at<double>(3, 2);

	Mat_Mask_Roi = cv::Mat::zeros(m_nImageHeight, m_nImageWidth, CV_8UC1);
	cv::rectangle(Mat_Mask_Roi, Roi_L, cv::Scalar(255), -1);
	
	//�Ӳ����
	m_nID_RADIO = GetCheckedRadioButton(IDC_RADIO_DispFromCam, IDC_RADIO_DispFromImg);
	if (m_nID_RADIO == IDC_RADIO_DispFromCam)
	{
		KillTimer(1);
		KillTimer(3);
		SetTimer(2, 10, NULL);
	}
	else if (m_nID_RADIO == IDC_RADIO_DispFromImg)
	{
		KillTimer(1);
		KillTimer(2);
		SetTimer(3, 10, NULL);
	}

	m_edit_showDistance = " ";

	UpdateData(FALSE);
}


BOOL CbinocularMeasureDSMFCDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg-> message==WM_LBUTTONDOWN)     
	{
		CPoint   ptCursor; 
		GetCursorPos(&ptCursor); 

		CRect rc_disparity;
		GetDlgItem(IDC_PIC_Disparity)->GetWindowRect(&rc_disparity);
		if (rc_disparity.PtInRect(ptCursor))
		{
			CPoint tf = rc_disparity.TopLeft();

			double xx = (ptCursor.x - tf.x) * 640 / rc_disparity.Width();
			double yy = (ptCursor.y - tf.y) * 480 / rc_disparity.Height();
			

			if (pointClouds.empty())
			{
				return FALSE;
			}

			float  distance = -pointClouds.at<cv::Point3f>(yy, xx).z / 4 ;
			float newdistance = distance;
			if (distance < 100)
			{
				newdistance = distance;
			}
			else
			{
				newdistance = distance;
			}
			if (newdistance >= 0)
			{
				CString str;
				str.Format(_T("The distance at ( %d , %d ) is %.3f cm "), int(xx), int(yy), newdistance);
				str.Format(_T("������( %d , %d )λ�õľ����ǣ� %.3f cm "), int(xx), int(yy), newdistance);

				m_ctrl_edit_showDistance.SetSel(-1, -1);			//�Զ�����
				m_ctrl_edit_showDistance.ReplaceSel(str+"\r\n");    //�Զ�����
			}
		}
	}
	else if (pMsg->message == WM_MOUSEMOVE)
	{
		CPoint   ptCursor;
		GetCursorPos(&ptCursor);

		CRect rc_left;
		GetDlgItem(IDC_PIC_Left)->GetWindowRect(&rc_left);
		if (GetCheckedRadioButton(IDC_RADIO_DispFromCam, IDC_RADIO_DispFromImg) == IDC_RADIO_DispFromImg && rc_left.PtInRect(ptCursor))
		{
			CPoint tf = rc_left.TopLeft();

			double xx = (ptCursor.x - tf.x) * 640 / rc_left.Width();
			double yy = (ptCursor.y - tf.y) * 480 / rc_left.Height();

			Mat left_tmp, right_tmp;
			m_lfImage.copyTo(left_tmp);
			m_riImage.copyTo(right_tmp);


			rectangle(left_tmp, Rect(Point(xx - 3, yy - 3), Point(xx + 3, yy + 3)), Scalar(0, 0, 255), 3);
			rectangle(right_tmp, Rect(Point(xx - 3, yy - 3), Point(xx + 3, yy + 3)), Scalar(0, 0, 255), 3);

			m_showImg_left.ShowImage(left_tmp, 1);
			m_showImg_right.ShowImage(right_tmp, 1);
		}

	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


CString CbinocularMeasureDSMFCDlg::selectFolder(void)
{
	TCHAR           szFolderPath[MAX_PATH] = {0};  
	CString         strFolderPath = TEXT("");  

	BROWSEINFO      sInfo;  
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));  
	sInfo.pidlRoot   = 0;  
	sInfo.lpszTitle  = _T("��ѡ��һ���ļ��У�");  
	sInfo.ulFlags   = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;  
	sInfo.lpfn     = NULL;

	// ��ʾ�ļ���ѡ��Ի���  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);   
	if (lpidlBrowse != NULL)  
	{  
		// ȡ���ļ�����  
		if (::SHGetPathFromIDList(lpidlBrowse,szFolderPath))    
		{  
			strFolderPath = szFolderPath;  
		}  
	}  
	if(lpidlBrowse != NULL)  
	{  
		::CoTaskMemFree(lpidlBrowse);  
	}  

	return strFolderPath;
}


/*----------------------------
* ���� : �������ļ��Ի���ѡ�񵥸������ļ�
*----------------------------
* ���� : DoSelectFiles
* ���� : selectedFiles	ѡ����ļ���·������
*
* ���� : lpszDefExt			[in]	�ļ�Ĭ�ϸ�ʽ
* ���� : dwFlags				[in]	�Ի���ѡ��
* ���� : lpszFilter			[in]	�ļ���ʽ��������
* ���� : lpstrTitle			[in]	�Ի������
* ���� : lpstrInitialDir		[in]	�Ի���ĳ�ʼ·��
*/
vector<CStringA> CbinocularMeasureDSMFCDlg::DoSelectFiles(
	LPCTSTR	lpszDefExt,
	DWORD	dwFlags,
	LPCTSTR	lpszFilter,
	LPCWSTR	lpstrTitle,
	LPCWSTR	lpstrInitialDir)
{
	vector<CStringA> selectedFiles;
	POSITION filePosition;
	DWORD MAXFILE = 4000;
	TCHAR* pc = new TCHAR[MAXFILE];

	CFileDialog dlg(TRUE, lpszDefExt, NULL, dwFlags, lpszFilter, NULL);

	dlg.m_ofn.nMaxFile = MAXFILE;
	dlg.m_ofn.lpstrFile = pc;
	dlg.m_ofn.lpstrFile[0] = NULL;
	dlg.m_ofn.lpstrTitle = lpstrTitle;
	dlg.m_ofn.lpstrInitialDir = lpstrInitialDir;

	if (dlg.DoModal() == IDOK)
	{
		filePosition = dlg.GetStartPosition();
		while (filePosition != NULL)
		{
			CStringA path;
			path = dlg.GetNextPathName(filePosition);
			selectedFiles.push_back(path);
		}
	}

	delete[]pc;
	return selectedFiles;
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnSelectleftfolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	leftFolderPath = selectFolder();
	m_edit_LeftFolder = leftFolderPath;
	UpdateData(FALSE);
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnSelectrightfolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	rightFolderPath = selectFolder();
	m_edit_RightFolder = rightFolderPath;
	UpdateData(FALSE);
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnSelectparmfolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ������ͷ��������ļ�
	vector<CStringA> xmlFiles;
	xmlFiles = DoSelectFiles(
		_T("*.xml"),
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("XML/YML file (*.xml; *.yml) |*.xml; *.yml | All Files (*.*) |*.*||"),
		_T("ѡ������ͷ��������ļ�"),
		m_workDir
		);

	if (xmlFiles.empty())
	{
		LPCTSTR errMsg = _T("û��ѡ����Ч������ͷ��������ļ�!");
		throw errMsg;
	}

	m_edit_ParmFileName = xmlFiles[0];

	parm_selected = true;

	UpdateData(FALSE);
}


void CbinocularMeasureDSMFCDlg::OnCbnSelchangeComboCamlistL()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	// ȷ����������ͷ��Ӧ���豸��ţ���Ӧ�����˵�ѡ�������ţ�
	m_lfCamID = m_COMBO_CamList_L.GetCurSel();

	// ʹ��������ͷ��ť��Ч
	GetDlgItem(IDC_BTN_OpenCam)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_CloseCam)->EnableWindow(FALSE);

	return;
}


void CbinocularMeasureDSMFCDlg::OnCbnSelchangeComboCamlistR()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	// ȷ����������ͷ��Ӧ���豸��ţ���Ӧ�����˵�ѡ�������ţ�
	m_riCamID = m_COMBO_CamList_R.GetCurSel();

	// ʹ��������ͷ��ť��Ч
	GetDlgItem(IDC_BTN_OpenCam)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_CloseCam)->EnableWindow(FALSE);

	return;
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnOpencam()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_riCamID == m_lfCamID)
	{
		AfxMessageBox(_T("��������ͷ���豸��Ų�����ͬ��"));
		return;
	}

	if (m_nCamCount > 0)
	{
		//�򿪵�һ������ͷ
		//if( ! lfCam.OpenCamera(m_lfCamID, false, m_nImageWidth, m_nImageHeight) ) //����������ѡ�񴰿ڣ��ô����ƶ�ͼ���͸�
		if (!lfCam.OpenCamera(m_lfCamID))
		{
			AfxMessageBox(_T("��������ͷʧ��."));
			return;
		}
	}

	if (m_nCamCount > 1)
	{
		//�򿪵ڶ�������ͷ
		//if( ! riCam.OpenCamera(m_riCamID, false, m_nImageWidth, m_nImageHeight) ) 
		if(! riCam.OpenCamera(m_riCamID))
		{
			AfxMessageBox(_T("��������ͷʧ��."));
			return;
		}
	}

	cam_opened = true;

	// ʹ���ְ�ť��Ч
	GetDlgItem(IDC_BTN_CloseCam)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_Snapshot)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_Execute)->EnableWindow(TRUE);
	// ʹ���ְ�ťʧЧ
	GetDlgItem(IDC_BTN_OpenCam)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_CamList_L)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_CamList_R)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_Calib)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SelectLeftFolder)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SelectRightFolder)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_ReadImg)->EnableWindow(FALSE);
	// ��������ͷ����ʾʵʱ����
	DoShowOrigFrame();
	return;
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnClosecam()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	GetDlgItem(IDC_BTN_CloseCam)->EnableWindow(FALSE);
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);

	lfCam.CloseCamera();
	riCam.CloseCamera();

	// ��ͼ����������
	m_lfImage = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_showImg_left.ShowImage(m_lfImage, 1);

	m_riImage = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_showImg_right.ShowImage(m_riImage, 1);

	cam_opened = false;

	// ʹ��������ͷ��ť������ͷѡ���б���Ч
	GetDlgItem(IDC_BTN_OpenCam)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_CamList_L)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_CamList_R)->EnableWindow(TRUE);

	GetDlgItem(IDC_BTN_SelectLeftFolder)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_SelectRightFolder)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_ReadImg)->EnableWindow(TRUE);

	GetDlgItem(IDC_BTN_Calib)->EnableWindow(TRUE);
	
	if (GetCheckedRadioButton(IDC_RADIO_DispFromCam, IDC_RADIO_DispFromImg) == IDC_RADIO_DispFromCam)
		GetDlgItem(IDC_BTN_Execute)->EnableWindow(FALSE);

	return;
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnSnapshot()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	char leftimg_file[100];
	char rightimg_file[100];

	sprintf(leftimg_file, "%s//%s%d.%s", leftimg_directory, leftimg_filename, writeImgindex, extension);
	sprintf(rightimg_file, "%s//%s%d.%s", rightimg_directory, rightimg_filename, writeImgindex, extension);

	imwrite(leftimg_file, m_lfImage);
	imwrite(rightimg_file, m_riImage);

	m_lfImage = Mat::ones(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_showImg_left.ShowImage(m_lfImage, 1);

	m_riImage = Mat::ones(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_showImg_right.ShowImage(m_riImage, 1);

	CString str;
	str.Format(_T("�ɹ������ %d ��ͼƬ %s �� %s"), int(writeImgindex), CString(leftimg_file), CString(rightimg_file));
	m_ctrl_edit_show.SetSel(-1, -1);				//�Զ�����
	m_ctrl_edit_show.ReplaceSel(str + "\r\n");		//�Զ�����

	writeImgindex++;
}


//��ʾ����ͷʵʱ����
void CbinocularMeasureDSMFCDlg::DoShowOrigFrame(void)
{
	// ��ͼ����������
	m_lfImage = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_showImg_left.ShowImage(m_lfImage, 1);

	m_riImage = Mat::zeros(m_nImageWidth, m_nImageHeight, CV_8UC3);
	m_showImg_right.ShowImage(m_riImage, 1);

	m_COMBO_MethodList.SetCurSel(0);
	m_ProcMethod = SHOW_ORIGINAL_FRAME;
	SetTimer(1, 0, NULL);	// 50ms ��ʱ��ʾ
}


void CbinocularMeasureDSMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	switch (nIDEvent)
	{
		case 1:
		{
			Mat imageLeft = Mat(lfCam.QueryFrame());
			Mat imageRight = Mat(riCam.QueryFrame());

			if (imageLeft.empty())	return;
			if (imageRight.empty())	return;

			if (m_ProcMethod != SHOW_ORIGINAL_FRAME)
			{
				DoFrameProc(imageLeft, imageLeft);
			}

			if (m_ProcMethod != SHOW_ORIGINAL_FRAME)
			{
				DoFrameProc(imageRight, imageRight);
			}

			m_showImg_left.ShowImage(imageLeft, 1);
			m_showImg_right.ShowImage(imageRight, 1);

			//
			m_lfImage = imageLeft;
			m_riImage = imageRight;
		}
		break;
	
		case 2:
		{
			int t1 = 0, t2 = 0, t3 = 0;
			clock_t t_ms = clock();

			Mat frameLeft = Mat(lfCam.QueryFrame());
			Mat frameRight = Mat(riCam.QueryFrame());
			
			if (frameLeft.empty() || frameRight.empty()) return;
			if (m_nImageWidth == 0 || m_nImageHeight == 0) return;

			t1 = (clock() - t_ms) * 1000 / CLOCKS_PER_SEC;
			t_ms = clock();

			Mat disp, disparityImage;
			Mat imageLeft, imageRight;//˫Ŀƥ����������ͼ

			doMatch(frameLeft, frameRight, disp, imageLeft, imageRight);

			getDisparityImage(disp, disparityImage, false);

			t2 = (clock() - t_ms) * 1000 / CLOCKS_PER_SEC;
			t_ms = clock();

			//��ȡ����
			cv::reprojectImageTo3D(disparityImage, pointClouds, Mat_Q, true);
			pointClouds *= 1.6;

			t3 = (clock() - t_ms) * 1000 / CLOCKS_PER_SEC;

			m_showImg_left.ShowImage(imageLeft, 1);
			m_showImg_right.ShowImage(imageRight, 1);
			m_showImg_disparity.ShowImage(disparityImage, 1);


			CString str1, str2, str3;
			str1.Format(_T("��ʱ������ͼ�� %d ms���Ӳ���� %d ms����ȡ���� %d ms"), t1, t2, t3);
			str2.Format(_T("������ɣ����������ͼ�������"));
			str3.Format(_T("��� ��ʼ��� ���м�����һ��"));
			GetDlgItem(IDC_EDIT_Show)->SetWindowText(str1 + "\r\n" + str2 + "\r\n" + str3 + "\r\n");

			picIndex++;
		}
		break;
		case 3:
		{
			if (picIndex <= m_edit_NumOfImg)
			{
				int k = picIndex;

				int t1 = 0, t2 = 0, t3 = 0;
				clock_t t_ms = clock();

				char leftimg_file[100];
				char rightimg_file[100];
				//leftimg_directory = (LPSTR)(LPCSTR)leftFolderPath;
				//rightimg_directory = (LPSTR)(LPCSTR)rightFolderPath;
				sprintf(leftimg_file, "%s//%s%d.%s", leftimg_directory, leftimg_filename, k, extension);
				sprintf(rightimg_file, "%s//%s%d.%s", rightimg_directory, rightimg_filename, k, extension);

				//��ȡһ֡
				Mat frameLeft = imread(leftimg_file, CV_LOAD_IMAGE_COLOR);
				Mat frameRight = imread(rightimg_file, CV_LOAD_IMAGE_COLOR);

				if (frameLeft.empty() || frameRight.empty()) return;
				if (m_nImageWidth == 0 || m_nImageHeight == 0) return;

				Mat disp, disparityImage;

				doMatch(frameLeft, frameRight, disp, m_lfImage, m_riImage);

				getDisparityImage(disp, disparityImage, false);

				t2 = (clock() - t_ms) * 1000 / CLOCKS_PER_SEC;
				t_ms = clock();

				//��ȡ����
				cv::reprojectImageTo3D(disparityImage, pointClouds, Mat_Q, true);
				pointClouds *= 1.6;

				t3 = (clock() - t_ms) * 1000 / CLOCKS_PER_SEC;

				m_showImg_left.ShowImage(m_lfImage, 1);
				m_showImg_right.ShowImage(m_riImage, 1);
				m_showImg_disparity.ShowImage(disparityImage, 1);

				CString str1, str2, str3, str4;
				str1.Format(_T("��ǰ����� %d ��ͼƬ"), picIndex);
				str2.Format(_T("��ʱ������ͼ�� %d ms���Ӳ���� %d ms����ȡ���� %d ms"), t1, t2, t3);
				str3.Format(_T("������ɣ����������ͼ�������"));
				str4.Format(_T("��� ��ʼ��� ���м�����һ��"));
				GetDlgItem(IDC_EDIT_Show)->SetWindowText(str1 + "\r\n" + str2 + "\r\n" + str3 + "\r\n" + str4 + "\r\n");

				picIndex++;
			}
			else
				GetDlgItem(IDC_EDIT_Show)->SetWindowText(_T("ȫ��������ɣ�"));
		}
		break;
	}

	KillTimer(3);
	CDialog::OnTimer(nIDEvent);
}


//��֡ͼ����д���
void  CbinocularMeasureDSMFCDlg::DoFrameProc(Mat& src, Mat& dst)
{
	try
	{
		switch (m_ProcMethod)
		{
		//case 0:
		//{
		//}
		//break;
		//}
		case SHOW_GRAY_FRAME:
		{
				  cvtColor(src, dst, CV_BGR2GRAY);
		}
			break;

		case SHOW_GAUSSIAN_FRAME:
		{
					int k = 5;
					GaussianBlur(src, dst, Size(k, k), 0, 0);
		}
			break;
		case SHOW_EDGE_IMAGE:
		{
								Mat gray, edge, edge8u;

								edge = cv::Mat(src.size(), CV_16S);

								// ��Դͼ��תΪ�Ҷ�ͼ��
								if (src.channels() == 1)
									src.copyTo(gray);
								else
									cvtColor(src, gray, CV_RGB2GRAY);

								// ��Ե���
								Sobel(gray, edge, CV_16S, 0, 1);
								edge.convertTo(edge8u, CV_8U);

								// ����Ե���ͼ��ת�����ͼ���ʽ
								if (dst.channels() == 1)
									edge8u.copyTo(dst);
								else
									cvtColor(edge8u, dst, CV_GRAY2BGR);
		}
			break;

		}
	}
	catch (cv::Exception& e)
	{
		char err[2048];
		sprintf_s(err, "��������: %s", e.what());
		CString errInfo;
		errInfo = err;
		AfxMessageBox(errInfo);
	}
	catch (...)
	{
		AfxMessageBox(_T("����δ֪����"));
	}

	return;
}


void CbinocularMeasureDSMFCDlg::OnCbnSelchangeComboMethodlist()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_ProcMethod = m_COMBO_MethodList.GetCurSel();
}

void CbinocularMeasureDSMFCDlg::OnBnClickedBtnDefaultcamcalibparam()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_nBoardSize_X = 9;
	m_nBoardSize_Y = 6;
	m_nSquareSize = 25.0f;
	UpdateData(FALSE);
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnCalib()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	KillTimer(1);
	GetDlgItem(IDC_BTN_Calib)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO_MethodList)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_Execute)->EnableWindow(FALSE);


	//////////////////////////////////
	//�Ƚ��е�Ŀ�궨
	Size imgSize;
	Size board_size = Size(m_nBoardSize_X, m_nBoardSize_Y);
	int board_n = m_nBoardSize_X * m_nBoardSize_Y;
	Mat lf_img, ri_img, lf_gray, ri_gray;
	Mat lf_cameraMatrix, ri_cameraMatrix;
	Mat lf_cameraDistcoeff, ri_cameraDistcoeff;
	vector< vector< Point3f > > object_points;
	vector< vector< Point2f > > lf_image_points, ri_image_points;
	vector< Mat > lf_rvecs, lf_tvecs, ri_rvecs, ri_tvecs;
	int flag = 0;
	flag |= CV_CALIB_FIX_K4;
	flag |= CV_CALIB_FIX_K5;

	char* lf_out_file = "parms//leftParms.xml";		// ����������ͷ����·�����ļ���
	char* ri_out_file = "parms//rightParms.xml";	// ����������ͷ����·�����ļ���
	char* stereo_out_file = "parms//calibParms.xml";	// ����������ͷ����·�����ļ���

	
	vector<Mat> lf_imgs, ri_imgs;
	for (int i = 1; i <= m_edit_NumOfImg; i++)
	{
		char lf_img_file[100], ri_img_file[100];
		sprintf(lf_img_file, "%s//%s%d.%s", leftimg_directory, leftimg_filename, i, extension);
		sprintf(ri_img_file, "%s//%s%d.%s", rightimg_directory, rightimg_filename, i, extension);
		
		lf_img = imread(lf_img_file, CV_LOAD_IMAGE_COLOR);
		ri_img = imread(ri_img_file, CV_LOAD_IMAGE_COLOR);

		if (lf_img.empty() || ri_img.empty())
		{
			AfxMessageBox(_T("����ͼƬ����,��ȷ������ͼ·������"));
			return ;
		}

		lf_imgs.push_back(lf_img);
		ri_imgs.push_back(ri_img);

		imgSize = lf_img.size();

		cv::cvtColor(lf_img, lf_gray, CV_BGR2GRAY);
		cv::cvtColor(ri_img, ri_gray, CV_BGR2GRAY);

		bool found = false;
		vector< Point2f > lf_corners;
		vector< Point2f > ri_corners;
		found = cv::findChessboardCorners(lf_img, board_size, lf_corners, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS) && 
			cv::findChessboardCorners(ri_img, board_size, ri_corners, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);;
		if (found)
		{
			cornerSubPix(lf_gray, lf_corners, cv::Size(5, 5), cv::Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			cornerSubPix(ri_gray, ri_corners, cv::Size(5, 5), cv::Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			drawChessboardCorners(lf_img, board_size, lf_corners, found);
			drawChessboardCorners(ri_img, board_size, ri_corners, found);
		}

		vector< Point3f > obj;
		for (int i = 0; i < m_nBoardSize_Y; i++)
			for (int j = 0; j < m_nBoardSize_X; j++)
				obj.push_back(Point3f((float)j * m_nSquareSize, (float)i * m_nSquareSize, 0));

		if (found)
		{
			cout << "ͼƬ " << i << " ��⵽�ǵ�!" << endl;
			lf_image_points.push_back(lf_corners);
			ri_image_points.push_back(ri_corners);
			object_points.push_back(obj);
		}

		m_showImg_left.ShowImage(lf_img, 1);
		m_showImg_right.ShowImage(ri_img, 1);
	}

	printf("��ʼ�궨...\n");
	
	calibrateCamera(object_points, lf_image_points, imgSize, lf_cameraMatrix, lf_cameraDistcoeff, lf_rvecs, lf_tvecs, flag);
	calibrateCamera(object_points, ri_image_points, imgSize, ri_cameraMatrix, ri_cameraDistcoeff, ri_rvecs, ri_tvecs, flag);

	cv::FileStorage lf_fs(lf_out_file, cv::FileStorage::WRITE);
	lf_fs << "cameraMatrix" << lf_cameraMatrix;
	lf_fs << "cameraDistcoeff" << lf_cameraDistcoeff;
	lf_fs << "board_width" << m_nBoardSize_X;
	lf_fs << "board_height" << m_nBoardSize_Y;
	lf_fs << "square_size" << m_nSquareSize;

	cv::FileStorage ri_fs(ri_out_file, cv::FileStorage::WRITE);
	ri_fs << "cameraMatrix" << ri_cameraMatrix;
	ri_fs << "cameraDistcoeff" << ri_cameraDistcoeff;
	ri_fs << "board_width" << m_nBoardSize_X;
	ri_fs << "board_height" << m_nBoardSize_Y;
	ri_fs << "square_size" << m_nSquareSize;

	printf("�궨��ɣ�\n");
	//////////////////////////////////



	//////////////////////////////////
	//˫Ŀ�궨
	stereoCalibrate(object_points, lf_image_points, ri_image_points, lf_cameraMatrix, lf_cameraDistcoeff, ri_cameraMatrix, ri_cameraDistcoeff, imgSize, R, T, E, F);

	cv::FileStorage fso(stereo_out_file, cv::FileStorage::WRITE);
	fso << "imageSize" << imgSize;
	fso << "cameraMatrixL" << lf_cameraMatrix;
	fso << "cameraDistcoeffL" << lf_cameraDistcoeff;
	fso << "cameraMatrixR" << ri_cameraMatrix;
	fso << "cameraDistcoeffR" << ri_cameraDistcoeff;
	fso << "R" << R;
	fso << "T" << T;
	fso << "E" << E;
	fso << "F" << F;

	printf("�궨��ɣ�\n");

	printf("��ʼУ��...\n");

	cv::Mat R1, R2, P1, P2, Q;
	stereoRectify(lf_cameraMatrix, lf_cameraDistcoeff, ri_cameraMatrix, ri_cameraDistcoeff, imgSize, R, T, R1, R2, P1, P2, Q);

	fso << "R1" << R1;
	fso << "R2" << R2;
	fso << "P1" << P1;
	fso << "P2" << P2;
	fso << "Q" << Q;

	printf("У����ɣ�\n");
	//////////////////////////////////


	//////////////////////////////////
	//������������





	//////////////////////////////////

	// ����������ָ�˫Ŀ���갴ť
	GetDlgItem(IDC_BTN_Calib)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_MethodList)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_Execute)->EnableWindow(TRUE);

	// �ָ�������ʾ
	//DoShowOrigFrame();
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnReadcalibparm()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnRectify()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnDefaultstereoparm()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_nID_RADIO = GetCheckedRadioButton(IDC_RADIO_BM, IDC_RADIO_SGBM);
	if (m_nID_RADIO == IDC_RADIO_BM)
	{
		m_nMinDisp = 0;
		m_nNumDisp = 64;
		m_nSADWinSiz = 19;
		m_nTextThres = 10;
		m_nDisp12MaxDiff = -1;
		m_nPreFiltCap = 31;
		m_nUniqRatio = 25;
		m_nSpeckRange = 32;
		m_nSpeckWinSiz = 100;
	}
	else if (m_nID_RADIO == IDC_RADIO_SGBM)
	{
		m_nMinDisp = 0;
		m_nNumDisp = 64;
		m_nSADWinSiz = 7;
		m_nDisp12MaxDiff = -1;
		m_nPreFiltCap = 63;
		m_nUniqRatio = 25;
		m_nSpeckRange = 32;
		m_nSpeckWinSiz = 100;
		m_pCheck = (CButton*)GetDlgItem(IDC_CHK_ModeHH);
		m_pCheck->SetCheck(0);
	}
	UpdateData(FALSE);
}


void CbinocularMeasureDSMFCDlg::OnBnClickedBtnReadimg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 1; i <= m_edit_NumOfImg; i++)
	{
		Mat lf_frame, ri_frame;//������ͼ

		char leftimg_file[100];
		char rightimg_file[100];

		const char *left_directory0 = NULL;
		const char *right_directory0 = NULL;
		char left_directory[100] = "";
		char right_directory[100] = "";
		left_directory0 = leftFolderPath;
		right_directory0 = rightFolderPath;

		for (int m = 0, k = 0; m < strlen(left_directory0); m++, k++)
		{
			
			if (left_directory0[m] == '\\')
			{
				left_directory[k] = '\/';
				left_directory[++k] = '\/';
			}
			else
			{
				left_directory[k] = left_directory0[m];
			}
		}

		for (int m = 0, k = 0; m < strlen(right_directory0); m++, k++)
		{

			if (right_directory0[m] == '\\')
			{
				right_directory[k] = '\/';
				right_directory[++k] = '\/';
			}
			else
			{
				right_directory[k] = right_directory0[m];
			}
		}

		sprintf(leftimg_file, "%s//%s%d.%s", left_directory, leftimg_filename, i, extension);
		sprintf(rightimg_file, "%s//%s%d.%s", right_directory, rightimg_filename, i, extension);

		//��ȡһ֡
		lf_frame = imread(leftimg_file, CV_LOAD_IMAGE_COLOR);
		ri_frame = imread(rightimg_file, CV_LOAD_IMAGE_COLOR);
		if (lf_frame.empty() || ri_frame.empty())
		{
			printf("����ͼ�����\n");
			return;
		}

		m_showImg_left.ShowImage(lf_frame, 1);
		m_showImg_right.ShowImage(ri_frame, 1);

		m_lf_imgs.push_back(lf_frame);
		m_ri_imgs.push_back(ri_frame);

		CString str;
		str.Format(_T("�ѳɹ����� %s ~"), CString(leftimg_file));
		m_ctrl_edit_show.SetSel(-1, -1);				//�Զ�����
		m_ctrl_edit_show.ReplaceSel(str + "\r\n");		//�Զ�����
		str.Format(_T("�ѳɹ����� %s ~"), CString(rightimg_file));
		m_ctrl_edit_show.SetSel(-1, -1);				//�Զ�����
		m_ctrl_edit_show.ReplaceSel(str + "\r\n");		//�Զ�����
	}
	m_ctrl_edit_show.ReplaceSel(CString("\r\n"));		//�Զ�����
}


void CbinocularMeasureDSMFCDlg::OnBnClickedRadioBm()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	GetDlgItem(IDC_EDIT_minDisp)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_numDisp)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SADWinSize)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_textThres)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_disp12MaxDiff)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_preFiltCap)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_uniqRatio)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_speckRange)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_speckWinSize)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHK_ModeHH)->EnableWindow(FALSE);

	OnBnClickedBtnDefaultstereoparm();
}


void CbinocularMeasureDSMFCDlg::OnBnClickedRadioSgbm()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	GetDlgItem(IDC_EDIT_minDisp)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_numDisp)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SADWinSize)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_textThres)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_disp12MaxDiff)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_preFiltCap)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_uniqRatio)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_speckRange)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_speckWinSize)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHK_ModeHH)->EnableWindow(TRUE);

	OnBnClickedBtnDefaultstereoparm();
}


//��ʼ����������������ļ���
CString CbinocularMeasureDSMFCDlg::F_InitWorkDir()
{
	CStringA strPath;
	TCHAR path[_MAX_PATH];
	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[_MAX_DIR];
	TCHAR fname[_MAX_FNAME];
	TCHAR ext[_MAX_EXT];
	::GetModuleFileName(AfxGetApp()->m_hInstance, path, _MAX_PATH);
	_tsplitpath(path, drive, dir, fname, ext);

	strPath.Empty();
	strPath += CString(drive);
	strPath += CString(dir);

	return CString(strPath);
}


//����ļ����Ƿ����
bool CbinocularMeasureDSMFCDlg::F_CheckDir(const string dir, bool creatDir /* = false */)
{
	bool RetVal = false;

	string fileName = dir;
	fileName += "\\*";

	_finddata_t FileInfo;
	long Handle = _findfirst(fileName.c_str(), &FileInfo);

	if (Handle == -1L)
	{
		if (creatDir)
		{
			if (_mkdir(dir.c_str()) == 0)
			{
				RetVal = true;
			}
		}
	}
	else
	{
		RetVal = true;
		_findclose(Handle);
	}

	return RetVal;
}


int CbinocularMeasureDSMFCDlg::getDisparityImage(cv::Mat& disparity, cv::Mat& disparityImage, bool isColor)
{
	// ��ԭʼ�Ӳ����ݵ�λ��ת��Ϊ 8 λ
	cv::Mat disp8u;
	if (disparity.depth() != CV_8U)
	{
		if (disparity.depth() == CV_8S)
		{
			disparity.convertTo(disp8u, CV_8U);
		}
		else
		{
			disparity.convertTo(disp8u, CV_8U, 255 / (numberOfDisparies*16.));
		}
	}
	else
	{
		disp8u = disparity;
	}

	// ת��Ϊα��ɫͼ�� �� �Ҷ�ͼ��
	if (isColor)
	{
		if (disparityImage.empty() || disparityImage.type() != CV_8UC3 || disparityImage.size() != disparity.size())
		{
			disparityImage = cv::Mat::zeros(disparity.rows, disparity.cols, CV_8UC3);
		}

		for (int y = 0; y < disparity.rows; y++)
		{
			for (int x = 0; x < disparity.cols; x++)
			{
				uchar val = disp8u.at<uchar>(y, x);
				uchar r, g, b;

				if (val == 0)
					r = g = b = 0;
				else
				{
					r = 255 - val;
					g = val < 128 ? val * 2 : (uchar)((255 - val) * 2);
					b = val;
				}

				disparityImage.at<cv::Vec3b>(y, x) = cv::Vec3b(r, g, b);
			}
		}
	}
	else
	{
		disp8u.copyTo(disparityImage);
	}

	return 1;
}

void CbinocularMeasureDSMFCDlg::OnBnClickedRadioDispfromcam()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (cam_opened)
		GetDlgItem(IDC_BTN_Execute)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BTN_Execute)->EnableWindow(FALSE);
}


void CbinocularMeasureDSMFCDlg::OnBnClickedRadioDispfromimg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_BTN_Execute)->EnableWindow(TRUE);
}


void CbinocularMeasureDSMFCDlg::doMatch(Mat frameLeft, Mat frameRight, Mat &disp, Mat &imageLeft, Mat &imageRight)
{
	//˫Ŀƥ���������Ӳ�
	m_nID_RADIO = GetCheckedRadioButton(IDC_RADIO_BM, IDC_RADIO_SGBM);
	if (m_nID_RADIO == IDC_RADIO_BM)
	{
		BM.state->roi1 = Roi_L;
		BM.state->roi2 = Roi_R;
		BM.state->minDisparity = m_nMinDisp;
		BM.state->numberOfDisparities = m_nNumDisp;
		BM.state->SADWindowSize = m_nSADWinSiz;
		BM.state->textureThreshold = m_nTextThres;
		BM.state->disp12MaxDiff = m_nDisp12MaxDiff;
		BM.state->preFilterCap = m_nPreFiltCap;
		BM.state->uniquenessRatio = m_nUniqRatio;
		BM.state->speckleRange = m_nSpeckRange;
		BM.state->speckleWindowSize = m_nSpeckWinSiz;

		// ת��Ϊ�Ҷ�ͼ
		cv::Mat img1proc, img2proc;
		cvtColor(frameLeft, img1proc, CV_BGR2GRAY);
		cvtColor(frameRight, img2proc, CV_BGR2GRAY);

		// У��ͼ��ʹ������ͼ�ж���    
		cv::Mat img1remap, img2remap;

		if (data_Loaded)
		{
			// �������Ӳ����Ļ������У��
			remap(img1proc, img1remap, Mat_Remap_X_L, Mat_Remap_Y_L, cv::INTER_LINEAR);
			remap(img2proc, img2remap, Mat_Remap_X_R, Mat_Remap_Y_R, cv::INTER_LINEAR);
		}
		else
		{
			img1remap = img1proc;
			img2remap = img2proc;
		}

		// ��������ͼ����߽��б߽����أ��Ի�ȡ��ԭʼ��ͼ��ͬ��С����Ч�Ӳ�����
		cv::Mat img1border, img2border;
		if (numberOfDisparies != BM.state->numberOfDisparities)
			numberOfDisparies = BM.state->numberOfDisparities;
		copyMakeBorder(img1remap, img1border, 0, 0, BM.state->numberOfDisparities, 0, IPL_BORDER_REPLICATE);
		copyMakeBorder(img2remap, img2border, 0, 0, BM.state->numberOfDisparities, 0, IPL_BORDER_REPLICATE);

		// �����Ӳ�
		cv::Mat dispBorder;
		BM(img1border, img2border, dispBorder);

		// ��ȡ��ԭʼ�����Ӧ���Ӳ�������ȥ�ӿ�Ĳ��֣�
		cv::Mat disp_tmp;
		disp_tmp = dispBorder.colRange(BM.state->numberOfDisparities, img1border.cols);
		disp_tmp.copyTo(disp, Mat_Mask_Roi);

		// ���������ͼ��
		if (data_Loaded)
		{
			remap(frameLeft, imageLeft, Mat_Remap_X_L, Mat_Remap_Y_L, cv::INTER_LINEAR);
			rectangle(imageLeft, Roi_L, CV_RGB(0, 0, 255), 3);
		}
		else
			frameLeft.copyTo(imageLeft);

		if (data_Loaded)
		{
			remap(frameRight, imageRight, Mat_Remap_X_R, Mat_Remap_Y_R, cv::INTER_LINEAR);
			rectangle(imageRight, Roi_R, CV_RGB(0, 0, 255), 3);
		}
		else
			frameRight.copyTo(imageRight);

		for (int i = 0; i < imageLeft.rows / 20; i++)
		{
			line(imageLeft, Point(0, i * 20), Point(imageLeft.cols, i * 20), CV_RGB(0, 255, 0), 2);
			line(imageRight, Point(0, i * 20), Point(imageRight.cols, i * 20), CV_RGB(0, 255, 0), 2);
		}

	}
	else if (m_nID_RADIO == IDC_RADIO_SGBM)
	{
		SGBM.minDisparity = m_nMinDisp;
		SGBM.numberOfDisparities = m_nNumDisp;
		SGBM.SADWindowSize = m_nSADWinSiz;
		SGBM.disp12MaxDiff = m_nDisp12MaxDiff;
		SGBM.preFilterCap = m_nPreFiltCap;
		SGBM.uniquenessRatio = m_nUniqRatio;
		SGBM.speckleRange = m_nSpeckRange;
		SGBM.speckleWindowSize = m_nSpeckWinSiz;
		SGBM.P1 = 8 * 3 * SGBM.SADWindowSize * SGBM.SADWindowSize;
		SGBM.P2 = 32 * 3 * SGBM.SADWindowSize * SGBM.SADWindowSize;
		if (BST_CHECKED == IsDlgButtonChecked(IDC_CHK_ModeHH))// ��ѡ
			SGBM.fullDP = true;
		else
			SGBM.fullDP = false;

		// ����ͼ��
		cv::Mat img1proc, img2proc;
		frameLeft.copyTo(img1proc);
		frameRight.copyTo(img2proc);

		// У��ͼ��ʹ������ͼ�ж���	
		cv::Mat img1remap, img2remap;
		if (data_Loaded)
		{
			// �������Ӳ����Ļ������У��
			remap(img1proc, img1remap, Mat_Remap_X_L, Mat_Remap_Y_L, cv::INTER_LINEAR);
			remap(img2proc, img2remap, Mat_Remap_X_R, Mat_Remap_Y_R, cv::INTER_LINEAR);
		}
		else
		{
			img1remap = img1proc;
			img2remap = img2proc;
		}

		// ��������ͼ����߽��б߽����أ��Ի�ȡ��ԭʼ��ͼ��ͬ��С����Ч�Ӳ�����
		cv::Mat img1border, img2border;
		if (numberOfDisparies != SGBM.numberOfDisparities)
			numberOfDisparies = SGBM.numberOfDisparities;
		copyMakeBorder(img1remap, img1border, 0, 0, SGBM.numberOfDisparities, 0, IPL_BORDER_REPLICATE);
		copyMakeBorder(img2remap, img2border, 0, 0, SGBM.numberOfDisparities, 0, IPL_BORDER_REPLICATE);

		// �����Ӳ�
		cv::Mat dispBorder;
		SGBM(img1border, img2border, dispBorder);

		// ��ȡ��ԭʼ�����Ӧ���Ӳ�������ȥ�ӿ�Ĳ��֣�
		cv::Mat disp_tmp;
		disp_tmp = dispBorder.colRange(SGBM.numberOfDisparities, img1border.cols);
		disp_tmp.copyTo(disp, Mat_Mask_Roi);

		// ���������ͼ��
		imageLeft = img1remap.clone();
		imageRight = img2remap.clone();

		rectangle(imageLeft, Roi_L, CV_RGB(0, 255, 0), 3);
		rectangle(imageRight, Roi_R, CV_RGB(0, 255, 0), 3);

		for (int i = 0; i < imageLeft.rows / 20; i++)
		{
			line(imageLeft, Point(0, i * 20), Point(imageLeft.cols, i * 20), CV_RGB(0, 0, 255), 2);
			line(imageRight, Point(0, i * 20), Point(imageRight.cols, i * 20), CV_RGB(0, 0, 255), 2);
		}
	}
}

void CbinocularMeasureDSMFCDlg::OnEnChangeEditShow()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CbinocularMeasureDSMFCDlg::OnEnChangeEditspeckrange()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CbinocularMeasureDSMFCDlg::OnStnClickedPicRight()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CbinocularMeasureDSMFCDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CbinocularMeasureDSMFCDlg::OnEnChangeEditSadwinsize()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CbinocularMeasureDSMFCDlg::OnEnChangeEditspeckwinsize()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
