#pragma once

#include <vector>
#include <array>
#include "math_library.h"

class Task_1_and_2
{
public:
	Task_1_and_2();
	~Task_1_and_2();

	void Init(double M, double R, double H);

	void Solve_Task_1(std::vector<std::vector<double>>& Out_X, std::vector<std::vector<double>>& Out_Y, std::vector<std::vector<double>>& Out_Z, double Initial_X, double Initial_Y, double Initial_Z, double Step, double Start, double End);
private:

	std::array<double, 3> RK4_Task1(std::array<double,3>&, double, double,double,double);

	//Inline function to solve the provide equation of task 1 and 2
	double inline Equation(double upslion, double Omega_1, double Omega_2)
	{
		return -1 * (upslion * Omega_1 * Omega_2);
	}

	std::array<std::array<double, 3>, 3> Inertia_Tensor;

	std::array<double, 3> Upsilon;
	//Vectors to hold the Omega values
	std::vector<double> Omega_X;
	std::vector<double> Omega_Y;
	std::vector<double> Omega_Z;

	math_library* maths_;
};

