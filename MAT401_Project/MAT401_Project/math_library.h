#pragma once
#include <vector>
class math_library
{
public:
	math_library();
	~math_library();

	std::vector<float> Generate_Half_open_interval(float step, float start,float end);

	std::vector<float> Generate_zeros(float length);
};

