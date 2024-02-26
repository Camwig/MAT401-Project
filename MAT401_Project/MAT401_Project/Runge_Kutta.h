#pragma once
#include "math_library.h"
#include <cmath>

class Runge_Kutta
{
public:
	Runge_Kutta();
	~Runge_Kutta();

	std::vector<std::vector<float>> RK2(float f, float x0, float y0, float xe, float dx);
private:
	math_library* maths_;

	float inline function(float x, float y) {return  5.0f * (pow(x,4)); }

	float inline function2(float TE, float T) { 
		float i = TE - T;
		return  2*i; 
		}
};

