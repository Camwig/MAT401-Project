#pragma once
#include <vector>
class math_library
{
public:
	math_library();
	~math_library();

	std::vector<double> Generate_Half_open_interval(double step, double start, double end);

	std::vector<double> Generate_zeros(double length);
	std::vector<double> Generate_zeros(double length,double step);

	std::vector<std::vector<double>> Matrix_multiplication(std::vector<std::vector<double>>& Matrix_1, std::vector<std::vector<double>>& Matrix_2, int R1, int C1, int R2, int C2);
};

