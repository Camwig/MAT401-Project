#pragma once
#include <vector>
class math_library
{
public:
	math_library();
	~math_library();

	std::vector<double> Generate_Half_open_interval(double step, double start, double end);

	std::vector<double> Generate_zeros(double length);
};

