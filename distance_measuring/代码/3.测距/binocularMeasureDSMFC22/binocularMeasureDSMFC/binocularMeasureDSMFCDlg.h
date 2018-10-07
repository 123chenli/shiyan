// binocularMeasureDSMFCDlg.h : 头文件
//

#pragma once

#include "stdlib.h"
#include <vector>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <io.h>
#include <direct.h>

#include "CV_picture.h" 
#include "CvvImage.h"
#include "camerads.h"

using namespace cv;
using namespace std;

#include "afxwin.h"


// CbinocularMeasureDSMFCDlg 对话框
class CbinocularMeasureDSMFCDlg : public CDialogEx
{
// 构造
public:
	CbinocularMeasureDSMFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BINOCULARMEASUREDSMFC_DIALOG };

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
	typedef enum { STEREO_BM, STEREO_SGBM } STEREO_METHOD;
	//typedef enum { SHOW_ORIGINAL_FRAME, SHOW_EDGE_IMAGE } FRAME_PROCESS_METHOD;
	typedef enum { SHOW_ORIGINAL_FRAME, SHOW_EDGE_IMAGE, SHOW_GRAY_FRAME, SHOW_GAUSSIAN_FRAME } FRAME_PROCESS_METHOD;

public:
	CV_picture m_showImg_left;
	CV_picture m_showImg_right;
	CV_picture m_showImg_disparity;
	
	CString m_edit_showDistance;

	CStringA leftFolderPath;
	CStringA rightFolderPath;
	CString parmFolderPath;

	CString m_edit_LeftFolder;
	CString m_edit_RightFolder;
	CString m_edit_ParmFileName;
	
	int m_edit_NumOfImg;
	CEdit m_ctrl_edit_showDistance;
	CEdit m_ctrl_edit_show;

	afx_msg void OnBnClickedBtnExecute();
	afx_msg void OnBnClickedBtnSelectleftfolder();
	afx_msg void OnBnClickedBtnSelectrightfolder();
	afx_msg void OnBnClickedBtnSelectparmfolder();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnCbnSelchangeComboCamlistL();
	afx_msg void OnCbnSelchangeComboCamlistR();
	CComboBox m_COMBO_CamList_L;
	CComboBox m_COMBO_CamList_R;

	CCameraDS lfCam;
	CCameraDS riCam;
	cv::Mat m_lfImage;
	cv::Mat m_riImage;
	cv::Mat m_disparity;

	int m_lfCamID;
	int m_riCamID;
	vector <Mat> m_lf_imgs;
	vector <Mat> m_ri_imgs;
	int m_nCamCount;
	int m_nImageWidth;
	int m_nImageHeight;

	int m_ProcMethod;

	void DoShowOrigFrame();
	void DoFrameProc(Mat& src, Mat& dst);
	
	afx_msg void OnBnClickedBtnOpencam();
	afx_msg void OnBnClickedBtnClosecam();
	afx_msg void OnBnClickedBtnSnapshot();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeComboMethodlist();
	afx_msg void OnBnClickedBtnDefaultcamcalibparam();
	afx_msg void OnBnClickedBtnCalib();
	afx_msg void OnBnClickedBtnReadcalibparm();
	afx_msg void OnBnClickedBtnRectify();
	afx_msg void OnBnClickedBtnDefaultstereoparm();
	afx_msg void OnBnClickedBtnReadimg();
	afx_msg void OnBnClickedRadioBm();
	afx_msg void OnBnClickedRadioSgbm();

	CComboBox m_COMBO_MethodList;
	CButton* m_pCheck;

	CString m_workDir;
	CString F_InitWorkDir();
	bool F_CheckDir(const string dir, bool creatDir /* = false */);
	CString selectFolder(void);
	vector<CStringA> DoSelectFiles(LPCTSTR	lpszDefExt, DWORD	dwFlags, LPCTSTR	lpszFilter, LPCWSTR	lpstrTitle, LPCWSTR	lpstrInitialDir);
	int getDisparityImage(cv::Mat& disparity, cv::Mat& disparityImage, bool isColor);
	void doMatch(Mat frameLeft, Mat frameRight, Mat &disp, Mat &imageLeft, Mat &imageRight);

	int m_nBoardSize_X;
	int m_nBoardSize_Y;
	float m_nSquareSize;
	int m_nDelayTime;
	int m_nMinDisp;
	int m_nPreFiltCap;
	int m_nNumDisp;
	int m_nSADWinSiz;
	int m_nTextThres;
	int m_nDisp12MaxDiff;
	int m_nUniqRatio;
	int m_nSpeckRange;
	int m_nSpeckWinSiz;
	BOOL m_bModeHH;
	UINT m_nID_RADIO;
	int writeImgindex;

	Size imageSize;
	bool data_Loaded;			// 是否成功载入定标参数
	Mat Mat_Remap_X_L;			// 左视图畸变校正像素坐标映射矩阵 X
	Mat Mat_Remap_Y_L;			// 左视图畸变校正像素坐标映射矩阵 Y
	Mat Mat_Remap_X_R;			// 右视图畸变校正像素坐标映射矩阵 X
	Mat Mat_Remap_Y_R;			// 右视图畸变校正像素坐标映射矩阵 Y
	Mat Mat_Mask_Roi;			// 左视图校正后的有效区域
	Rect Roi_L;					// 左视图校正后的有效区域矩形
	Rect Roi_R;					// 右视图校正后的有效区域矩形
	Mat	pointClouds;			// 点云
	int	numberOfDisparies;		// 视差变化范围
	cv::StereoBM	BM;			// 立体匹配 BM 方法
	cv::StereoSGBM	SGBM;		// 立体匹配 SGBM 方法

	Mat cameraMatrixL = (Mat_<double>(3, 3));
	Mat distCoeffL = (Mat_<double>(5, 1));
	Mat cameraMatrixR = (Mat_<double>(3, 3));
	Mat distCoeffR = (Mat_<double>(5, 1));
	Mat R = (Mat_<double>(3, 3));	// R 旋转矩阵 
	Mat T = (Mat_<double>(3, 1));	// T 平移矢量
	Mat E, F;						// E 本征矩阵 F 基础矩阵
	Mat Mat_Q;						// Q 矩阵
	Mat Rl, Rr, Pl, Pr;				// 校正旋转矩阵 Rl Rr，投影矩阵 Pl Pr

	//默认的图片路径及格式
	char* leftimg_directory = "leftImgs";			// 左摄像头图像路径
	char* rightimg_directory = "rightImgs";			// 右摄像头图像路径
	char* leftimg_filename = "left";				// 左摄像头图像名
	char* rightimg_filename = "right";				// 右摄像头图像名
	char* extension = "jpg";						// 图像格式
	int num_imgs;

	int picIndex;
	bool img_Loaded;				// 是否成功载入图片
	bool cam_opened;				// 是否打开摄像头
	bool parm_selected;				//是否选择参数文件

	afx_msg void OnBnClickedRadioDispfromcam();
	afx_msg void OnBnClickedRadioDispfromimg();
	afx_msg void OnEnChangeEditShow();
	afx_msg void OnEnChangeEditspeckrange();
	afx_msg void OnStnClickedPicRight();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditSadwinsize();
	afx_msg void OnEnChangeEditspeckwinsize();
	afx_msg void OnEnChangeEditBoardwidth();
};