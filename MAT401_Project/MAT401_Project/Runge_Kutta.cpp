#include "Runge_Kutta.h"
#include <iostream>
#include <iomanip>
Runge_Kutta::Runge_Kutta()
{
	maths_ = new math_library();
}

Runge_Kutta::~Runge_Kutta()
{
	maths_->~math_library();
	maths_ = nullptr;
	delete maths_;
}

std::vector<std::vector<double>> Runge_Kutta::RK4(double x0, double y0, double xe, double dx)
{
	std::vector<std::vector<double>> output;

	//Need to generate values between a start, a stop and using a step
	std::vector<double> x = maths_->Generate_Half_open_interval(dx, x0, xe);

	std::vector<double> y = maths_->Generate_zeros(x.size());

	y[0] = y0;

	for (int i = 1; i <= x.size() - 1; i++)
	{
		//std::cout << function(x[i-1], 1) << "\n";

		//std::cout << std::setprecision(8);

		//std::cout << y[i - 1] << "\n";

		//double k1 = 0.1 * function2(15, y[i - 1]);

		////std::cout << k1 << "\n";

		//double k2 = 0.1 * function2(15 + (0.1 / 2.0f), y[i - 1] + /*0.1f **/ (k1 / 2.0f));

		//double k3 = 0.1 * function2(15 + (0.1 / 2.0f), y[i - 1] + /*0.1f * */(k2 / 2.0f));

		//double k4 = 0.1 * function2(15 + 0.1, y[i - 1] + /*0.1f **/ (k3));

		//y[i] = y[i - 1] + (1.0f/6.0f * (k1 + (2.0f*k2) + (2.0f*k3) + k4));

		double k1 = dx * function(x[i - 1], y[i - 1]);

		double k2 = dx * function(x[i - 1] + dx / 2.0f, y[i - 1] + /*0.1f**/(k1 / 2.0f));

		double k3 = dx * function(x[i - 1] + dx / 2.0f, y[i - 1] + /*0.1f**/(k2 / 2.0f));

		double k4 = dx * function(x[i - 1] + dx, y[i - 1] + /*0.1f**/(k2));

		//std::cout << y[i] << "\n";

		y[i] = y[i - 1] + (1.0f/6.0f * (k1 + (2.0f*k2) + (2.0f*k3) + k4));
	}

	output = { x,y };

	return output;
}

std::vector<std::vector<double>> Runge_Kutta::RK2(double x0, double y0, double xe, double dx)
{
	std::vector<std::vector<double>> output;

	//Need to generate values between a start, a stop and using a step
	std::vector<double> x = maths_->Generate_Half_open_interval(dx, x0, xe);

	std::vector<double> y = maths_->Generate_zeros(x.size());

	y[0] = y0;

	//std::cout << x.size() << "\n";

	//std::cout << y.size() << "\n";

	//std::cout << std::setprecision(8);

	//double result  = function2(15,29.811);

	//std::cout << result << " whatever this is\n";

	for (int i = 1; i <= x.size()-1; i++)
	{
		//std::cout << function(15, y[i - 1]) << "\n";

		//std::cout << std::setprecision(8);

		//std::cout << y[i - 1] << "\n";

		double k1 = dx * function(x[i-1],y[i-1]);

		//std::cout << k1 << "\n";

		double k2 = dx * function(x[i - 1] + dx/2.0f, y[i - 1] + /*0.1f**/(k1/2.0f));
		y[i] = y[i - 1] + k2;

		//std::cout << y[i] << "\n";
	}

	output = { x,y };

	return output;
}
