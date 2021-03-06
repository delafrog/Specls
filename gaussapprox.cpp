#ifndef GAUSSAPPROX_CPP
#define GAUSSAPPROX_CPP

#include <QMessageBox>
#include "gaussapprox.h"
#include "linalg.cpp"
#include "linalg.h"

GaussApproximator::GaussApproximator()
{
	P.setlen(dim);
	S.setlen(dim);
	S_.setlen(dim);
	R.setlen(dim);
	R_.setlen(dim);
	X.setlen(dim);
	X_.setlen(dim);

	Grd.setlen(dim);
	H.setSize(dim, dim);

	grad_data.setlen(dim);

	usr_eps = 1e-10; // ??????????????? ????????????? ??????? 
	usr_Nittr = 1000; // ??????????????? ????????????? ???????????? ????? ?????????

	//AF = &GaussApproximator::Fun;
//	hess_data.setSize(dim,dim);
}

void GaussApproximator::setdata(vecdb & x_in, vecdb & y_in)
{
	double mx, mn, yn,yx;
	
	x.fsetlen(x_in.N);
	y.fsetlen(y_in.N);
	f.fsetlen(x_in.N);

	mx = x_in.last();// x_in.max();
	mn = x_in.x[0];// .min();

	yn = y_in.x[0];
	yx = y_in.last();
	k_ = (yx-yn)/(mx-mn);
	b_ = (yn*mx-yx*mn) / (mx-mn);

	// ????????? ???????? ????????? 
	x = x_in;
	x *= k_;
	x += b_;
	f = y_in;
	f -= x;

	// ????????? ?????? ??????? ????? ????????? ?????????
	for (int ii = 0; ii < f.N; ii++) { y.x[ii] = fabs(f.x[ii]); }
	int id;
	double myx;

	myx = y.max(id); // ??????????? ????????? ??????  - ??? ?????????????? ????????????? ?????????

	sign = (y.x[id] != f.x[id]) ? -1 : 1; // ???? , ???? ??? ?????? ???? , ?? ???? '-'
	
	f *= sign; // ???? ????? - ?????? ?  f  ??? ?????? ??????? ?????

	kx = 2.0 / (mx - mn);
	bx = (mx + mn) / (mn - mx);

	// ????? ???????? ? ??????? ?? 'f'
	mx = f.max();
	mn = f.min();

	ky = 1. / (mx - mn);
	by = mn / (mn - mx);

	x = x_in;

	x *= kx;
	x += bx;

	y = f;
	y *= ky;
	y += by;

	for(int ii=0;ii<dim;ii++)
	{
		grad_data.x[ii].fsetlen(x.N);
	}
	/*for (int ii = 0; ii<hess_data.s.N; ii++)
	{
		hess_data.s.x[ii].fsetlen(x.N);
	}*/
	hess_data_12.fsetlen(x.N);
	hess_data_13.fsetlen(x.N);
	hess_data_22.fsetlen(x.N);
	hess_data_23.fsetlen(x.N);
	hess_data_33.fsetlen(x.N);
	

	hexp.fsetlen(x.N);
	hf1.fsetlen(x.N);
	hf2.fsetlen(x.N);
}

void GaussApproximator::fitfun(vecdb & Xk)
{
	double c2,c1;
	c2 *= c2 = 1/Xk.x[2];
	for (int ii = 0; ii < x.N; ii++)
	{
		c1 *= c1 = (x.x[ii] - Xk.x[1]);
		hf1.x[ii] = c1 *= c2; // ((x-B)/C)^2
	}
	for (int ii = 0; ii < x.N; ii++)
	{
		hexp.x[ii] = exp(-hf1.x[ii]); // exp(-((x-B)/C)^2)
	}
	for (int ii = 0; ii < x.N; ii++)
	{
		f.x[ii] = Xk.x[0] * hexp.x[ii] + Xk.x[3] * x.x[ii] + Xk.x[4];  // A*exp(-((x-B)/C)^2) + D*x +E
	}

	//c1 *= c1 = Xk.x[2];
	hf2 = x;
	hf2 -= Xk.x[1];
	hf2 *= 2.0 * (c2);
}

void GaussApproximator::ErrFun(vecdb & Xk)
{
	fitfun(Xk);
	dfy = f;
	dfy -= y;
	err = dfy.ssqr()/dfy.N;
}

void GaussApproximator::gradFun(vecdb & Xk)
{
	fitfun(Xk);
	dfy = f;
	dfy -= y; // (f-y)



	grad_data.x[0] = hexp;

	grad_data.x[1] =  hexp;
	grad_data.x[1] *= hf2;
	grad_data.x[1] *= Xk.x[0];

	grad_data.x[2] =  hexp;
	grad_data.x[2] *= hf1;
	grad_data.x[2] *= 2.0*Xk.x[0]/Xk.x[2];

	grad_data.x[3] = x;   

	grad_data.x[4] = 1.0; 
}

void GaussApproximator::GradErr(vecdb & Xk)
{
	gradFun(Xk);

	Grd.x[0] = 2 * dfy.scpr(hexp) / x.N;  // ???? ??????, ???  grad_data.x[0] = hexp
	Grd.x[1] = 2 * dfy.scpr(grad_data.x[1]) / x.N;
	Grd.x[2] = 2 * dfy.scpr(grad_data.x[2]) / x.N;
	Grd.x[3] = 2 * dfy.scpr(x) / x.N; // ???? ??????, ??? grad_data.x[3] = x;
	Grd.x[4] = 2 * dfy.sum() / x.N; // ???? ??????, ??? grad_data.x[4] = 1;
}

void GaussApproximator::HessErr(vecdb & Xk)
{
	GradErr(Xk);
	hessFun(Xk);

	H.fst(0, 0) = 2 * hexp.ssqr() / x.N; // ???? ??????, ??? grad_data.x[0] = hexp
	H.fst(1, 0) = H.fst(0, 1) = 2 * (hexp.scpr(grad_data.x[1]) + dfy.scpr(hess_data_12)) / x.N;
	H.fst(2, 0) = H.fst(0, 2) = 2 * (hexp.scpr(grad_data.x[2]) + dfy.scpr(hess_data_13)) / x.N;
	H.fst(3, 0) = H.fst(0, 3) = 2 * (hexp.scpr(x)) / x.N;
	H.fst(4, 0) = H.fst(0, 4) = 2 * (hexp.sum()) / x.N;

	H.fst(1, 1) = 2 * (grad_data.x[1].ssqr() + dfy.scpr(hess_data_22)) / x.N;
	H.fst(2, 1) = H.fst(1, 2) = 2 * (grad_data.x[1].scpr(grad_data.x[2]) + dfy.scpr(hess_data_23)) / x.N;
	H.fst(3, 1) = H.fst(1, 3) = 2 * (grad_data.x[1].scpr(x)) / x.N;
	H.fst(4, 1) = H.fst(1, 4) = 2 * (grad_data.x[1].sum()) / x.N;

	H.fst(2, 2) = 2 * (grad_data.x[2].ssqr() + dfy.scpr(hess_data_33)) / x.N;
	H.fst(3, 2) = H.fst(2, 3) = 2 * (grad_data.x[2].scpr(x)) / x.N;
	H.fst(4, 2) = H.fst(2, 4) = 2 * (grad_data.x[2].sum()) / x.N;

	H.fst(3, 3) = 2 * (x.ssqr()) / x.N;
	H.fst(3, 4) = H.fst(3, 4) = 0; // 2 * (x.sum) / x.N;  x.sum() ?????? ????? ?????? ?????? 0 (???????? ?? x:  ?? -1 ?? 1)

	H.fst(4, 4) = 2.0; // 

}

void GaussApproximator::hessFun(vecdb & Xk)
{
	double c1;
	c1 *= c1 = Xk.x[2];
	/*hf2 = x;
	hf2 -= Xk.x[1];
	hf2 *= 2.0 / (c1); // 2*(x-B)/C^2*/

	hess_data_12 = hexp; // ?????? ??????????? ??????
	hess_data_12 *= hf2;

	hess_data_13 = hexp;
	hess_data_13 *= hf1;
	hess_data_13 *= (2.0 / Xk.x[2]);

	hess_data_22 = hf1;
	hess_data_22 *= 2.0;
	hess_data_22 -= 1;
	hess_data_22 *= hexp;
	hess_data_22 *= 2 * Xk.x[0] / (c1);

	hess_data_23 = hf1;
	hess_data_23 -= 1;
	hess_data_23 *= hexp;
	hess_data_23 *= hf2;
	hess_data_23 *= (2 * Xk.x[0] / Xk.x[2]);

	hess_data_33 = hf1;
	hess_data_33 *= 2.0;
	hess_data_33 -= 3.0;
	hess_data_33 *= hexp;
	hess_data_33 *= hf1;
	hess_data_33 *= (2 * Xk.x[0]/c1);
}



void GaussApproximator::initguess(vecdb & Xk)
{
	Xk.x[4] = (y.x[0] + y.last()) / 2;
	Xk.x[3] = (y.last() - y.x[0]) / 2;
	f = y - Xk.x[3] * x - Xk.x[4];
	for (int ii = 0; ii < f.N; ii++) if (f.x[ii] < 0) f.x[ii] = 0;
	err = f.sum();
	hf1 = f;
	hf1 *= x;
	Xk.x[1] = hf1.sum() / err;
	hf1 = x;
	f *= hf1 *= hf1 -= Xk.x[1];
	Xk.x[2] = sqrt(f.sum() / err);
	Xk.x[0] = 1 - Xk.x[4];
}


void GaussApproximator::MinErrFind()
{
	double lmb, wk, eps;

	initguess(X);
	X_ = X;
	HessErr(X); // ?????? ??????????? ? ?????????
	R_ = S_ = -Grd;
	lmb = S_.ssqr() / (S_.scpr(H.pmv(S_, P)));
	X = X_ + S_*lmb;

	int kk;
	kk = 0;
	eps = R_.snrm();
	while ((eps > usr_eps)&(kk<usr_Nittr))
	{
		HessErr(X);
		R = -Grd;
		wk = R.ssqr() / R_.ssqr();
		S =  S_;
		S *= wk;
		S += R;
		lmb = R.scpr(S) / (S.scpr(H.pmv(S, P)));
		S_ = S;
		S *= lmb;
		X += S;
		R_ = R;
		eps = R.snrm();
		kk++;
	}
	if (kk >= usr_Nittr)
	{
		QMessageBox msgBox;
		msgBox.setText("\320\235\320\260\320\271\320\264\320\265\320\275\320\275\321\213\320\265\040\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213\040\320\260\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\320\270\040\320\275\320\265\040\320\276\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\321\213\056\040\012\320\230\320\267\320\274\320\265\320\275\320\270\321\202\320\265\040\320\276\320\261\320\273\320\260\321\201\321\202\321\214\040\320\260\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\320\270\056");
		msgBox.exec();
	}
	P = X; // 
	Finalize();
}

void GaussApproximator::Finalize()
{
	ErrFun(P);
	X_.x[0] = sqrt(2 * err / H.fst(0, 0));
	X_.x[1] = sqrt(2 * err / H.fst(1, 1));
	X_.x[2] = sqrt(2 * err / H.fst(2, 2));
	X_.x[3] = sqrt(2 * err / H.fst(3, 3));
	X_.x[4] = sqrt(2 * err / H.fst(4, 4));

	// ??????????? ? ????????? ????????
	X.x[0] = P.x[0] / ky;  
	X.x[1] = (P.x[1]-bx) / kx;
	X.x[2] = P.x[2] / kx;
	X.x[3] = P.x[3] * kx / ky;
	X.x[4] = (P.x[3] * (bx + kx * X.x[1])  + P.x[4] - by) / ky;

	X_.x[0] = X_.x[0] / ky;
	X_.x[1] = X_.x[1] / kx;
	X_.x[2] = X_.x[2] / kx;
	X_.x[4] = (X_.x[3]*X_.x[3]*(bx + kx*X.x[1])*(bx + kx*X.x[1]) + kx*kx*P.x[3]*P.x[3]*X_.x[1]*X_.x[1] + X_.x[4]*X_.x[4])/ky;
	X_.x[3] = X_.x[3] * kx / ky;

	X.x[0] *= sign; // ???? ????? ?? sign
	X.x[3] *= sign;
	X.x[4] *= sign;
	X.x[3] += k_; // ?????????????? ???????
	X.x[4] += b_+k_*X.x[1]; // ?????????????? ????????
	X_.x[4] = sqrt(X_.x[4]+k_*k_*X_.x[1]* X_.x[1]); // ???????? ?? ???????????
}

void GaussApproximator::Fun(vecdb  &xx, vecdb  &yy)
{
	yy.fsetlen(xx.N);
	double hh;
	for (int ii = 0; ii < xx.N; ii++)
	{
		hh *= hh = (xx.x[ii]-X.x[1]) / (X.x[2]);
		yy.x[ii] = X.x[0] * exp(-hh) + X.x[3]*(xx.x[ii] - X.x[1]) + X.x[4];
	}
}

#endif