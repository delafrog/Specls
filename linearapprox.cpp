#ifndef LINARAPPROX_CPP
#define LINEARAPPROX_CPP

//#include <QMessageBox>
#include "linearapprox.h"
//#include "linalg.cpp"
#include "linalg.h"

//LinearApproximator::LinearApproximator(){}

void LinearApproximator::setdata(vecdb & x_in, vecdb & y_in)
{
	double mx, mn, yn, yx;

	x.fsetlen(x_in.N);
	y.fsetlen(y_in.N);
	f.fsetlen(x_in.N);

	mx = x_in.max();
	mn = x_in.min();
	kx = 2 / (mx - mn);
	bx = (mx + mn) / (mn - mx);

	yx = y_in.max();
	yn = y_in.min();
	ky = 2 / (yx - yn);
	by = (yx + yn) / (yn - yx);

	x = x_in;
	x *= kx;
	x += bx;

	y = y_in;
	y *= ky;
	y += by;
}

void LinearApproximator::fitfun(vecdb & Xk)
{
	f = Xk;
	f *= a;
	f += b;
}

void LinearApproximator::ErrFun(vecdb & Xk)
{
	vecdb dfy;
	fitfun(Xk);
	dfy = f;
	dfy -= y;
	err = dfy.ssqr() / dfy.N;
}

void LinearApproximator::MinErrFind()
{
	double dxdym,sdxm,sdym,mx,my;
	vecdb dx, dy;

	dx.setlen(x.N);
	dy.setlen(y.N);

	mx = x.sum() / x.N;
	my = y.sum() / y.N;

	dx = x;
	dx -= mx;

	dy = y;
	dy -= my;

	sdym = dy.snrm();
	sdxm = dx.snrm();
	dxdym = dx.scpr(dy) / dx.N;

	a = dxdym/sdxm;
	b = my - a*mx;

	sgb = sqrt(sdxm*sdym-dxdym*dxdym)/sqrt(double(dx.N));
	sga = sgb/sdxm;
	
	Finalize();
}

void LinearApproximator::Finalize()
{
	double a_, b_, sga_,sgb_;

	a_	 = a*kx / ky;
	sga_ = sga*kx / ky;

	b_ = (b-by+a*bx) / ky ;
	sgb_ = sqrt(sgb*sgb+sga*sga*bx*bx)/ky;

	a = a_;
	b = b_;
	sga = sga_;
	sgb = sgb_;
}

void LinearApproximator::Fun(vecdb  &xx, vecdb  &yy)
{
	yy.fsetlen(xx.N);
	yy = xx;
	yy *= a;
	yy += b;
}

#endif