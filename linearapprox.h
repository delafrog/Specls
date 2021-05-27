#ifndef LINEARAPPROX_H
#define LINEARAPPROX_H


#include "linalg.h" 

class LinearApproximator // класс для проведения аппроксимации данных функцией вида y(x) = A*exp(-((x-B)/C)^2)+D*x+E методом наименьших квадратов 
{
public:

	LinearApproximator() {};
	~LinearApproximator() {};

	const int dim = 5; // размерность аппроскимации - всего 5 параметров

	double kx, ky, bx, by; // коэффициенты для перевода данных в рабочий диапазон: x -> [-1..1]; y -> [-1..1];

	vecdb x, y; // данные для аппроксимации
	vecdb f; // аппроксимирующая функция (значния)

	double err; // ошибка аппроксимации
	double a,b,sga,sgb; // искомые коэффициеты линейной аппроскимации

	void setdata(vecdb &x_in, vecdb &y_in); // установка данных для аппроксимации

	void fitfun(vecdb &Xk); // вычисление функции аппроксимации
	void ErrFun(vecdb &Xk); // вычисление ошибки

	void MinErrFind(); // определение коэффициентов линейной аппроскимации
	void Finalize(); // возращение к исходному масштабу, вычисление доверитенльных интервалов 

	void Fun(vecdb &xx, vecdb &yy); // вычисление аппроксимирующей функции по аргументам xx результат - в yy (по параметрам из X)
};

#endif
