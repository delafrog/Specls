#ifndef APROXIMATION_H
#define APROXIMATION_H


#include <QWidget>
#include <QPaintEvent>
#include <QRadioButton>
#include <QGroupBox>
#include <QTableWidget>

#include "picview.h"
#include "plotgraph.h"
#include "linalg.h"
#include "gaussapprox.h"
//#include "lorentsapprox.h"



class ClbrWidget : public QWidget // ����� ��� ����������� ���� ����������
{
	//QObject;
	Q_OBJECT
public:
	ClbrWidget(QWidget *parent = 0);
	~ClbrWidget(){ };//if (picdata!= 0x0) delete [] picdata;};

	void setCalibrData(vec4FMushort *Dat,int y1,int y2); // ������� �������� ������ ��� ���������� ����������
	
public	slots:

	void addPeakData(); // �������� ������ ��� ���������� ����  
	void setRed() { chanel_id = 0; }
	void setGreen1() { chanel_id = 1; }
	void setGreen2() { chanel_id = 2; }
	void setBlue() { chanel_id = 3; }
	void setLor() { aprxtype = 1; }
	void setGauss() { aprxtype = 0; }
	//void cpur() { emit clbr_pic_udt_req(); }
/*	void SetGaussApproxFun(); // ��������� ���������������� ������� � � �����������  f(x) = A*exp(-((x-B)/C)^2)+d*x+E  

	void ErrFun();  // ������� ������
	void GradFun(); // �������� ������� ������
	void HessFun(); // ������� ������ ����������� ������� ������

	void dataNormalize();
	void Approx(); // */
signals:
	void clbr_pic_udp_req();
	
private:

	//PicView *clbr_pic; // ����������� "�����" �������� � ������������ �������
	//PlotGraph *clbr_grf; // ������ ������� ������ �� ����������� ������ �����������, ���� ��������� - ����� ���������

//	PlotGraph *clbr_tbl; // ������ ����������: ����� ����� �� ������ ������� (��� ����������� ������)
	int pxspln; // ����� ������� � �������� - ��� ����������� �������� � �������
	int pxsphg; // ������ ������� �� ��������
	int dw; // ����� ��� ��������� ���� �������

	



/*	vecdb Param; // ��������� �������������
	vecdb xx;	// �������� ���������������� �������
	vecdb yy;	// �������� ���������������� �������
	vecdb dy;   // 
	vecdb ddy;  // 
	vecdb ff;   // �������� ����������������� ��������

	double k_x, k_y, b_x, b_y; // �����. ����������� ������ ���  ������������
*/
//	double err; // ������ 
//	vecdb graderr;
//	FullMatrix<double> hesserr;

	
	//vecT<>


//	approxFun Fun;
//	vecT<diffFun> gradFun;
//	FullMatrix<ddFun> hessFun;

	GaussApproximator GssApprx;
//	LorentsApproximator LorApprx;

	QGroupBox *groupBox, *groupBox2;
	QRadioButton *red, *green1, *green2, *blue; // ������ ��� ������ ������ 
	int chanel_id; // ����� ������

	QRadioButton *gauss, *lorents; // ������ ��� ������ ���� �������������
	int aprxtype; // ��� ���������������� ������� 0 - �����, 1 - ������

//	QLabel *yfuntext;//
	QLabel *formula;

	QLabel *fiterrtxt;
	QLabel *fiterrdata;

	QTableWidget *fitParTbl;

	QTableWidgetItem *fP_A, *fP_sgA;
	QTableWidgetItem *fP_B, *fP_sgB;
	QTableWidgetItem *fP_C, *fP_sgC;
	QTableWidgetItem *fP_D, *fP_sgD;
	QTableWidgetItem *fP_E, *fP_sgE;

protected :
	//void paintEvent(QPaintEvent *event);

};
/*
class ClbrTableData // ����� ������ ������������� �������
{
public:
	ClbrTableData();//QObject *parent = 0);
	ClbrTableData(const ClbrTableData &other);
	~ClbrTableData();

	//ClbrTableData & operator = (const IIMData& other);

	

};
/*
class Calibrator // ����� ��� ���������� �������� ����������
{
//	QObject;
public:
	Calibrator();
	~Calibrator(){};
private:

	VecT<FullMatrix<double>> ClbrTables; // ������ ������������� ������


};*/



#endif