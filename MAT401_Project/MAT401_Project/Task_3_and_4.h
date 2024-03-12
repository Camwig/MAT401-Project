#pragma once
#include <array>
#include "math_library.h"

class Task_3_and_4
{
public:
	Task_3_and_4();
	~Task_3_and_4();

	void Init(std::array<float,3> Initial_velocity, std::array<float, 3> Initial_position);
	void Solve_Task_3(std::array<float, 3> Initial_velocity, std::array<float, 3> Initial_position,std::vector<std::vector<float>>& Out_Vx, std::vector<std::vector<float>>& Out_Vy, std::vector<std::vector<float>>& Out_Vz, std::vector<std::vector<float>>& Out_Px, std::vector<std::vector<float>>& Out_Py, std::vector<std::vector<float>>& Out_Pz, float Step, float Start, float End);

	float Semi_Implict_Euler(float Initial_Value,float Diffrence,float Step);

private:
	std::array<std::vector<float>, 3> velocity;
	std::array<std::vector<float>, 3> position;
	const float Gravity = -9.8f;
	math_library* maths_;
};

