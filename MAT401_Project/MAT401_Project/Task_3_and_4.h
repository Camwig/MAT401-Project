#pragma once
#include <array>
#include "math_library.h"

class Task_3_and_4
{
public:
	Task_3_and_4();
	~Task_3_and_4();

	void Init(std::array<float,3> Initial_velocity, std::array<float, 3> Initial_position);

private:
	std::array<float, 3> velocity;
	std::array<float, 3> position;
	const float Gravity = -9.8f;
	math_library* maths_;
};

