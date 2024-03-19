#pragma once

#include <array>
#include "math_library.h"

class Task_5
{
public:
	Task_5();
	~Task_5();
	void Set_rotation_matrix(double alpha, double beta, double gamma, double theta);
	void Solve_Task_5();
private:
	std::array<std::array<double, 3>, 3> Rotation_Matrix;
};

