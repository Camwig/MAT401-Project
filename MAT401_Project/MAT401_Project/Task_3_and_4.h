#pragma once
#include <array>
#include "math_library.h"

class Task_3_and_4
{
public:
	Task_3_and_4();
	~Task_3_and_4();

	void Init(std::array<double,3> Initial_velocity, std::array<double, 3> Initial_position);
	void Solve_Task_3(std::array<double, 3> Initial_velocity, std::array<double, 3> Initial_position,std::vector<std::vector<double>>& Out_Vx, std::vector<std::vector<double>>& Out_Vy, std::vector<std::vector<double>>& Out_Vz, std::vector<std::vector<double>>& Out_Px, std::vector<std::vector<double>>& Out_Py, std::vector<std::vector<double>>& Out_Pz, double Step, double Start, double End);

	double Semi_Implict_Euler(double Initial_Value, double Diffrence, double Step);

private:
	std::array<std::vector<double>, 3> velocity;
	std::array<std::vector<double>, 3> position;
	const double Gravity = -9.8f;
	math_library* maths_;
};

