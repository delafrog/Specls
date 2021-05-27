#ifndef LINEARAPPROX_H
#define LINEARAPPROX_H


#include "linalg.h" 

class LinearApproximator // ����� ��� ���������� ������������� ������ �������� ���� y(x) = A*exp(-((x-B)/C)^2)+D*x+E ������� ���������� ��������� 
{
public:

	LinearApproximator() {};
	~LinearApproximator() {};

	const int dim = 5; // ����������� ������������� - ����� 5 ����������

	double kx, ky, bx, by; // ������������ ��� �������� ������ � ������� ��������: x -> [-1..1]; y -> [-1..1];

	vecdb x, y; // ������ ��� �������������
	vecdb f; // ���������������� ������� (�������)

	double err; // ������ �������������
	double a,b,sga,sgb; // ������� ����������� �������� �������������

	void setdata(vecdb &x_in, vecdb &y_in); // ��������� ������ ��� �������������

	void fitfun(vecdb &Xk); // ���������� ������� �������������
	void ErrFun(vecdb &Xk); // ���������� ������

	void MinErrFind(); // ����������� ������������� �������� �������������
	void Finalize(); // ���������� � ��������� ��������, ���������� �������������� ���������� 

	void Fun(vecdb &xx, vecdb &yy); // ���������� ���������������� ������� �� ���������� xx ��������� - � yy (�� ���������� �� X)
};

#endif
