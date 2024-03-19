#pragma once

#include <array>
#include "math_library.h"

class Task_5
{
public:
	Task_5();
	~Task_5();
	void Set_rotation_matrix(double alpha, double beta, double gamma, double theta);
	void Solve_Task_5(std::vector<std::vector<double>>& Omega_x, std::vector<std::vector<double>>& Omega_y, std::vector<std::vector<double>>& Omega_z, std::vector<std::vector<double>>& Position_x, std::vector<std::vector<double>>& Position_y, std::vector<std::vector<double>>& Position_z, std::vector<std::vector<double>>& Velocity_x, std::vector<std::vector<double>>& Velocity_y, std::vector<std::vector<double>>&Velocity_z, double Step, double Start, double End, std::vector<std::vector<double>>&);
private:
	std::array<std::array<double, 3>, 3> Rotation_Matrix;
	math_library* maths_;
};

