#pragma once

#include <array>

class Task_1_and_2
{
public:
	Task_1_and_2();
	~Task_1_and_2();

	void Init(float, float, float);

private:

	std::array<std::array<float, 3>, 3> Inertia_Tensor;

	std::array<float, 3> Centre_of_mass;

	std::array<float, 3> Upsilon;
};

