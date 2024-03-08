#pragma once

#include <vector>
#include <array>
#include "math_library.h"

class Task_1_and_2
{
public:
	Task_1_and_2();
	~Task_1_and_2();

	void Init(float M, float R, float H);

	void Solve_Task_1(std::vector<std::vector<float>>& Out_X, std::vector<std::vector<float>>& Out_Y, std::vector<std::vector<float>>& Out_Z, float Initial_X, float Initial_Y, float Initial_Z, float Step, float Start, float End);
private:

	std::array<float, 3> RK4_Task1(std::array<float,3>&, float, float,float,float);

	float inline Equation(float upslion, float Omega_1, float Omega_2)
	{
		return -1 * (upslion * Omega_1 * Omega_2);
	}

	std::array<std::array<float, 3>, 3> Inertia_Tensor;

	std::array<float, 3> Centre_of_mass;

	std::array<float, 3> Upsilon;

	std::vector<float> Omega_X;
	std::vector<float> Omega_Y;
	std::vector<float> Omega_Z;

	math_library* maths_;
};

