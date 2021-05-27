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
	QPushButton *flscrbt; // кнопка показа картинки в полноэкранном режиме
	QPushButton *setcentrbt; // кнопка вычислени€ центра масс картинки
	QPushButton *setVln,*setHln; // кнопки горизонального и вертикального выравнивани€
	QPushButton *setCM; // центрирование по центру масс
	QPushButton *row_sum; // суммирование по строкам 
	QPushButton *col_sum; // суммирование по столбцам
	PicView *pFllScrn; // буфер дл€ картинки отображаемой в режиме fullscreen
	//QProgressBar *prgssBar; // progressBar for autocorrelation calculation

	QLineEdit *data_x1,*data_x2,*data_y1,*data_y2,*data_dx,*data_dy;
	QLabel *str_p1,*str_p2,*str_CM_xy,*str_p3;

	QSlider *bright_sldr, *contrast_sldr; // ползунки дл€ установки €ркости и контраста

	ColorBox *clrbx;

	void clearAll(); // очистка данных изображени€ - нули в матрицы R,G1,G2,B и соответсвующие вызовы дл€ pvw и pvHist

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
	void getRScldata(); // построение части изображени€ в полном масштабе 
	void autoCorr(); // вычисление автокоррел€ции
	void showFullScrn(); // показать выделенную катринку на полный экран
	void setcrd_1(); // установка данных координат дл€ раздела "»ндикатриса"
	void updcrd_1();
	void hrznalgm();// горизонтальное выравнивание
	void vrtcalgm();// вертикальное выравнивание
	void cntposCM();// центрирование положени€
	void SaveBinFile();
	void newpicgen1(); // генерирование новой картинки
	void newpicgen2(); // генерирование новой картинки
	void newpicgen3(); // генерирование новой картинки


	void SaveFile(const QModelIndex & index); // сохранение файла (используетс€ при вызаве через контекстное меню)
	//void SaveBinFile(); // сохранение файла в бинарном виде (4 файла)

	void updatepic(const QModelIndex & index);
	void type_change(const QModelIndex & index,const QModelIndex & index1);

	void DelSpectr(const QModelIndex & index); // удаление спектра по его индексу

	void AboutMsg();
	void AboutQtMsg();
	
protected:
private:

	void setFlScrPic(); //заполнить картинку дл€ полноэкранного отображени€

	bool okToContinue();
	void setCurrentFile(const QString &fileName);
	
	void loadbin();
	void savebin(FullMatrix<unsigned short> &R,FullMatrix<unsigned short> &G1,FullMatrix<unsigned short> &G2,FullMatrix<unsigned short> &B,const QString &fileName);


	void addImage(FullMatrix<unsigned short> &R,FullMatrix<unsigned short> &G1,FullMatrix<unsigned short> &G2,FullMatrix<unsigned short> &B); // добавить снимок в массив данных о снимках
	vecT< vec4FMushort > Img_datas; // массив матриц с данными о загруженных снимках 
	int actual_pic_id; // номер акуального спектра

	vecdb lhlpvr; // вспомогательный массив
	
	//std::valarray<unsigned short> R,G1,G2,B;
	FullMatrix<unsigned short> R,G1,G2,B,G3;
	FullMatrix<double> AC; // матрица автокоррел€ции

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