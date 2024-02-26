#include "Runge_Kutta.h"

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

std::vector<std::vector<float>> Runge_Kutta::RK2(float f, float x0, float y0, float xe, float dx)
{
	std::vector<std::vector<float>> output;

	//Need to generate values between a start, a stop and using a step
	std::vector<float> x = maths_->Generate_Half_open_interval(dx, x0, xe+dx);

	std::vector<float> y = maths_->Generate_zeros(x.size());

	y[0] = y0;

	for (int i = 1; i <= x.size(); i++)
	{
		float k1 = dx * function(x[i - 1], y[i - 1]);
		float k2 = dx * function(x[i - 1] + dx/2.0f, y[i - 1] + k1/2.0f);
		y[i] = y[i - 1] + k2;
	}

	output = { x,y };

	return output;
}
