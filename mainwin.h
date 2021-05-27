#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QSplitter>
#include <QTabWidget>
#include <QGraphicsView>
#include <QSize>
#include <QMenu>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QVector>
#include <QCloseEvent>
#include <QPaintEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QSlider>
#include <QScrollArea> 
#include <QProgressBar>

#include "ui_gui_.h"
//#include <valarray>
#include "linalg.h"
#include "picview.h"
#include "plotgraph.h"
#include "prevw.h"

#include "colorbox.h"

class MainWin : public QMainWindow
{
	Q_OBJECT
public:
	MainWin();

	Ui::MainWindow *guiWin;

	QTabWidget *tabWidget;

	ListView *lstVw;
	ImageIconModel *iiMdl;
	ImageIconDelegate *iiDlg;


	PicView *pvw;
	PlotGraph *plt1D;

	PicView *pvHist;
	PicView *pvRScl;
	PlotGraph *Hist;
	PlotGraph *LogHist;
	PicView *Cor2D;
	PlotGraph *Corr;
	QPushButton *gcrbt;
	QPushButton *flscrbt; // ������ ������ �������� � ������������� ������
	QPushButton *setcentrbt; // ������ ���������� ������ ���� ��������
	QPushButton *setVln,*setHln; // ������ �������������� � ������������� ������������
	QPushButton *setCM; // ������������� �� ������ ����
	QPushButton *row_sum; // ������������ �� ������� 
	QPushButton *col_sum; // ������������ �� ��������
	PicView *pFllScrn; // ����� ��� �������� ������������ � ������ fullscreen
	//QProgressBar *prgssBar; // progressBar for autocorrelation calculation

	QLineEdit *data_x1,*data_x2,*data_y1,*data_y2,*data_dx,*data_dy;
	QLabel *str_p1,*str_p2,*str_CM_xy,*str_p3;

	QSlider *bright_sldr, *contrast_sldr; // �������� ��� ��������� ������� � ���������

	ColorBox *clrbx;

	void clearAll(); // ������� ������ ����������� - ���� � ������� R,G1,G2,B � �������������� ������ ��� pvw � pvHist

protected:
	void keyPressEvent(QKeyEvent *event);

public slots:
	void openImageFile();
	void getpicslice();
	void getpicslice_(int dd);
	void getpicslice_sum_x();
	void getpicslice_sum_y();
	void getpicsliceAC();
	void gethistdata();
	void gethistdata2();
	void getRScldata(); // ���������� ����� ����������� � ������ �������� 
	void autoCorr(); // ���������� ��������������
	void showFullScrn(); // �������� ���������� �������� �� ������ �����
	void setcrd_1(); // ��������� ������ ��������� ��� ������� "�����������"
	void updcrd_1();
	void hrznalgm();// �������������� ������������
	void vrtcalgm();// ������������ ������������
	void cntposCM();// ������������� ���������
	void SaveBinFile();
	void newpicgen1(); // ������������� ����� ��������
	void newpicgen2(); // ������������� ����� ��������
	void newpicgen3(); // ������������� ����� ��������


	void SaveFile(const QModelIndex & index); // ���������� ����� (������������ ��� ������ ����� ����������� ����)
	//void SaveBinFile(); // ���������� ����� � �������� ���� (4 �����)

	void updatepic(const QModelIndex & index);
	void type_change(const QModelIndex & index,const QModelIndex & index1);

	void DelSpectr(const QModelIndex & index); // �������� ������� �� ��� �������

	void AboutMsg();
	void AboutQtMsg();
	
protected:
private:

	void setFlScrPic(); //��������� �������� ��� �������������� �����������

	bool okToContinue();
	void setCurrentFile(const QString &fileName);
	
	void loadbin();
	void savebin(FullMatrix<unsigned short> &R,FullMatrix<unsigned short> &G1,FullMatrix<unsigned short> &G2,FullMatrix<unsigned short> &B,const QString &fileName);


	void addImage(FullMatrix<unsigned short> &R,FullMatrix<unsigned short> &G1,FullMatrix<unsigned short> &G2,FullMatrix<unsigned short> &B); // �������� ������ � ������ ������ � �������
	vecT< vec4FMushort > Img_datas; // ������ ������ � ������� � ����������� ������� 
	int actual_pic_id; // ����� ���������� �������

	vecdb lhlpvr; // ��������������� ������
	
	//std::valarray<unsigned short> R,G1,G2,B;
	FullMatrix<unsigned short> R,G1,G2,B,G3;
	FullMatrix<double> AC; // ������� ��������������

	int acnx,acny; 


	//QStringList recentFiles;
	QString curFile;
	QString curDir;



	QAction *actionOpenImage;

	QAction *actionSaveBin;

	QAction *actionExit;



	QScrollArea  *scrollArea_RScl;
	
};


#endif 