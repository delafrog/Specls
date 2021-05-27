#ifndef MAINWIN_CPP
#define MAINWIN_CPP

#include "ui_gui_.h"
#include "mainwin.h"
#include "linalg.cpp"
#include "picview.h"
#include "plotgraph.h"
#include <QPaintEvent>
#include <QPushButton>
#include <QHBoxLayout>

MainWin::MainWin()
{
	//Ui::MainWindow *guiWin;
	guiWin = new Ui::MainWindow;

	guiWin->setupUi(this);
	
	actionOpenImage	= guiWin->actionOpen_Image_Data_File;
	actionOpenImage->setStatusTip(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 *.cr2 \321\204\320\260\320\271\320\273", 0));//tr("Load *.cr2 raw file"));
	connect(actionOpenImage,SIGNAL(triggered()), this, SLOT(openImageFile()));

	actionExit		= guiWin->actionExit;

	actionSaveBin	= guiWin->actionSave_Binary_Data;
	actionSaveBin->setStatusTip(QApplication::translate("MainWindow", "\xD0\xA1\xD0\xBE\xD1\x85\xD1\x80\xD0\xB0\xD0\xBD\xD0\xB8\xD1\x82\xD1\x8C\x20\xD0\xB4\xD0\xB0\xD0\xBD\xD0\xBD\xD1\x8B\xD0\xB5\x20\xD0\xB2\x20\xD0\xB1\xD0\xB8\xD0\xBD\xD0\xB0\xD1\x80\xD0\xBD\xD0\xBE\xD0\xBC\x20\xD0\xB2\xD0\xB8\xD0\xB4\xD0\xB5\x0A", 0));//tr("Load *.cr2 raw file"));
	connect(actionSaveBin,SIGNAL(triggered()), this, SLOT(SaveBinFile()));



	tabWidget = new QTabWidget;

	tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
	tabWidget->setEnabled(true);

	tabWidget->setTabPosition(QTabWidget::North);
	tabWidget->setTabShape(QTabWidget::Rounded);
	tabWidget->setElideMode(Qt::ElideNone);
	tabWidget->setUsesScrollButtons(false);
	tabWidget->setDocumentMode(false);
	tabWidget->setTabsClosable(false);
	tabWidget->setMovable(true);

	iiMdl = new ImageIconModel(this);

	lstVw = new ListView(this);
	lstVw->setViewMode(QListView::IconMode);
	lstVw->setWrapping(true);
	lstVw->setFlow(QListView::LeftToRight);
	lstVw->setSpacing(5);
	//lstVw->setGridSize(QSize(330,300));
	lstVw->setResizeMode(QListView::Adjust);
	lstVw->setModel(iiMdl);

	iiDlg = new ImageIconDelegate();

	lstVw->setItemDelegate(iiDlg);

	tabWidget->addTab(lstVw,QString(QApplication::translate("MainWindow", "\xD0\x97\xD0\xB0\xD0\xB3\xD1\x80\xD1\x83\xD0\xB6\xD0\xB5\xD0\xBD\xD0\xBD\xD1\x8B\xD0\xB5\x20\xD1\x84\xD0\xB0\xD0\xB9\xD0\xBB\xD1\x8B", 0 )));

	pvw = new PicView;
	pFllScrn = new PicView;
	//tabWidget->addTab(pvw,QString());
	//tabWidget->addTab();

	plt1D = new PlotGraph();

	plt1D->setNgrphx(4); // установка количества графиков - 4 красный, зелёный, синий, зелёный

	setHln = new QPushButton(QString(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \320\262\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265", 0 )));
	setVln = new QPushButton(QString(QApplication::translate("MainWindow", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\265 \320\262\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265", 0 )));
	setCM  = new QPushButton(QString(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0 )));; // центрирование по центру масс

	row_sum = new QPushButton(QString(QApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265  \320\277\320\276  \321\201\321\202\321\200\320\276\320\272\320\260\320\274", 0 )));; // суммирование по строкам
	col_sum = new QPushButton(QString(QApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\260\320\274", 0 )));; // суммирование по столбцам

	QWidget *wdg;
	wdg = new QWidget();
	
	QHBoxLayout * hbox1,*hbox2,*hbox3,*hbox4;
	QVBoxLayout * vbox1;

	hbox1 = new QHBoxLayout();
	hbox2 = new QHBoxLayout();
	hbox3 = new QHBoxLayout();
	hbox4 = new QHBoxLayout();
	vbox1 = new QVBoxLayout();

	str_p1 = new QLabel(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 (x1,y1) \321\202\320\276\321\207\320\272\320\270 \342\204\2261 :", 0 ));
	str_p2 = new QLabel(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 (x2,y2) \321\202\320\276\321\207\320\272\320\270 \342\204\2262 :", 0 ));
	str_CM_xy = new QLabel(QApplication::translate("MainWindow", "(xc,yc) : ", 0 ));
	str_p3 = new QLabel(QApplication::translate("MainWindow", "| (Dx,Dy): ", 0 ));

	data_x1 = new QLineEdit();
	data_x1->setMaxLength(4);
	data_x1->setMaximumWidth(30);
	data_y1 = new QLineEdit();
	data_y1->setMaxLength(4);
	data_y1->setMaximumWidth(30);

	data_x2 = new QLineEdit();
	data_x2->setMaxLength(4);
	data_x2->setMaximumWidth(30);
	data_y2 = new QLineEdit();
	data_y2->setMaxLength(4);
	data_y2->setMaximumWidth(30);
	data_dx = new QLineEdit();
	data_dx->setMaxLength(4);
	data_dx->setMaximumWidth(30);
	data_dx->setReadOnly(true);
	data_dy = new QLineEdit();
	data_dy->setMaxLength(4);
	data_dy->setMaximumWidth(30);
	data_dy->setReadOnly(true);

	//data_x1->setInputMask(QString("9999"));
	
	hbox1->addWidget(str_p1);
	hbox1->addWidget(data_x1);
	hbox1->addWidget(data_y1);
	hbox1->addWidget(setVln);
	hbox1->addWidget(setHln);
	hbox1->addStretch();
	
	hbox2->addWidget(str_p2);
	hbox2->addWidget(data_x2);
	hbox2->addWidget(data_y2);
	hbox2->addWidget(setCM);
	hbox2->addWidget(str_CM_xy);
	hbox2->addWidget(str_p3);
	hbox2->addWidget(data_dx);
	hbox2->addWidget(data_dy);
	hbox2->addStretch();
	hbox3->addWidget(row_sum);
	hbox3->addStretch();
	hbox4->addWidget(col_sum);
	hbox4->addStretch();
	
	vbox1->addLayout(hbox1);
	vbox1->addLayout(hbox2);
	vbox1->addLayout(hbox3);
	vbox1->addLayout(hbox4);
	vbox1->addStretch();


	wdg->setLayout(vbox1);



	QSplitter *V_split;
	V_split = new QSplitter();
	V_split->setOrientation(Qt::Horizontal); 
	V_split->addWidget(pvw);
	V_split->addWidget(wdg);
	V_split->setStretchFactor(1,1);
	

	QSplitter *H_split;
	H_split = new QSplitter();
	H_split->setOrientation(Qt::Vertical);
	//H_split->setObjectName(QString::fromUtf8());


	H_split->addWidget(V_split);
	H_split->addWidget(plt1D);
	H_split->setStretchFactor(1,1);

	tabWidget->addTab(H_split,QString(QApplication::translate("MainWindow", "\320\230\320\275\320\264\320\270\320\272\320\260\321\202\321\200\320\270\321\201\320\260", 0 ))); // tr("I(x,y)")

	pvHist = new PicView;
	//tabWidget->addTab(pvw,QString());
	//tabWidget->addTab();
	pvHist->setpnts(0.1,0.1,0.9,0.9);
	pvHist->settype(1);

	pvRScl = new PicView;
	pvRScl->setpnts(0.0, 0.0, 0.0, 0.0);
	pvRScl->setPixelScale(1);
	pvRScl->settype(0);

	scrollArea_RScl = new QScrollArea(this);
	scrollArea_RScl->setWidget(pvRScl);

	Hist	= new PlotGraph;
	LogHist = new PlotGraph;
	Hist->setNgrphx(4);
	LogHist->setNgrphx(4);


	QWidget *wdg1;
	wdg1 = new QWidget();
	flscrbt = new QPushButton(QString(QApplication::translate("MainWindow", "\xD0\x9F\xD0\xBE\xD0\xBB\xD0\xBD\xD0\xBE\xD1\x8D\xD0\xBA\xD1\x80\xD0\xB0\xD0\xBD\xD0\xBD\xD1\x8B\xD0\xB9\x20\xD1\x80\xD0\xB5\xD0\xB6\xD0\xB8\xD0\xBC", 0 )),wdg1); // tr("Calc AutoCorrelation")
	setcentrbt = new QPushButton(QString(QApplication::translate("MainWindow", "\xD0\xA6\xD0\xB5\xD0\xBD\xD1\x82\xD1\x80\x20\xD1\x80\xD0\xB0\xD1\x81\xD0\xBF\xD1\x80\xD0\xB5\xD0\xB4\xD0\xB5\xD0\xBB\xD0\xB5\xD0\xBD\xD0\xB8\xD1\x8F", 0 ))); // tr("Calc AutoCorrelation")
	//wdg1->insest

	/*QSplitter *V_split01;
	V_split01 = new QSplitter();
	V_split01->setOrientation(Qt::Vertical);
	V_split01->addWidget(pvHist);
	V_split01->addWidget(wdg1);
	//V_split1->addWidget(wdg4);
	//V_split01->setStretchFactor(1, 1);*/

	QSplitter *V_split1;
	V_split1 = new QSplitter();
	V_split1->setOrientation(Qt::Vertical); 
	//V_split1->addWidget(V_split01);
	V_split1->addWidget(pvHist);
	V_split1->addWidget(scrollArea_RScl);
	//V_split1->addWidget(wdg4);
	//V_split1->setStretchFactor(1,1);


	QSplitter *H_split1;
	H_split1 = new QSplitter();
	H_split1->setOrientation(Qt::Horizontal);
	//H_split->setObjectName(QString::fromUtf8());


	QSplitter *V_split3;
	V_split3 = new QSplitter();
	V_split3->setOrientation(Qt::Vertical);
	V_split3->addWidget(Hist);
	V_split3->addWidget(LogHist);

	H_split1->addWidget(V_split1);
	H_split1->addWidget(V_split3);
	H_split1->setStretchFactor(1,1);


	tabWidget->addTab(H_split1,QString(QApplication::translate("MainWindow", "\320\223\320\270\321\201\321\202\320\276\320\263\321\200\320\260\320\274\320\274\320\260", 0 ))); // tr("Histogram dN(I)")


	Corr	= new PlotGraph;
	Corr->setNgrphx(1);
	Cor2D	= new PicView;
	Cor2D->setpnts(0.1,0.1,0.1,0.15);

	QWidget *wdg2;
	wdg2 = new QWidget();

	
	gcrbt = new QPushButton(QString(QApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \321\204\321\203\320\275\320\272\321\206\320\270\321\216 \320\260\320\262\321\202\320\276\320\272\320\276\321\200\321\200\320\265\320\273\321\217\321\206\320\270\320\270", 0 )),wdg2); // tr("Calc AutoCorrelation")
	//gcrbt->

	QSplitter *V_split2;
	V_split2 = new QSplitter();
	V_split2->setOrientation(Qt::Vertical); 
	V_split2->addWidget(Cor2D);
	V_split2->addWidget(wdg2);
	V_split2->setStretchFactor(1,1);
	

	QSplitter *H_split2;
	H_split2 = new QSplitter();
	H_split2->setOrientation(Qt::Horizontal);
	//H_split->setObjectName(QString::fromUtf8());


	H_split2->addWidget(V_split2);
	H_split2->addWidget(Corr);
	H_split2->setStretchFactor(1,1);


	acnx = 400;
	acny = 10;

	tabWidget->addTab(H_split2,QString(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\272\320\276\321\200\321\200\320\265\320\273\321\217\321\206\320\270\321\217", 0 ))); // tr("Correlation")

	setCentralWidget(tabWidget);

	plt1D->xlabel(QString(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\262 \320\277\320\273\320\276\321\201\320\272\320\276\321\201\321\202\320\270 (x,y) [\320\277\320\270\321\201\320\272\320\265\320\273\320\270]", 0 )));//tr("(x,y) displacment "));
	plt1D->ylabel(QString(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 [\320\276\321\202\320\275. \320\265\320\264.]", 0 )));//tr("Int. a.u."));
	plt1D->setTcsTpx(1);
	plt1D->setTcsTpy(1);

	LogHist->xlabel(QString(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 [\320\261\320\270\321\202]", 0 )));//tr("Intencity [Counts]"));
	LogHist->ylabel(QString(QApplication::translate("MainWindow", "ln(\321\207\320\270\321\201\320\273\320\276 \320\277\320\270\320\272\321\201\320\265\320\273\320\265\320\271 / \320\261\320\270\321\202 )/ln(10)", 0 )));//tr("log(Number of pixels)/log(10)"));
	LogHist->setTcsTpx(2);
	LogHist->setTcsTpy(1);

	Hist->xlabel(QString(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 [\320\261\320\270\321\202]", 0 )));//tr("Intencity [Counts]"));
	Hist->ylabel(QString(QApplication::translate("MainWindow", "\321\207\320\270\321\201\320\273\320\276 \320\277\320\270\320\272\321\201\320\265\320\273\320\265\320\271 / \320\261\320\270\321\202", 0 )));//tr("log(Number of pixels)/log(10)"));
	Hist->setTcsTpx(2);
	Hist->setTcsTpy(1);

	Corr->setTcsTpy(1);
	Corr->setTcsTpx(1);
	Corr->xlabel(QString(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\260\320\262\321\202\320\276\320\272\320\276\321\200\321\200\320\265\320\273\321\217\321\206\320\270\320\270 [\320\277\320\270\320\272\321\201\320\265\320\273\320\270]", 0 )));//tr("Numder of pixel"));
	Corr->ylabel(QString(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\260\320\262\321\202\320\276\320\272\320\276\321\200\321\200\320\265\320\273\321\217\321\206\320\270\320\270 ", 0 )));//tr("Correlation function value"));	

	connect(pvw,SIGNAL(recalc()), this, SLOT(getpicslice()));
	connect(pvHist,SIGNAL(recalc()), this, SLOT(gethistdata2()));
	connect(pvHist, SIGNAL(recalc()), this, SLOT(getRScldata()));
	connect(gcrbt,SIGNAL(clicked()),this,SLOT(autoCorr()));
	connect(Cor2D,SIGNAL(recalc()), this, SLOT(getpicsliceAC()));

	connect(flscrbt,SIGNAL(clicked()),this,SLOT(showFullScrn()));

	connect(pvw,SIGNAL(updtcrd()),this,SLOT(setcrd_1()));
	connect(data_x1,SIGNAL(editingFinished()),this,SLOT(updcrd_1()));
	connect(data_y1,SIGNAL(editingFinished()),this,SLOT(updcrd_1()));
	connect(data_x2,SIGNAL(editingFinished()),this,SLOT(updcrd_1()));
	connect(data_y2,SIGNAL(editingFinished()),this,SLOT(updcrd_1()));

	connect(setHln,SIGNAL(clicked()),this,SLOT(hrznalgm()));
	connect(setVln,SIGNAL(clicked()),this,SLOT(vrtcalgm()));
	connect(setCM,SIGNAL(clicked()),this,SLOT(cntposCM()));

	connect(row_sum,SIGNAL(clicked()),this,SLOT(getpicslice_sum_x() ) );
	connect(col_sum,SIGNAL(clicked()),this,SLOT(getpicslice_sum_y() ) );


	connect(lstVw,SIGNAL(clicked(const QModelIndex &)),this,SLOT(updatepic(const QModelIndex &)));
	connect(iiMdl,SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)),this,SLOT(type_change(const QModelIndex &, const QModelIndex &)));

	connect(lstVw, SIGNAL(save(const QModelIndex &)), this, SLOT(SaveFile(const QModelIndex &)));
	connect(lstVw, SIGNAL(del(const QModelIndex &)), this, SLOT(DelSpectr(const QModelIndex &)));

	connect(pvw,SIGNAL(getnewpic()),this,SLOT(newpicgen1()));
	connect(pvHist,SIGNAL(getnewpic()),this,SLOT(newpicgen2()));
	connect(Cor2D,SIGNAL(getnewpic()),this,SLOT(newpicgen3()));
	connect(pFllScrn,SIGNAL(getnewpic()),this,SLOT(showFullScrn()));


	plt1D->tp_mxy = 0;

	IIMData Ldat;
	actual_pic_id = -1;
	loadbin();
	addImage(R,G1,G2,B);
	G3 = G1;
	G3.s += G2.s;
	G3.s /= 2.0;
	pvw->setpicdata(R,G3,B);
	pvHist->setpicdata(R,G3,B);

//unsigned char *loc;
//loc = pvw->getPic().bits();
	Ldat.d->bigIm = pvw->getPic();
	Ldat.d->filename = QString::fromUtf8("\xD0\x98\xD0\xB7\x20\xD1\x84\xD0\xB0\xD0\xB9\xD0\xBB\xD0\xBE\xD0\xB2\xD0\xBE\xD0\xB3\xD0\xBE\x20\xD0\xB1\xD1\x83\xD1\x84\xD0\xB5\xD1\x80\xD0\xB0");//QString("From last binary");
	Ldat.gensmall();
	iiMdl->addImgData(Ldat);
	data_x1->setValidator(new QIntValidator(0,R.nx-1,this));
	data_y1->setValidator(new QIntValidator(0,R.ny-1,this));
	data_x2->setValidator(new QIntValidator(0,R.nx-1,this));
	data_y2->setValidator(new QIntValidator(0,R.ny-1,this));
	setcrd_1();
	lstVw->update();
/**/

	connect(guiWin->actionAbout_Qt5, SIGNAL(triggered()), this, SLOT(AboutQtMsg()));
	connect(guiWin->actionAbout, SIGNAL(triggered()), this, SLOT(AboutMsg()));

}

void MainWin::newpicgen1() // генерирование новой картинки
{
	pvw->setpicdata(R,G1,B);
	update();
}
void MainWin::newpicgen2() // генерирование новой картинки
{
	pvHist->setpicdata(R,G1,B);
	update();
}
void MainWin::newpicgen3() // генерирование новой картинки
{
	Cor2D->setpicdata(AC);
	update();
}


bool MainWin::okToContinue()
{
//	if()
	/*if(isWindowModified())
	{
		int r	= QMessageBox::warning(this,tr("ImProc"), tr("Save the changes?"),
			QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
		if (r==QMessageBox::Yes)
		{
			return save();
		}else
			if (r==QMessageBox::Cancel)
			{
				return false;
			}
	}*/
	return true;
}

void MainWin::openImageFile()
{
	char *fnm;
	QByteArray Qf;
	if(okToContinue())
	{
		QString	fileName	= QFileDialog::getOpenFileName(this,tr("Open Canon Image File"),curDir,tr("Canon raw files (*.cr2)"));
		if(!fileName.isEmpty())
		{	
			IIMData Ldat;
			//loadFile(fileName);
			setCurrentFile(fileName);
			QString	cstr("wdcraw.exe -4 ");
			cstr.append(fileName);
			Qf = cstr.toLatin1();
			fnm = Qf.data();
			//dcraw();
			system(fnm);
			loadbin();
			Ldat.d->filename = QFileInfo(fileName).fileName();
			addImage(R,G1,G2,B);
			G3 = G1;
			G3.s += G2.s;
			G3.s /= 2.0;
			pvw->setpicdata(R,G3,B);
			pvHist->setpicdata(R,G3,B);
			Ldat.d->bigIm = pvw->getPic();
			Ldat.gensmall();
			iiMdl->addImgData(Ldat);
			lstVw->update();	
			data_x1->setValidator(new QIntValidator(0,R.nx-1,this));
			data_y1->setValidator(new QIntValidator(0,R.ny-1,this));
			data_x2->setValidator(new QIntValidator(0,R.nx-1,this));
			data_y2->setValidator(new QIntValidator(0,R.ny-1,this));
		}
	}
}

void MainWin::SaveBinFile()
{
	char *fnm;
	//QByteArray Qf;
	if(okToContinue())
	{
		QString	fileName	= QFileDialog::getSaveFileName(this,tr("Save Binary File"),curDir,tr("Binary Files (*.bin)"));
		if(!fileName.isEmpty())
		{	
			//loadFile(fileName);
			//setCurrentFile(fileName);
			//QString	cstr("wdcraw.exe -4 ");
			//cstr.append(fileName);
			//Qf = cstr.toAscii();
			//fnm = Qf.data();
			//dcraw();
			//system(fnm);
			//loadbin();
			//pvw->setpicdata(R,G1,B);
			//pvHist->setpicdata(R,G1,B);
			savebin(R,G1,G2,B,fileName);
		}
	}
}

void MainWin::setCurrentFile(const QString &fileName)
{
	curFile	= fileName;
	//setWindowModified(false);

	//QString shownName	= "Untitled";
	if(!curFile.isEmpty())
	{
		//shownName	= StrippedName(curFile);
		
		curDir = QFileInfo(fileName).absolutePath();
//		recentFiles.removeAll(curFile);
//		recentFiles.prepend(curFile);
//		updateRecentFileActions();
	}
//	setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Molred")));
}

void MainWin::type_change(const QModelIndex & index,const QModelIndex & index1)
{
	if(index.data().value<IIMData>().d->type == 0)
	{
//		clbr_button->setEnabled(true);
	}else
	{
//		clbr_button->setEnabled(false);
	}
}
void MainWin::updatepic(const QModelIndex & index)
{
	int id;
	if(index.data().value<IIMData>().d->type == 0)
	{
	//	clbr_button->setEnabled(true);
	}else
	{
	//	clbr_button->setEnabled(false);
	}
	id = index.row();
	if (id!= actual_pic_id)
	{
		R = Img_datas.x[id].x[0];
		G1 = Img_datas.x[id].x[1];
		B = Img_datas.x[id].x[2];
		G2 = Img_datas.x[id].x[3];

		G3 = G1;
		G3.s += G2.s;
		G3.s /= 2.0;
		//pvw->setpicdata(R,G3,B);
		//pvHist->setpicdata(R,G3,B);
		pvw->setPic(index.data().value<IIMData>().d->bigIm);
		pvHist->setPic(index.data().value<IIMData>().d->bigIm);
		actual_pic_id = id;
	}
	tabWidget->update();
}

void MainWin::DelSpectr(const QModelIndex & index)
{
	if (index.isValid())
	{
		int id;
		id = index.row();
		for (int ii = id;ii < (Img_datas.N-1);ii++) // цикл сдвигающий указатели на удаляемые матрицы в конец массива
		{
			Img_datas.x[ii].x[0].swp(Img_datas.x[ii + 1].x[0]);
			Img_datas.x[ii].x[1].swp(Img_datas.x[ii + 1].x[1]);
			Img_datas.x[ii].x[2].swp(Img_datas.x[ii + 1].x[2]);
			Img_datas.x[ii].x[3].swp(Img_datas.x[ii + 1].x[3]);
		}
		Img_datas.N--; // просто уменьшаем актуальный размер массива - последние матрицы оказыыются за пределами массива
		iiMdl->delImgData(index); // удаление информации об удаляемом спектре из данных для отображения иконок
		actual_pic_id = -1;

		if (Img_datas.N > 0)
		{
			id = id < Img_datas.N ? id : --id; // смена нового актуального номера спектра. Если удалялся последний спектр, то номер уменьшаем на единицу
			const ImageIconModel *ptr;
			ptr = reinterpret_cast<const ImageIconModel *> (index.model());
			updatepic(ptr->index(id));
		}
		else clearAll();
		
		lstVw->update();
		update();
	}
}
void MainWin::clearAll()
{
	R.s	 = 0;
	G1.s = 0;
	G2.s = 0;
	B.s = 0;
	pvw->setpicdata(R, G1, B);
	pvHist->setpicdata(R,G1,B);
//	clbr_button->setEnabled(false);
}
/*
void MainWin::SaveBinFile()
{
	char *fnm;
	//QByteArray Qf;
	if(okToContinue())
	{
		QString	fileName	= QFileDialog::getSaveFileName(this,tr("Save Binary File"),curDir,tr("Binary Files (*.bin)"));
		if(!fileName.isEmpty())
		{	
			//loadFile(fileName);
			//setCurrentFile(fileName);
			//QString	cstr("wdcraw.exe -4 ");
			//cstr.append(fileName);
			//Qf = cstr.toAscii();
			//fnm = Qf.data();
			//dcraw();
			//system(fnm);
			//loadbin();
			//pvw->setpicdata(R,G1,B);
			//pvHist->setpicdata(R,G1,B);
			savebin(R,G1,G2,B,fileName);
		}
	}
}
*/


void MainWin::SaveFile(const QModelIndex & index)
{
	FullMatrix<unsigned short> R_,G1_,G2_,B_;
	int id;
	char *fnm;
	id = index.row();

	R_ = Img_datas.x[id].x[0];
	G1_ = Img_datas.x[id].x[1];
	B_ = Img_datas.x[id].x[2];
	G2_ = Img_datas.x[id].x[3];

	if (okToContinue())
	{
		QString	fileName = QFileDialog::getSaveFileName(this, tr("Save Binary File"), curDir, tr("Binary Files (*.bin)"));
		if (!fileName.isEmpty())
		{
			savebin(R_, G1_, G2_, B_, fileName);
		}
	}
}


void MainWin::loadbin()
{
	FILE *fid;
	int rh,rw,ii,rh2,rw2,i2,j2,jj,kk;
	unsigned short *raw_image;

	raw_image = 0x0;
	fid = fopen("image.bin","rb");
	if(fid!=NULL)
	{
		fread(&rw,4,1,fid);
		fread(&rh,4,1,fid);
		ii = rw*rh;
		raw_image = new unsigned short [ii];
		fread(raw_image,2,ii,fid);
		fclose(fid);
	}else
	{
		rw = 4800;
		rh = 3200;
		ii = rw*rh;
		raw_image = new unsigned short [ii];
		memset(raw_image,0,ii*sizeof(unsigned short));
	}
		
	rw2 =rw/2;
	rh2 =rh/2;
	//ii /= 4;

	//R.resize(ii);
	//G1.resize(ii);
	//G2.resize(ii);
	//B.resize(ii);

	R.setSize(rh2,rw2);
	G1.setSize(rh2,rw2);
	G2.setSize(rh2,rw2);
	B.setSize(rh2,rw2);

	i2 = 0;
	if ((rw2==2672)&&(rh2==1758)) // размер матрицы canon 600D
	{
		for (ii = 0;ii < rh2;ii++)
		{
			j2 = 0;
			for (jj = 0;jj < rw2;jj++)
			{
				kk = j2 + i2*rw;
				G1.x[ii][jj] = raw_image[kk];
				kk++;
				B.x[ii][jj] = raw_image[kk];
				j2 += 2;
			}
			j2 = 0;
			i2++;
			for (jj = 0;jj < rw2;jj++)
			{
				kk = j2 + i2*rw;
				R.x[ii][jj] = raw_image[kk];
				kk++;
				G2.x[ii][jj] = raw_image[kk];
				j2 += 2;
			}
			i2++;
		}
	}
	else  // ((rw2==2416)&&(rh2==1602)) // размер матрицы  canon 500D
	{
		for (ii = 0;ii < rh2;ii++)
		{
			j2 = 0;
			for (jj = 0;jj < rw2;jj++)
			{
				kk = j2 + i2*rw;
				R.x[ii][jj] = raw_image[kk];
				kk++;
				G1.x[ii][jj] = raw_image[kk];
				j2 += 2;
			}
			j2 = 0;
			i2++;
			for (jj = 0;jj < rw2;jj++)
			{
				kk = j2 + i2*rw;
				G2.x[ii][jj] = raw_image[kk];
				kk++;
				B.x[ii][jj] = raw_image[kk];
				j2 += 2;
			}
			i2++;
		}
	}



	
	/*for (ii = 0;ii<rh2;ii++)
	{
		j2	= 0;
		for(jj = 0;jj<rw2;jj++)
		{
			kk = j2+i2*rw;
			R.x[ii][jj] = raw_image[kk];
			kk++;
			G1.x[ii][jj] = raw_image[kk];
			j2	+= 2;
		}
		j2	= 0;
		i2++;
		for(jj = 0;jj<rw2;jj++)
		{
			kk = j2+i2*rw;
			G2.x[ii][jj] = raw_image[kk];
			kk++;
			B.x[ii][jj] = raw_image[kk];
			j2	+= 2;
		}
		i2	++;
	}*/

//	G3 = G1;
	//G3.s += G2.s;
	//G3.s /= 2.0;

	//FullMatrix<unsigned short> Loc;
	//Loc.getSub(R,13,R.ny-1,31,R.nx-1);
	plt1D->user_max_y = 13500;//(double)Loc.s.max();
	delete [] raw_image;
}

void MainWin::savebin(FullMatrix<unsigned short> &R,FullMatrix<unsigned short> &G1,FullMatrix<unsigned short> &G2,FullMatrix<unsigned short> &B,const QString &fileName)
{
	QString fnmR(fileName);
	QString fnmG1(fileName);
	QString fnmG2(fileName);
	QString fnmB(fileName);
	fnmR.chop(4);
	fnmG1.chop(4);
	fnmG2.chop(4);
	fnmB.chop(4);
	fnmR.append("R.bin");
	fnmG1.append("G1.bin");
	fnmG2.append("G2.bin");
	fnmB.append("B.bin");



	FILE *fir, *fig1, *fig2, *fib;
	fir = fopen(fnmR.toLatin1().constData(),"wb");
	fwrite(&R.nx, sizeof(int), 1, fir);
	fwrite(&R.ny, sizeof(int), 1, fir);
	fwrite(R.s.x, sizeof(unsigned short),R.s.N, fir);
	fclose(fir);

	fig1 = fopen(fnmG1.toLatin1().constData(),"wb");
	fwrite(&G1.nx, sizeof(int), 1, fir);
	fwrite(&G1.ny, sizeof(int), 1, fir);
	fwrite(G1.s.x, sizeof(unsigned short),G1.s.N, fir);
	fclose(fig1);

	fig2 = fopen(fnmG2.toLatin1().constData(),"wb");
	fwrite(&G2.nx, sizeof(int), 1, fir);
	fwrite(&G2.ny, sizeof(int), 1, fir);
	fwrite(G2.s.x, sizeof(unsigned short),G2.s.N, fir);
	fclose(fig2);

	fib = fopen(fnmB.toLatin1().constData(),"wb");
	fwrite(&B.nx, sizeof(int), 1, fir);
	fwrite(&B.ny, sizeof(int), 1, fir);
	fwrite(B.s.x, sizeof(unsigned short),B.s.N, fir);
	fclose(fib);

}

void MainWin::addImage(FullMatrix<unsigned short> &R,FullMatrix<unsigned short> &G1,FullMatrix<unsigned short> &G2,FullMatrix<unsigned short> &B)
{
	Img_datas.adz(); // инициировать новый нулевой элемент в конце массива
	Img_datas.last().x[0] = R;
	Img_datas.last().x[1] = G1;
	Img_datas.last().x[2] = B;
	Img_datas.last().x[3] = G2;
	actual_pic_id = Img_datas.N-1;
}


void MainWin::getpicslice()
{
	getpicslice_(0);
}

void MainWin::getpicslice_(int dd=0)
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay,ro;
		int Nx1,Ny1,Nx2,Ny2,NN;

		pvw->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		NN = abs(Nx2-Nx1)>abs(Ny2-Ny1) ? abs(Nx2-Nx1) : abs(Ny2-Ny1);

		ax = (double(Nx2-Nx1))/double(NN);
		ay = (double(Ny2-Ny1))/double(NN);

		ro = sqrt(ax*ax+ay*ay);
		lhlpvr.var1D_(0,ro,NN);

		plt1D->rsz_All(NN);

		plt1D->setXdata(lhlpvr);

		double dx, dy;
		int nx, ny;
		for(int ii = 0;ii<NN;ii++)
		{
			dx = ax*ii;
			dy = ay*ii;
			nx = Nx1+dx;
			ny = Ny1+dy;
			plt1D->Y().x[0].x[ii] = R.fst(ny,nx);
			plt1D->Y().x[1].x[ii] = G1.fst(ny,nx);
			plt1D->Y().x[2].x[ii] = G2.fst(ny, nx);
			plt1D->Y().x[3].x[ii] = B.fst(ny,nx);
		}
		plt1D->ZoomReset();
		update();
	}
}

/*
void MainWin::getpicslice_(int dd=0)
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay,ro;
		int Nx1,Ny1,Nx2,Ny2,NN;
		
		pvw->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		//if (Nx2<Nx1) {NN = Nx2; Nx2 = Nx1;Nx1 = NN;	}
		//if (Ny2<Ny1) {NN = Ny2; Ny2 = Ny1;Ny1 = NN;	}

		// ориентация отрезкка - вдоль вертикали (false) или вдоль горизонтали (true)

		NN = abs(Nx2-Nx1)>abs(Ny2-Ny1) ? abs(Nx2-Nx1) : abs(Ny2-Ny1);
		
		ax = (double(Nx2-Nx1))/double(NN);
		ay = (double(Ny2-Ny1))/double(NN);


		/*if(dd==0)
		{
			if(ax==1)//((Nx1==Nx2)&&(Ny1!=Ny2))
			{
				dd = Nx1;
			}else
			if(ay==1)//((Ny1==Ny2)&&(Nx1!=Nx2))
			{
				dd = Ny1;
			}
		}* /



		plt1D->x.clear();
		plt1D->y.clear();
		plt1D->x.resize(NN);
		plt1D->y.resize(NN);


		double dx,dy;
		int nx,ny;
		ro = sqrt(ax*ax+ay*ay);
		for(int ii = 0;ii<NN;ii++)
		{
			dx = ax*ii;
			dy = ay*ii;
			nx = Nx1+dx;
			ny = Ny1+dy;
			plt1D->y[ii]=R.fst(ny,nx);//+G1.fst(ny,nx)+G2.fst(ny,nx)+B.fst(ny,nx);
			plt1D->x[ii]=ro*ii;//ii+dd;
		}

		update();

		//QPaintEvent *qpe;

		//qpe = new QPaintEvent(plt1D->rect());
		//plt1D->paintEvent(qpe);
	}
	//plt1D->setUpdatesEnabled(true);
	//plt1D->update();
	//setUpdatesEnabled(true);
	//repaint();
	//plt1D->setUpdatesEnabled(false);
}

*/

/*
void MainWin::getpicslice_sum_x()
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay;
		int Nx1,Ny1,Nx2,Ny2,NN;

		FullMatrix<unsigned short> Loc;

		pvw->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		Loc.getSub(R,Ny1,Ny2,Nx1,Nx2);

		plt1D->x.clear();
		plt1D->y.clear();
		plt1D->x.resize(Loc.nx);
		plt1D->y.resize(Loc.nx);

		for(int ii = 0;ii<Loc.nx;ii++) 
		{
			plt1D->x[ii] = ii+Nx1;	
			plt1D->y[ii] = 0;	
		}
		unsigned short *hx;
		for(int ii = 0;ii<Loc.ny;ii++)
		{
			hx = Loc.x[ii];
			for(int jj = 0;jj<Loc.nx;jj++)
			{
				plt1D->y[jj] += (double)hx[jj];
			}
		}

		for(int jj = 0;jj<Loc.nx;jj++)
		{
			plt1D->y[jj] /= Loc.ny;
		}

		QPaintEvent *qpe;
		qpe = new QPaintEvent(plt1D->rect());
		plt1D->paintEvent(qpe);
	}
}
*/

void MainWin::getpicslice_sum_x()
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay;
		int Nx1,Ny1,Nx2,Ny2,NN,nx,ny;

		pvw->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		nx = Nx2 - Nx1 + 1;
		ny = Ny2 - Ny1 + 1;

		plt1D->rsz_All(nx);

		lhlpvr.var1D_(Nx1, 1, nx);
		plt1D->setXdata(0, lhlpvr);
		plt1D->setXdata(2, lhlpvr);
		lhlpvr += 0.5;
		plt1D->setXdata(1, lhlpvr);
		plt1D->setXdata(3, lhlpvr);

		memset(plt1D->Y().x[0].x, 0, sizeof(double)*nx);
		memset(plt1D->Y().x[1].x, 0, sizeof(double)*nx);
		memset(plt1D->Y().x[2].x, 0, sizeof(double)*nx);
		memset(plt1D->Y().x[3].x, 0, sizeof(double)*nx);

		unsigned short *hxr,*hxg1,*hxg2,*hxb;
		double *hxd0, *hxd1, *hxd2, *hxd3;
		hxd0 = plt1D->Y().x[0].x;
		for (int ii = Ny1;ii <= Ny2;ii++) {	hxr = R.x[ii] + Nx1;   for (int jj = 0;jj<nx;jj++) {hxd0[jj] += (double)hxr[jj]; }}
		hxd1 = plt1D->Y().x[1].x;
		for (int ii = Ny1;ii <= Ny2;ii++) {	hxg1 = G1.x[ii] + Nx1; for (int jj = 0;jj<nx;jj++) {hxd1[jj] += (double)hxg1[jj];}}
		hxd2 = plt1D->Y().x[2].x;
		for (int ii = Ny1;ii <= Ny2;ii++) {	hxg2 = G2.x[ii] + Nx1; for (int jj = 0;jj<nx;jj++) {hxd2[jj] += (double)hxg2[jj];}}
		hxd3 = plt1D->Y().x[3].x;
		for(int ii = Ny1;ii<=Ny2;ii++)    { hxb  = B.x[ii] + Nx1;  for (int jj = 0;jj<nx;jj++) {hxd3[jj] += (double)hxb[jj]; }}
		
		plt1D->Y().x[0]/= (double)ny;
		plt1D->Y().x[1]/= (double)ny;
		plt1D->Y().x[2]/= (double)ny;
		plt1D->Y().x[3]/= (double)ny;
		
		plt1D->ZoomReset();
		update();
	}
}
/*
void MainWin::getpicslice_sum_y()
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay;
		int Nx1,Ny1,Nx2,Ny2,NN;

		FullMatrix<unsigned short> Loc;

		pvw->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		Loc.getSub(R,Ny1,Ny2,Nx1,Nx2);

		plt1D->x.clear();
		plt1D->y.clear();
		plt1D->x.resize(Loc.ny);
		plt1D->y.resize(Loc.ny);

		for(int ii = 0;ii<Loc.ny;ii++) 
		{
			plt1D->x[ii] = ii+Ny1;	
			plt1D->y[ii] = 0;	
		}
		unsigned short *hx;
		int kk;
		for(int ii = 0;ii<Loc.nx;ii++)
		{
			hx = (Loc.s.x+ii);
			kk = 0;
			for(int jj = 0;jj<Loc.ny;jj++)
			{
				plt1D->y[jj] += (double)hx[kk];
				kk	+=	Loc.nx;
			}
		}

		for(int jj = 0;jj<Loc.ny;jj++)
		{
			plt1D->y[jj] /= Loc.nx;
		}

		QPaintEvent *qpe;
		qpe = new QPaintEvent(plt1D->rect());
		plt1D->paintEvent(qpe);
	}
}
*/

void MainWin::getpicslice_sum_y()
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay;
		int Nx1,Ny1,Nx2,Ny2,NN,nx,ny;

		FullMatrix<unsigned short> LocR,LocG1,LocG2,LocB;

		pvw->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		nx = Nx2 - Nx1 + 1;
		ny = Ny2 - Ny1 + 1;

		plt1D->rsz_All(ny);

		lhlpvr.var1D_(Ny1, 1, ny);
		plt1D->setXdata(0, lhlpvr);
		plt1D->setXdata(3, lhlpvr);
		lhlpvr += 0.5;
		plt1D->setXdata(1, lhlpvr);
		plt1D->setXdata(2, lhlpvr);

		plt1D->Y().x[0].zero();
		plt1D->Y().x[1].zero();
		plt1D->Y().x[2].zero();
		plt1D->Y().x[3].zero();


		/*memset(plt1D->Y().x[0].x, 0, sizeof(double)*ny);
		memset(plt1D->Y().x[1].x, 0, sizeof(double)*ny);
		memset(plt1D->Y().x[2].x, 0, sizeof(double)*ny);
		memset(plt1D->Y().x[3].x, 0, sizeof(double)*ny);
		*/
		unsigned short *hxr, *hxg1, *hxg2, *hxb;
		double *hxd0, *hxd1, *hxd2, *hxd3;
		hxd0 = plt1D->Y().x[0].x;
		for (int ii = Ny1;ii <= Ny2;ii++) { hxr = R.x[ii] + Nx1;   for (int jj = Nx1;jj <= Nx2;jj++) { *hxd0 += (double)hxr[jj]; } hxd0++; }
		hxd1 = plt1D->Y().x[1].x;
		for (int ii = Ny1;ii <= Ny2;ii++) { hxg1 = G1.x[ii] + Nx1; for (int jj = Nx1;jj <= Nx2;jj++) { *hxd1 += (double)hxg1[jj]; } hxd1++; }
		hxd2 = plt1D->Y().x[2].x;
		for (int ii = Ny1;ii <= Ny2;ii++) { hxg2 = G2.x[ii] + Nx1; for (int jj = Nx1;jj <= Nx2;jj++) { *hxd2 += (double)hxg2[jj]; } hxd2++; }
		hxd3 = plt1D->Y().x[3].x;
		for (int ii = Ny1;ii <= Ny2;ii++) { hxb = B.x[ii] + Nx1;   for (int jj = Nx1;jj <= Nx2;jj++) { *hxd3 += (double)hxb[jj]; } hxd3++; }

		plt1D->Y().x[0] /= (double)nx;
		plt1D->Y().x[1] /= (double)nx;
		plt1D->Y().x[2] /= (double)nx;
		plt1D->Y().x[3] /= (double)nx;
		plt1D->ZoomReset();
		update();
	}
}



void MainWin::getpicsliceAC()
{
	if (AC.s.N!=0)
	{
		double x1,y1,x2,y2,ax,ay;
		int Nx1,Ny1,Nx2,Ny2,NN;
		int zx,zy;

		Cor2D->getpnts(x1,y1,x2,y2);
		Cor2D->getsz(zx,zy);

		Nx1 = AC.nx*x1;
		Ny1 = AC.ny*y1;

		Nx2 = AC.nx*x2;
		Ny2 = AC.ny*y2;


		NN = sqrt((x1-x2)*(x1-x2)*AC.nx*AC.nx+(y1-y2)*(y1-y2)*AC.ny*AC.ny);

		ax = (double(Nx2-Nx1))/double(NN);
		ay = (double(Ny2-Ny1))/double(NN);

		Corr->rsz_All(NN);

		lhlpvr.var1D_(0, 1, NN);
		Corr->setXdata(0, lhlpvr);
		Corr->Y().x[0].zero();
		/*Corr->x.clear();
		Corr->y.clear();
		Corr->x.resize(NN);
		Corr->y.resize(NN);
*/

		double dx,dy;
		int nx,ny;
		double *hxd0;
		hxd0 = Corr->Y().x[0].x;
		for(int ii = 0;ii<NN;ii++)
		{
			dx = ax*ii;
			dy = ay*ii;
			nx = Nx1+dx;
			ny = Ny1+dy;
			*hxd0=AC.fst(ny,nx);
			hxd0++;
			//Corr->x[ii]=ii;
		}
		Corr->ZoomReset();
		update();
		//QPaintEvent *qpe;

		//qpe = new QPaintEvent(Corr->rect());
		//Corr->paintEvent(qpe);
	}
	//plt1D->setUpdatesEnabled(true);
	//plt1D->update();
	//setUpdatesEnabled(true);
	//repaint();
	//plt1D->setUpdatesEnabled(false);*/
}
void MainWin::gethistdata()
{
	if (R.s.N!=0)
	{
		double x1,y1,x2,y2;
		int Nx1,Ny1,Nx2,Ny2,NN;
		unsigned short Imx, Imn, DI;

		FullMatrix<unsigned short> LocR,LocG1,LocG2,LocB;

		pvHist->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		LocR.getSub(R,Ny1,Ny2,Nx1,Nx2);	
		LocG1.getSub(G1,Ny1,Ny2,Nx1,Nx2);
		LocG2.getSub(G2,Ny1,Ny2,Nx1,Nx2);
		LocB.getSub(B,Ny1,Ny2,Nx1,Nx2);


		Imx = LocR.s.max();
		DI  = LocG1.s.max();
		Imx = Imx<DI ? DI:Imx;
		DI  = LocG2.s.max();
		Imx = Imx<DI ? DI:Imx;
		DI  = LocB.s.max();
		Imx = Imx<DI ? DI:Imx;

		Imn = LocR.s.min();
		DI  = LocG1.s.min();
		Imn = Imn>DI ? DI:Imn;
		DI  = LocG2.s.min();
		Imn = Imn>DI ? DI:Imn;
		DI  = LocB.s.min();
		Imn = Imn>DI ? DI:Imn;

		DI = Imx - Imn + 1;

		Hist->rsz_All((int)DI);
		
		//	Loc.s.qsort();
		for (int ii = 0;ii<DI;ii++)
		{
			Hist->X().x[0].x[ii] = Hist->X().x[1].x[ii] = Hist->X().x[2].x[ii] = Hist->X().x[3].x[ii] =  ii+Imn;	
		}

		int jj;
		for (int ii = 0;ii<LocR.s.N;ii++)
		{
			jj = LocR.s.x[ii]-Imn;
			Hist->Y().x[0].x[jj]++;
			jj = LocG1.s.x[ii]-Imn;
			Hist->Y().x[1].x[jj]++;
			jj = LocG2.s.x[ii]-Imn;
			Hist->Y().x[2].x[jj]++;
			jj = LocB.s.x[ii]-Imn;
			Hist->Y().x[3].x[jj]++;
		}

		double xx,yy;
		yy = log(10.);
		for (int ii = 0;ii<DI;ii++)
		{
			for(int jj =0;jj<4;jj++)
			{
				xx = Hist->Y().x[jj].x[ii];
				xx = (xx==0)? 0.95 : xx;
				xx = log(xx)/yy;
				Hist->Y().x[jj].x[ii] = xx;
			}
		}
		Hist->ZoomReset();
		//QPaintEvent *qpe;

		//qpe = new QPaintEvent(Hist->rect());
		//Hist->paintEvent(qpe);
		update();
	}
}

void MainWin::gethistdata2()
{
	if (R.s.N!=0)
	{
		
		double x1,y1,x2,y2;
		int Nx1,Ny1,Nx2,Ny2,NN;
		unsigned short Imx, Imn, DI;
		FullMatrix<unsigned short> LocR,LocG1,LocG2,LocB;

		pvHist->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
	//	if (Nx1==Nx2) {Nx2 = Nx1+1;}
	//	if (Ny1==Ny2) {Ny2 = Ny1+1;}

		/*LocR.getSub(R,Ny1,Ny2,Nx1,Nx2);	
		LocG1.getSub(G1,Ny1,Ny2,Nx1,Nx2);
		LocG2.getSub(G2,Ny1,Ny2,Nx1,Nx2);
		LocB.getSub(B,Ny1,Ny2,Nx1,Nx2);*/

		Imx = 0; 	for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) Imx = Imx < R.fst(ii, jj) ? R.fst(ii, jj) : Imx; }
		DI = 0;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) DI = DI < G1.fst(ii, jj) ? G1.fst(ii, jj) : DI; }
		Imx = Imx<DI ? DI:Imx;
		DI = 0;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) DI = DI < G2.fst(ii, jj) ? G2.fst(ii, jj) : DI; }
		Imx = Imx<DI ? DI:Imx;
		DI = 0;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) DI = DI < B.fst(ii, jj) ? B.fst(ii, jj) : DI; }
		Imx = Imx<DI ? DI:Imx;

		Imn = 0x0000ffff;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) Imn = Imn > R.fst(ii, jj) ? R.fst(ii, jj) : Imn; }
		DI = 0x0000ffff;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) DI = DI > G1.fst(ii, jj) ? G1.fst(ii, jj) : DI; }
		Imn = Imn>DI ? DI:Imn;
		DI = 0x0000ffff;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) DI = DI > G2.fst(ii, jj) ? G2.fst(ii, jj) : DI; }
		Imn = Imn>DI ? DI:Imn;
		DI = 0x0000ffff;		for (int ii = Ny1;ii <= Ny2;ii++) { for (int jj = Nx1;jj <= Nx2;jj++) DI = DI > B.fst(ii, jj) ? B.fst(ii, jj) : DI; }
		Imn = Imn>DI ? DI:Imn;

		DI = Imx - Imn + 1;

		int dNgx; // число интервалов по оси x
		dNgx = Hist->pixelLength();//Hist->frame[2] - Hist->frame[0]; //число пикселей вдоль оси x на графике
		dNgx = dNgx >400 ? 400 : dNgx;

		double kgx;
		kgx = round(double(DI)/double(dNgx));
		dNgx = round(double(DI) / kgx) + 1;
		
		//int kx;
		//kx = DI/dNgx;

		//if (kx>0) dNgx = DI/kx;

		Hist->rsz_All(dNgx);
		Hist->Y().x[0].zero();
		Hist->Y().x[1].zero();
		Hist->Y().x[2].zero();
		Hist->Y().x[3].zero();



		//	Loc.s.qsort();
		lhlpvr.var1D_(Imn, kgx, dNgx);
		Hist->setXdata(lhlpvr);

		/*for (int ii = 0;ii<dNgx;ii++)
		{
			Hist->X().x[0].x[ii] = Hist->X().x[1].x[ii] = Hist->X().x[2].x[ii] = Hist->X().x[3].x[ii] =  double(ii)*kgx+Imn;
		}*/

		int kk;
		for (int ii = Ny1;ii <= Ny2;ii++)
		{
			for (int jj = Nx1;jj <= Nx2;jj++)
			{
				kk = (R.fst(ii, jj) - Imn) / kgx;
			//	if (kk < 0) {	kk = 0;	}else if (kk >= dNgx)	{	kk = dNgx - 1;	}
				Hist->Y().x[0].x[kk]++;
			}
		}

		for (int ii = Ny1;ii <= Ny2;ii++)
		{
			for (int jj = Nx1;jj <= Nx2;jj++)
			{
				kk = (G1.fst(ii, jj) - Imn) / kgx;
			//	if (kk < 0)	{	kk = 0;	}else if (kk >= dNgx){	kk = dNgx - 1;	}
				Hist->Y().x[1].x[kk]++;
			}
		}

		for (int ii = Ny1;ii <= Ny2;ii++)
		{
			for (int jj = Nx1;jj <= Nx2;jj++)
			{
				kk = (G2.fst(ii, jj) - Imn) / kgx;
			//	if (kk < 0)	{	kk = 0;	}else	if (kk >= dNgx)	{kk = dNgx - 1;	}
				Hist->Y().x[2].x[kk]++;
			}
		}

		for (int ii = Ny1;ii <= Ny2;ii++)
		{
			for (int jj = Nx1;jj <= Nx2;jj++)
			{
				kk = (B.fst(ii, jj) - Imn) / kgx;
			//	if (kk < 0)	{kk = 0;}	else	if (kk >= dNgx)	{	kk = dNgx - 1;}
				Hist->Y().x[3].x[kk]++;
			}
		}


		/*int jj;
		for (int ii = 0;ii<LocR.s.N;ii++)
		{
			jj = (LocR.s.x[ii]-Imn)/kgx;
			Hist->Y().x[0].x[jj]++;
			jj = (LocG1.s.x[ii]-Imn)/kgx;
			Hist->Y().x[1].x[jj]++;
			jj = (LocG2.s.x[ii]-Imn)/kgx;
			Hist->Y().x[2].x[jj]++;
			jj = (LocB.s.x[ii]-Imn)/kgx;
			Hist->Y().x[3].x[jj]++;
		}*/

		LogHist->rsz_All(dNgx);
		LogHist->X() = Hist->X();
		LogHist->Y() = Hist->Y();
		
		double xx,yy;

		yy = log(10.);
		for (int ii = 0;ii<dNgx;ii++)
		{
			for(int jj =0;jj<4;jj++)
			{
				xx = LogHist->Y().x[jj].x[ii];
				xx = (xx==0)? 0.95 : xx;
				xx = log(xx)/yy;
				LogHist->Y().x[jj].x[ii] = xx;
			}
		}
		Hist->ZoomReset();
		LogHist->ZoomReset();
		/*QPaintEvent *qpe;
		qpe = new QPaintEvent(Hist->rect());
		Hist->paintEvent(qpe);
		QPaintEvent *qpe2;
		qpe2 = new QPaintEvent(LogHist->rect());
		LogHist->paintEvent(qpe);
		*/
		update();
	}
}







/*

void MainWin::gethistdata()
{
	if (R.s.N!=0)
	{
		double x1,y1,x2,y2;
		int Nx1,Ny1,Nx2,Ny2,NN;
		unsigned short Imx, Imn, DI;
		FullMatrix<unsigned short> Loc;

		pvHist->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		Loc.getSub(R,Ny1,Ny2,Nx1,Nx2);

		Imx = 0x0000;
		Imn = 0xffff;
		for (int ii=0;ii<Loc.s.N;ii++)
		{
			Imx = (Imx>Loc.s.x[ii]) ? Imx : Loc.s.x[ii];
			Imn = (Imn<Loc.s.x[ii]) ? Imn : Loc.s.x[ii];
		}

		DI = Imx - Imn + 1;
		Hist->x.resize(DI);
		Hist->y.resize(DI);

		//	Loc.s.qsort();
		for (int ii = 0;ii<DI;ii++)
		{
			Hist->x[ii] = ii+Imn;
			Hist->y[ii] = 0;
		}
		int jj;
		for (int ii = 0;ii<Loc.s.N;ii++)
		{
			jj = Loc.s.x[ii]-Imn;
			Hist->y[jj]++;
		}

		double xx,yy;
		for (int ii = 0;ii<DI;ii++)
		{
			xx = Hist->y[ii];
			if(xx == 0)
			{
				xx = 0.95;
				yy = log(xx)/log(10.);
				Hist->y[ii] = yy;
			}else
			{
				yy = log(xx)/log(10.);
				Hist->y[ii] = yy;
			}
		}
		QPaintEvent *qpe;

		qpe = new QPaintEvent(Hist->rect());
		Hist->paintEvent(qpe);
	}
}

void MainWin::gethistdata2()
{
	if (R.s.N!=0)
	{
		
		double x1,y1,x2,y2;
		int Nx1,Ny1,Nx2,Ny2,NN;
		unsigned short Imx, Imn, DI;
		FullMatrix<unsigned short> Loc;

		pvHist->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		Loc.getSub(R,Ny1,Ny2,Nx1,Nx2);

		Imx = 0x0000;
		Imn = 0xffff;
		for (int ii=0;ii<Loc.s.N;ii++)
		{
			Imx = (Imx>Loc.s.x[ii]) ? Imx : Loc.s.x[ii];
			Imn = (Imn<Loc.s.x[ii]) ? Imn : Loc.s.x[ii];
		}

		DI = Imx - Imn + 1;


		int dNgx; // число интервалов по оси x
		dNgx = Hist->frame[2]-Hist->frame[0]; //число пикселей вдоль оси x на графике


		int kx;
		kx = DI/dNgx;

		if (kx>0) dNgx = DI/kx;

		Hist->x.resize(dNgx);
		Hist->y.resize(dNgx);

		double kgx;
		kgx = double(DI)/double(dNgx);

		//	Loc.s.qsort();
		for (int ii = 0;ii<dNgx;ii++)
		{
			Hist->x[ii] = Imn+double(ii)*kgx;
			Hist->y[ii] = 0;
		}
		int jj;
		for (int ii = 0;ii<Loc.s.N;ii++)
		{
			jj = (Loc.s.x[ii]-Imn)/kgx;
			Hist->y[jj]++;
		}

		LogHist->x.resize(dNgx);
		LogHist->y.resize(dNgx);
		double xx,yy;
		for (int ii = 0;ii<dNgx;ii++)
		{
			xx = Hist->y[ii];
			LogHist->x[ii] = Hist->x[ii];
			if(xx == 0)
			{
				xx = 0.95;
				yy = log(xx)/log(10.);
				LogHist->y[ii] = yy;
			}else
			{
				yy = log(xx)/log(10.);
				LogHist->y[ii] = yy;
			}
		}

		QPaintEvent *qpe;
		qpe = new QPaintEvent(Hist->rect());
		Hist->paintEvent(qpe);
		QPaintEvent *qpe2;
		qpe2 = new QPaintEvent(LogHist->rect());
		LogHist->paintEvent(qpe);
	}
}

*/

void MainWin::autoCorr()
{
	if(R.s.N!=0)
	{
		double x1,y1,x2,y2;
		int Nx1,Ny1,Nx2,Ny2,NN;
		FullMatrix<unsigned short> Loc;
		vecT<double> DbLoc;
		//double GSum;

		pvHist->getpnts(x1,y1,x2,y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) {NN = Nx1; Nx1 = Nx2; Nx2 = NN;}
		if (Ny1>Ny2) {NN = Ny1; Ny1 = Ny2; Ny2 = NN;}
		if (Nx1==Nx2) {Nx2 = Nx1+1;}
		if (Ny1==Ny2) {Ny2 = Ny1+1;}

		Loc.getSub(R,Ny1,Ny2,Nx1,Nx2);
		DbLoc.setlen(Loc.s.N);
		for(int ii = 0;ii<Loc.s.N;ii++) {DbLoc.x[ii] = (double) Loc.s.x[ii];}
		AC.setSize(acny,acnx);

		FullMatrix<double> Mtest;
		Mtest.setSize(Loc.ny,Loc.nx);
		Mtest.s.pst(DbLoc);
		Mtest.ConnectPointer();
		//Mtest.FullCorrelation(AC);
		Mtest.PartCorrelation(AC,100,150);

		AC.Shift();

		Cor2D->setpicdata(AC);
		update();
		
/*
		FullMatrix<unsigned short> R1;
		int zx,zy;
		Cor2D->getsz(zx,zy);
		R1.setSize(zy,zx);
		double Gx,Gn,kk;
		Gx = AC.s.max();
		Gn = AC.s.min();

		kk = 255/(Gx-Gn); // коэффиц. масштабирования на 8 бит

		double ax,ay;

		ax = zx/AC.nx;
		ay = zy/AC.ny;

		if (ax>ay)
		{ // картинку увеличивать только в ay раз
		}else
		{// картинку увеличивать в ax раз
			ay = ax;
		}
		int nn,mm;
		zy = ay*AC.ny;
		zx = ax*AC.nx;
		for (int ii=0;ii<zy;ii++)
		{
			nn = ii/ay;
			for(int jj=0;jj<zx;jj++)
			{
				mm = jj/ax;
				R1.fst(ii,jj) = (AC.fst(nn,mm)-Gn)*kk;
			}
		}

		Cor2D->setpicdata(R1);

		QPaintEvent *qpe;

		qpe = new QPaintEvent(Cor2D->rect());
		Cor2D->paintEvent(qpe);
		//AC.showfull_infile("fullcor.txt");
*/
	}
}
void MainWin::getRScldata()
{
	if (R.s.N != 0)
	{
		double x1, y1, x2, y2;
		int Nx1, Ny1, Nx2, Ny2, NN;
		unsigned short Imx, Imn, DI;

		FullMatrix<unsigned short> LocR, LocG1, LocG2, LocB;

		pvHist->getpnts(x1, y1, x2, y2);

		Nx1 = R.nx*x1;
		Ny1 = R.ny*y1;

		Nx2 = R.nx*x2;
		Ny2 = R.ny*y2;

		if (Nx1>Nx2) { NN = Nx1; Nx1 = Nx2; Nx2 = NN; }
		if (Ny1>Ny2) { NN = Ny1; Ny1 = Ny2; Ny2 = NN; }
		if (Nx1 == Nx2) { Nx2 = Nx1 + 1; }
		if (Ny1 == Ny2) { Ny2 = Ny1 + 1; }

		LocR.getSub(R, Ny1, Ny2, Nx1, Nx2);
		LocG1.getSub(G1, Ny1, Ny2, Nx1, Nx2);
		LocG2.getSub(G2, Ny1, Ny2, Nx1, Nx2);
		LocB.getSub(B, Ny1, Ny2, Nx1, Nx2);

		LocG1.s += LocG2.s;
		LocG1.s /= 2;

	//	pvRScl->clearpicdata();
		pvRScl->setpicdata(LocR, LocG1, LocB);
		update();
	}
}

void MainWin::setFlScrPic()
{ // катринка заполняется по по данным размера рамки определяемой в режиме "Гистограмма"
	double x1,y1,x2,y2;
	pvHist->getpnts(x1,y1,x2,y2);
	int i1,i2,j1,j2,nnx,nny;

	j1 = x1*R.nx;
	j2 = x2*R.nx;
	i1 = y1*R.ny;
	i2 = y2*R.ny;

	if(i2<i1) {nny = i1; i1 = i2; i2 = nny;}
	if(j2<j1) {nnx = j1; j1 = j2; j2 = nnx;}

	nnx = j2-j1;
	nny = i2-i1;

	FullMatrix<unsigned short> LR,LG1,LG2,LB;

	LR.getSub(R,i1,i2,j1,j2);
	LG1.getSub(G1,i1,i2,j1,j2);
	LG2.getSub(G2,i1,i2,j1,j2);
	LB.getSub(B,i1,i2,j1,j2);

	LG1.s += LG2.s;
	LG1.s /= 2;

	pFllScrn->setpnts(0,0,0,0);
	pFllScrn->setpicdataFull(LR,LG1,LB);
}

void MainWin::showFullScrn()
{
	setFlScrPic();
	pFllScrn->setWindowState(Qt::WindowFullScreen);
	//pFllScrn->setForegroundRole(QPalette::Shadow);
	pFllScrn->showFullScreen();

	//QPaintEvent *qpe;

	//qpe = new QPaintEvent(pFllScrn->rect());
	//Cor2D->paintEvent(qpe);
		
}

void MainWin::setcrd_1()
{
	int nx,ny;
	double x1,x2,y1,y2;
	QString hstr;
	
	pvw->getpnts(x1,y1,x2,y2);
	nx = x1*R.nx;
	ny = y1*R.ny;
	hstr.setNum(nx);
	data_x1->clear();
	data_x1->insert(hstr);
	hstr.setNum(ny);
	data_y1->clear();
	data_y1->insert(hstr);
	nx = x2*R.nx;
	ny = y2*R.ny;
	hstr.setNum(nx);
	data_x2->clear();
	data_x2->insert(hstr);
	hstr.setNum(ny);
	data_y2->clear();
	data_y2->insert(hstr);
	nx = (x2-x1)*R.nx;
	hstr.setNum(nx);
	data_dx->clear();
	data_dx->insert(hstr);
	ny = (y2-y1)*R.ny;
	hstr.setNum(ny);
	data_dy->clear();
	data_dy->insert(hstr);
}

void MainWin::updcrd_1()
{
	int nx,ny;
	double x1,x2,y1,y2;
	QString hstr;
	hstr = data_x1->displayText();
	x1 = hstr.toDouble()/R.nx;
	hstr = data_y1->displayText();
	y1 = hstr.toDouble()/R.ny;
	hstr = data_x2->displayText();
	x2 = hstr.toDouble()/R.nx;
	hstr = data_y2->displayText();
	y2 = hstr.toDouble()/R.ny;
	pvw->setpnts(x1,y1,x2,y2);
	getpicslice();
	QPaintEvent *qpe;
	qpe = new QPaintEvent(pvw->rect());
	pvw->paintEvent(qpe);
}

void MainWin::hrznalgm()
{
	double x1,x2,y1,y2;
	pvw->getpnts(x1,y1,x2,y2);
	x1 = x2 = (x1+x2)/2;
	pvw->setpnts(x1,y1,x2,y2);
	y1 = y1<y2 ? y1 : y2;
	getpicslice_(y1*R.ny);
	QPaintEvent *qpe;
	qpe = new QPaintEvent(pvw->rect());
	pvw->paintEvent(qpe);
}

void MainWin::vrtcalgm()
{
	double x1,x2,y1,y2;
	pvw->getpnts(x1,y1,x2,y2);
	y1 = y2 = (y1+y2)/2;
	pvw->setpnts(x1,y1,x2,y2);
	x1 = x1<x2 ? x1 : x2;
	getpicslice_(x1*R.nx);
	QPaintEvent *qpe;
	qpe = new QPaintEvent(pvw->rect());
	pvw->paintEvent(qpe);
}

void MainWin::cntposCM()
{
	double x1,x2,y1,y2;

	int ii,jj;

	FullMatrix<unsigned short> locR;

	locR.getSub(R,13,R.ny-1,0,30);
	double sz0;
	sz0 = 0.0;
	for(ii=0;ii<locR.s.N;ii++) 	{sz0 += locR.s.x[ii]; }
	sz0 /= locR.s.N;

	locR.getSub(R,13,R.ny-1,31,R.nx-1);

	double sxc,syc,xc,yc,sz;
	sxc = syc = sz = xc = yc = 0.0;
	for(ii=0;ii<locR.ny;ii++)
	{
		for(jj=0;jj<locR.nx;jj++)
		{
			yc += (locR.x[ii][jj]-sz0)*ii;
			xc += (locR.x[ii][jj]-sz0)*jj;
		}
	}
	for(ii=0;ii<locR.s.N;ii++) 	{sz += (locR.s.x[ii]-sz0); }

	xc /= sz;
	yc /= sz;

	for(ii=0;ii<locR.ny;ii++)
	{
		for(jj=0;jj<locR.nx;jj++)
		{
			syc += (locR.x[ii][jj]-sz0)*(ii-xc)*(ii-xc);
			sxc += (locR.x[ii][jj]-sz0)*(jj-yc)*(jj-yc);
		}
	}

	sxc = sqrt(sxc/sz);
	syc = sqrt(syc/sz);

	xc += 31; 
	yc += 13;

	QString hstr("(xc,yc): ");
	
	hstr.append(QString().setNum(int(xc)));
	hstr.append(", ");
	hstr.append(QString().setNum(int(yc)));

	str_CM_xy->setText(hstr);

	xc /= (double)R.nx;
	yc /= (double)R.ny;

	sxc /= (double)R.nx;
	syc /= (double)R.ny;




	x1 = xc - sxc;
	y1 = yc - syc;
	x2 = xc + sxc;
	y2 = yc + syc;
	
	x1 = x1<=0 ? 0 : x1;
	x1 = x1>=1 ? 1 : x1;

	y1 = y1<=0 ? 0 : y1;
	y1 = y1>=1 ? 1 : y1;

	x2 = x2<=0 ? 0 : x2;
	x2 = x2>=1 ? 1 : x2;

	y2 = y2<=0 ? 0 : y2;
	y2 = y2>=1 ? 1 : y2;


	pvw->setpnts(x1,y1,x2,y2);
	getpicslice();
	QPaintEvent *qpe;
	qpe = new QPaintEvent(pvw->rect());
	pvw->paintEvent(qpe);
		//<unsigned short> R
}

void MainWin::AboutMsg()
{
	const QString title = QString("Program  Specls");
	QString text;

	text.append("Program Specls - program for analize pictures of specls of laser radiation forms from rugged surface\n \n ");
	text.append("Sergey N. Zhabin 2020 @");

	QMessageBox::about(this, title,text);
}
void MainWin::AboutQtMsg()
{
	const QString title = QString("Program  Specls");

	QMessageBox::aboutQt(this, title);
}

void MainWin::keyPressEvent(QKeyEvent *event)
{
	event->accept();
}

#endif