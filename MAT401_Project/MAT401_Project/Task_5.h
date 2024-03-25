#pragma once

#include <array>
#include <variant>
#include "math_library.h"

class Task_5
{
public:
	Task_5();
	~Task_5();
	void Set_rotation_matrix(double alpha, double beta, double gamma, double theta);
	void Solve_Task_5(std::vector<std::vector<double>>& Omega_x, std::vector<std::vector<double>>& Omega_y, std::vector<std::vector<double>>& Omega_z, std::vector<std::vector<double>>& Position_x, std::vector<std::vector<double>>& Position_y, std::vector<std::vector<double>>& Position_z, double Step, double Start, double End, std::array<std::vector<double>, 3>&, std::array<double, 3> Initial_position_);
private:
	//2D vector to hold the rotation matrix
	std::vector<std::vector<double>> Rotation_Matrix;
	math_library* maths_;
};

