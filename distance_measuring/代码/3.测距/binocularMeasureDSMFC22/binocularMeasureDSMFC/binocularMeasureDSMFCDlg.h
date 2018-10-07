// binocularMeasureDSMFCDlg.h : ͷ�ļ�
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


// CbinocularMeasureDSMFCDlg �Ի���
class CbinocularMeasureDSMFCDlg : public CDialogEx
{
// ����
public:
	CbinocularMeasureDSMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BINOCULARMEASUREDSMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	bool data_Loaded;			// �Ƿ�ɹ����붨�����
	Mat Mat_Remap_X_L;			// ����ͼ����У����������ӳ����� X
	Mat Mat_Remap_Y_L;			// ����ͼ����У����������ӳ����� Y
	Mat Mat_Remap_X_R;			// ����ͼ����У����������ӳ����� X
	Mat Mat_Remap_Y_R;			// ����ͼ����У����������ӳ����� Y
	Mat Mat_Mask_Roi;			// ����ͼУ�������Ч����
	Rect Roi_L;					// ����ͼУ�������Ч�������
	Rect Roi_R;					// ����ͼУ�������Ч�������
	Mat	pointClouds;			// ����
	int	numberOfDisparies;		// �Ӳ�仯��Χ
	cv::StereoBM	BM;			// ����ƥ�� BM ����
	cv::StereoSGBM	SGBM;		// ����ƥ�� SGBM ����

	Mat cameraMatrixL = (Mat_<double>(3, 3));
	Mat distCoeffL = (Mat_<double>(5, 1));
	Mat cameraMatrixR = (Mat_<double>(3, 3));
	Mat distCoeffR = (Mat_<double>(5, 1));
	Mat R = (Mat_<double>(3, 3));	// R ��ת���� 
	Mat T = (Mat_<double>(3, 1));	// T ƽ��ʸ��
	Mat E, F;						// E �������� F ��������
	Mat Mat_Q;						// Q ����
	Mat Rl, Rr, Pl, Pr;				// У����ת���� Rl Rr��ͶӰ���� Pl Pr

	//Ĭ�ϵ�ͼƬ·������ʽ
	char* leftimg_directory = "leftImgs";			// ������ͷͼ��·��
	char* rightimg_directory = "rightImgs";			// ������ͷͼ��·��
	char* leftimg_filename = "left";				// ������ͷͼ����
	char* rightimg_filename = "right";				// ������ͷͼ����
	char* extension = "jpg";						// ͼ���ʽ
	int num_imgs;

	int picIndex;
	bool img_Loaded;				// �Ƿ�ɹ�����ͼƬ
	bool cam_opened;				// �Ƿ������ͷ
	bool parm_selected;				//�Ƿ�ѡ������ļ�

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