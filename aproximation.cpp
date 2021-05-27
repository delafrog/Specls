#ifndef APROXIMATION_CPP
#define APROXIMATION_CPP

#include <QApplication>
#include <QWidget>
#include "aproximation.h"
#include "linalg.cpp"

ClbrWidget::ClbrWidget(QWidget *parent) : QWidget(parent)
{
	int Dx;
/*	pxspln = 1200;
	pxsphg = 100;
	clbr_pic = new PicView(this);
	clbr_pic->setsz(pxspln, pxsphg);
	clbr_pic->BlackFill();
	clbr_pic->setpnts(0., 0., 0., 0.);
	clbr_pic->settype(1);*/

/*	clbr_grf = new PlotGraph(this);
	clbr_grf->setNgrphx(4);
	clbr_grf->xlabel(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\262 \320\277\320\273\320\276\321\201\320\272\320\276\321\201\321\202\320\270 (x,y) [\320\277\320\270\321\201\320\272\320\265\320\273\320\270]", 0));
	clbr_grf->ylabel(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 [\320\276\321\202\320\275. \320\265\320\264.]", 0));//tr("Int. a.u."));
*/

	clbr_grf->p_gsaprx = &GssApprx;
	//clbr_grf->p_loraprx = &LorApprx;
	aprxtype = 0;

	clbr_grf->FrameSetUp();// DrawAxes(painter);
	dw = clbr_grf->fontMetrics().width("-0.000");
	Dx = clbr_grf->get_lShift();
	clbr_pic->set_lShft(Dx);
	Dx = dw + pxspln-1;
	clbr_grf->setFixedWidth(Dx);
	clbr_grf->setTcsTpx(0);
	clbr_grf->setTcsTpy(1);


	chanel_id = -1; // по умолчанию нет выбранного канала

	groupBox = new QGroupBox(tr("Channels for a peak approximation"));// QApplication::translate("Channel for peak approximation", 0), this);


	red = new QRadioButton(QApplication::translate("MainWindow", "Red channel", 0),this);
	green1 = new QRadioButton(QApplication::translate("MainWindow", "Green1 channel", 0), this);
	green2 = new QRadioButton(QApplication::translate("MainWindow", "Green2 channel", 0), this);
	blue = new QRadioButton(QApplication::translate("MainWindow", "Blue channel", 0), this);

	QGridLayout * gbox;
	gbox = new QGridLayout();

	gbox->addWidget(red,0,0);
	gbox->addWidget(green1, 0,1);
	gbox->addWidget(green2, 1, 0);
	gbox->addWidget(blue, 1, 1);

	groupBox->setLayout(gbox);

	//yfuntext = new QLabel(tr("Approximation function: f(x) = A*exp(-( (x-B)/C)^2 ) + D*(x-B) + E"));

	groupBox2 = new QGroupBox(tr("Type of a peak approximation"));// QApplication::translate("Channel for peak approximation", 0), this);

	lorents = new QRadioButton(QApplication::translate("MainWindow", "Lorents fit: f(x) = A/((x-B)^2+C^2) +D*(x-B) + E ", 0), this);
	gauss = new QRadioButton(QApplication::translate("MainWindow", "Gauss fit: f(x) =  A*exp(-( (x-B)/C)^2 ) + D*(x-B) + E ", 0), this);

	QVBoxLayout * vbox5;
	vbox5 = new QVBoxLayout();
	vbox5->addWidget(gauss);
	vbox5->addWidget(lorents);
	groupBox2->setLayout(vbox5);
	groupBox2->setFixedSize(300,80);

//	formula = new QLabel(this);
//	formula->setPixmap(QPixmap(QString("formula.png")));


	QHBoxLayout * hbox1;
	hbox1 = new QHBoxLayout();
	hbox1->addWidget(groupBox);
	hbox1->addStretch();

	QVBoxLayout * vbox2;
	vbox2 = new QVBoxLayout();
	vbox2->addLayout(hbox1);
	vbox2->addWidget(groupBox2);
//	vbox2->addWidget(yfuntext);
//	vbox2->addWidget(formula);
	

	fiterrtxt = new QLabel(tr("Fit error Err(A,B,C,D,E) = "));
	fiterrdata = new QLabel(tr("          "));
	QHBoxLayout * hbox4;
	hbox4 = new QHBoxLayout();
	hbox4->addWidget(fiterrtxt);
	hbox4->addWidget(fiterrdata);
	hbox4->addStretch();

	vbox2->addLayout(hbox4);

	QStringList LblNms;
	LblNms.append(QString(tr("Value")));
	LblNms.append(QString(tr("Error")));
	QStringList PrmNms;
	PrmNms.append(QString(tr("A [Counts]")));
	PrmNms.append(QString(tr("B [Pixels]")));
	PrmNms.append(QString(tr("C [Pixels]")));
	PrmNms.append(QString(tr("D [Cnt/Pxl]")));
	PrmNms.append(QString(tr("E [Counts]")));

	fitParTbl =	 new QTableWidget(this);
	fitParTbl->setColumnCount(2);
	fitParTbl->setRowCount(5);
	fitParTbl->setVerticalHeaderLabels(PrmNms);
	fitParTbl->setHorizontalHeaderLabels(LblNms);
	fitParTbl->setFixedSize(300,175);


	fP_A = new  QTableWidgetItem();
	fP_sgA = new  QTableWidgetItem();
	fP_B = new  QTableWidgetItem();
	fP_sgB = new  QTableWidgetItem();
	fP_C = new  QTableWidgetItem();
	fP_sgC = new  QTableWidgetItem();
	fP_D = new  QTableWidgetItem();
	fP_sgD = new  QTableWidgetItem();
	fP_E = new  QTableWidgetItem();
	fP_sgE = new  QTableWidgetItem();

	fitParTbl->setItem(0, 0, fP_A);
	fitParTbl->setItem(0, 1, fP_sgA);
	fitParTbl->setItem(1, 0, fP_B);
	fitParTbl->setItem(1, 1, fP_sgB);
	fitParTbl->setItem(2, 0, fP_C);
	fitParTbl->setItem(2, 1, fP_sgC);
	fitParTbl->setItem(3, 0, fP_D);
	fitParTbl->setItem(3, 1, fP_sgD);
	fitParTbl->setItem(4, 0, fP_E);
	fitParTbl->setItem(4, 1, fP_sgE);

	
	vbox2->addWidget(fitParTbl);
	vbox2->addStretch();

	QVBoxLayout * vbox1;

	vbox1 = new QVBoxLayout();

	vbox1->addWidget(clbr_pic);
	vbox1->addWidget(clbr_grf);
//	vbox1->addStretch();

	QHBoxLayout * hbox0;
	hbox0 = new QHBoxLayout();
	hbox0->addLayout(vbox1);
	hbox0->addLayout(vbox2);


	this->setLayout(hbox0);


	connect(clbr_grf, SIGNAL(selDataReady()), this, SLOT(addPeakData()));

	connect(red, SIGNAL(clicked()), this, SLOT(setRed()));
	connect(green1, SIGNAL(clicked()), this, SLOT(setGreen1()));
	connect(green2, SIGNAL(clicked()), this, SLOT(setGreen2()));
	connect(blue, SIGNAL(clicked()), this, SLOT(setBlue()));

	connect(gauss, SIGNAL(clicked()), this, SLOT(setGauss()));
	connect(lorents, SIGNAL(clicked()), this, SLOT(setLor()));

	connect(clbr_pic, SIGNAL(getnewpic()), this, SIGNAL(clbr_pic_udp_req()));

	gauss->click();


}

void ClbrWidget::setCalibrData(vec4FMushort * Dat, int y1, int y2)
{
	FullMatrix<unsigned short> R, G1,G2,G3, B;
	int len,ym;
	QImage l_Img;
	
	if (y1 > y2) 
	{
		len = y1;
		y1 = y2;
		y2 = len;
	}
	if (y1 == y2) if (y2 < Dat->x[0].ny - 1) y2++; else if (y1 > 0) y1--; else return;
	len = Dat->x[0].nx - 1;
	// выделение рабочей части изображения
	R.getSub (Dat->x[0], y1, y2, 0, len);
	G1.getSub(Dat->x[1], y1, y2, 0, len);
	B.getSub (Dat->x[2], y1, y2, 0, len);
	G2.getSub(Dat->x[3], y1, y2, 0, len);

	G3 = G1;
	G3.s += G2.s;
	G3.s /= 2.0;

	clbr_pic->setpicdata(R,G3,B,1);
	pxspln = clbr_pic->getlen();
	clbr_pic->setsz(pxspln, pxsphg);

	l_Img = clbr_pic->getPic();
	clbr_pic->setPic(l_Img.scaled(pxspln, pxsphg, Qt::IgnoreAspectRatio, Qt::FastTransformation));

	
	clbr_grf->setSelActText(tr("Select Peak"));
	clbr_grf->rsz_All(R.nx);
	
	clbr_grf->setFixedWidth(clbr_grf->get_lShift() + dw + pxspln - 1);
	ym = (y2-y1) / 2;

	vecdb ix(R.nx);

	ix.var1D_(0.0, 1.0,R.nx );
	//clbr_grf->setXdata(ix);
	clbr_grf->setXdata(0, ix);
	clbr_grf->setXdata(2, ix);
	ix += 0.5;
	clbr_grf->setXdata(1, ix);
	clbr_grf->setXdata(3, ix);

	clbr_grf->ZoomReset();

	memset(ix.x, 0, sizeof(double)*R.nx);
	for (int ii = 0;ii < R.ny;ii++)	{for (int jj = 0;jj < R.nx;jj++){	ix.x[jj] += R.x.x[ii][jj];	}}
	ix /= double(R.ny);
	clbr_grf->setYdata(0, ix);

	memset(ix.x, 0, sizeof(double)*G1.nx);
	for (int ii = 0;ii < G1.ny;ii++) { for (int jj = 0;jj < G1.nx;jj++) { ix.x[jj] += G1.x.x[ii][jj]; } }
	ix /= double(G1.ny);
	clbr_grf->setYdata(1, ix);

	memset(ix.x, 0, sizeof(double)*G2.nx);
	for (int ii = 0;ii < G2.ny;ii++) { for (int jj = 0;jj < G2.nx;jj++) { ix.x[jj] += G2.x.x[ii][jj]; } }
	ix /= double(G2.ny);
	clbr_grf->setYdata(2, ix);

	memset(ix.x, 0, sizeof(double)*B.nx);
	for (int ii = 0;ii < B.ny;ii++) { for (int jj = 0;jj < B.nx;jj++) { ix.x[jj] += B.x.x[ii][jj]; } }
	ix /= double(B.ny);
	clbr_grf->setYdata(3, ix);

	/*
	for (int ii = 0;ii < R.nx;ii++) { ix.x[ii] = R.fst(ym, ii);	}
	clbr_grf->setYdata(0,ix);
	for (int ii = 0;ii < G1.nx;ii++) { ix.x[ii] = G1.fst(ym, ii); }
	clbr_grf->setYdata(1, ix);
	for (int ii = 0;ii < G2.nx;ii++) { ix.x[ii] = G2.fst(ym, ii); }
	clbr_grf->setYdata(2, ix);
	for (int ii = 0;ii < B.nx;ii++) { ix.x[ii] = B.fst(ym, ii); }
	clbr_grf->setYdata(3, ix);
	*/

	clbr_grf->setmnmx();
	clbr_grf->adpmnmx();
	clbr_grf->FrameSetUp();

	len = clbr_grf->dataLength() / 2; //(clbr_grf->mnmx[1] - clbr_grf->mnmx[0]) / 2;
	clbr_grf->setFixedWidth(clbr_grf->get_lShift() + dw + len);

	update();

	//d->imgs = d->bigIm.scaled(320, 240, Qt::KeepAspectRatio, Qt::FastTransformation);

}


void ClbrWidget::addPeakData()
{
	vecdb xx;	// аргумент аппроксимирующей функции
	vecdb ff;	// значения аппроксимирующей функции


	if ((chanel_id >= 0) && (chanel_id <= 3))
	{
		if (clbr_grf->SelectedIds.x[chanel_id].N > 3)
		{
			xx.fsetlen(clbr_grf->SelectedIds.x[chanel_id].N);
			ff.fsetlen(clbr_grf->SelectedIds.x[chanel_id].N);

			clbr_grf->X().x[chanel_id].ind(clbr_grf->SelectedIds.x[chanel_id], xx); // выбор в xx значений агрумента выбранного диапазона
			clbr_grf->Y().x[chanel_id].ind(clbr_grf->SelectedIds.x[chanel_id], ff); // выбор в ff значений интесивности выбранного диапазона

			clbr_grf->fun_x1 = xx.x[0];
			clbr_grf->fun_x2 = xx.last();


			if (aprxtype == 0)
			{
				GssApprx.setdata(xx, ff);
				GssApprx.MinErrFind();

				fiterrdata->setText(QString().setNum(GssApprx.err, 'g', 6));

				fP_A->setText(QString().setNum(GssApprx.X.x[0], 'g', 6));
				fP_sgA->setText(QString().setNum(GssApprx.X_.x[0], 'g', 4));
				fP_B->setText(QString().setNum(GssApprx.X.x[1], 'g', 8));
				fP_sgB->setText(QString().setNum(GssApprx.X_.x[1], 'g', 4));
				fP_C->setText(QString().setNum(GssApprx.X.x[2], 'g', 8));
				fP_sgC->setText(QString().setNum(GssApprx.X_.x[2], 'g', 4));
				fP_D->setText(QString().setNum(GssApprx.X.x[3], 'g', 6));
				fP_sgD->setText(QString().setNum(GssApprx.X_.x[3], 'g', 4));
				fP_E->setText(QString().setNum(GssApprx.X.x[4], 'g', 6));
				fP_sgE->setText(QString().setNum(GssApprx.X_.x[4], 'g', 4));

				clbr_grf->setFundata();
			}
			else
			{
				LorApprx.setdata(xx, ff);
				LorApprx.MinErrFind();

				fiterrdata->setText(QString().setNum(LorApprx.err, 'g', 6));

				fP_A->setText(QString().setNum(LorApprx.X.x[0], 'g', 6));
				fP_sgA->setText(QString().setNum(LorApprx.X_.x[0], 'g', 4));
				fP_B->setText(QString().setNum(LorApprx.X.x[1], 'g', 8));
				fP_sgB->setText(QString().setNum(LorApprx.X_.x[1], 'g', 4));
				fP_C->setText(QString().setNum(LorApprx.X.x[2], 'g', 8));
				fP_sgC->setText(QString().setNum(LorApprx.X_.x[2], 'g', 4));
				fP_D->setText(QString().setNum(LorApprx.X.x[3], 'g', 6));
				fP_sgD->setText(QString().setNum(LorApprx.X_.x[3], 'g', 4));
				fP_E->setText(QString().setNum(LorApprx.X.x[4], 'g', 6));
				fP_sgE->setText(QString().setNum(LorApprx.X_.x[4], 'g', 4));

				clbr_grf->setFundata2();
			}
		}
	}
}


#endif


