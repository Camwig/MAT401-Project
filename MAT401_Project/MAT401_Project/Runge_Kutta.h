#pragma once
#include "math_library.h"
#include <cmath>

class Runge_Kutta
{
public:
	Runge_Kutta();
	~Runge_Kutta();

	std::vector<std::vector<double>> RK2(double x0, double y0, double xe, double dx);
	std::vector<std::vector<double>> RK4(double x0, double y0, double xe, double dx);
private:
	math_library* maths_;

	double inline function(double x, double y) {return  5.0f * (pow(x,4)); }

	double inline function2(double TE, double T) { 
		double i = TE - T;
		return  2*i; 
		}
};

