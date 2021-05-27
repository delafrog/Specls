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



class ClbrWidget : public QWidget // класс для отображения окна калибровки
{
	//QObject;
	Q_OBJECT
public:
	ClbrWidget(QWidget *parent = 0);
	~ClbrWidget(){ };//if (picdata!= 0x0) delete [] picdata;};

	void setCalibrData(vec4FMushort *Dat,int y1,int y2); // функция загрузки данных для проведения калибровки
	
public	slots:

	void addPeakData(); // добавить данные для выбранного пика  
	void setRed() { chanel_id = 0; }
	void setGreen1() { chanel_id = 1; }
	void setGreen2() { chanel_id = 2; }
	void setBlue() { chanel_id = 3; }
	void setLor() { aprxtype = 1; }
	void setGauss() { aprxtype = 0; }
	//void cpur() { emit clbr_pic_udt_req(); }
/*	void SetGaussApproxFun(); // установка аппроксимирующей функции и её производных  f(x) = A*exp(-((x-B)/C)^2)+d*x+E  

	void ErrFun();  // функция ошибки
	void GradFun(); // градиент функции ошибки
	void HessFun(); // матрица вторых производных функции ошибки

	void dataNormalize();
	void Approx(); // */
signals:
	void clbr_pic_udp_req();
	
private:

	//PicView *clbr_pic; // отображение "узкой" картинки с изображением спектра
	//PlotGraph *clbr_grf; // график спектра взятый по центральной строке изображения, либо суммарный - после обработки

//	PlotGraph *clbr_tbl; // график калибровки: длина волны от номера пикселя (для центральной строки)
	int pxspln; // длина спектра в пикселях - для отображения картинки и графика
	int pxsphg; // выстоа каринки со спектром
	int dw; // сдвиг для рисования осей графика

	



/*	vecdb Param; // параметры аппроксимации
	vecdb xx;	// аргумент аппроксимирующей функции
	vecdb yy;	// значения аппроксимирующей функции
	vecdb dy;   // 
	vecdb ddy;  // 
	vecdb ff;   // значения экспериметнальных значений

	double k_x, k_y, b_x, b_y; // коэфф. нормализаци данных для  апроксимации
*/
//	double err; // ошибка 
//	vecdb graderr;
//	FullMatrix<double> hesserr;

	
	//vecT<>


//	approxFun Fun;
//	vecT<diffFun> gradFun;
//	FullMatrix<ddFun> hessFun;

	GaussApproximator GssApprx;
//	LorentsApproximator LorApprx;

	QGroupBox *groupBox, *groupBox2;
	QRadioButton *red, *green1, *green2, *blue; // кнопки для выбора канала 
	int chanel_id; // номер канала

	QRadioButton *gauss, *lorents; // кнопки для выбора типа аппроскимации
	int aprxtype; // тип аппроксимирующей функции 0 - гаусс, 1 - лоренц

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
class ClbrTableData // класс данных калибровочной таблицы
{
public:
	ClbrTableData();//QObject *parent = 0);
	ClbrTableData(const ClbrTableData &other);
	~ClbrTableData();

	//ClbrTableData & operator = (const IIMData& other);

	

};
/*
class Calibrator // класс для проведения расчётов калибровки
{
//	QObject;
public:
	Calibrator();
	~Calibrator(){};
private:

	VecT<FullMatrix<double>> ClbrTables; // данные калибровочных таблиц


};*/



#endif