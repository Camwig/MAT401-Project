#include "Task_1_and_2.h"

Task_1_and_2::Task_1_and_2()
{
	maths_ = new math_library();
}

Task_1_and_2::~Task_1_and_2()
{
	maths_->~math_library();
	maths_ = nullptr;
	delete maths_;
}

std::array<double,3> Task_1_and_2::RK4_Task1(std::array<double, 3>& Upsilon, double Omega_x, double Omega_y,double Omega_z,double dx)
{
	//Loop 1 Correct
	//Loop 2 Correct
	//Loop 3 Correct

	//Should change this to output in doubles as floats cannot hold as much data

	//Will need a k1 to k4 for x,y and z.
	double k1_x = dx * Equation(Upsilon[0], Omega_y, Omega_z); //1,2,3
	double k1_y = dx * Equation(Upsilon[1], Omega_x, Omega_z); //1,2,3
	double k1_z = dx * Equation(Upsilon[2], Omega_x, Omega_y); //1,2,3

	double k2_x = dx * Equation(Upsilon[0], Omega_y + (k1_y / 2.0f), Omega_z + /*0.1f**/(k1_z / 2.0f));//1,2,3
	double k2_y = dx * Equation(Upsilon[1], Omega_x + (k1_x / 2.0f), Omega_z + /*0.1f**/(k1_z / 2.0f));//1,2,3
	double k2_z = dx * Equation(Upsilon[2], Omega_x + (k1_x / 2.0f), Omega_y + /*0.1f**/(k1_y / 2.0f));//1,2,3

	double k3_x = dx * Equation(Upsilon[0], Omega_y + (k2_y / 2.0f), Omega_z + /*0.1f**/(k2_z / 2.0f));//1,2,3
	double k3_y = dx * Equation(Upsilon[1], Omega_x + (k2_x / 2.0f), Omega_z + /*0.1f**/(k2_z / 2.0f));//1,2,3
	double k3_z = dx * Equation(Upsilon[2], Omega_x + (k2_x / 2.0f), Omega_y + /*0.1f**/(k2_y / 2.0f));//1,2,3

	double k4_x = dx * Equation(Upsilon[0], Omega_y + (k3_y), Omega_z + /*0.1f**/(k3_z));//1,2,3
	double k4_y = dx * Equation(Upsilon[1], Omega_x + (k3_x), Omega_z + /*0.1f**/(k3_z));//1,2,3
	double k4_z = dx * Equation(Upsilon[2], Omega_x + (k3_x), Omega_y + /*0.1f**/(k3_y));//1,2,3

	double Ouptut_x = Omega_x + (1.0f / 6.0f * (k1_x + (2.0f * k2_x) + (2.0f * k3_x) + k4_x));//1,2,3
	double Ouptut_y = Omega_y + (1.0f / 6.0f * (k1_y + (2.0f * k2_y) + (2.0f * k3_y) + k4_y));//1,2,3
	double Ouptut_z = Omega_z + (1.0f / 6.0f * (k1_z + (2.0f * k2_z) + (2.0f * k3_z) + k4_z));//1,2,3

	std::array<double, 3> output;
	output[0] = Ouptut_x;
	output[1] = Ouptut_y;
	output[2] = Ouptut_z;

	return output;


	//double k2 = dx * Equation(Upsilon, Omega_1 + dx / 2.0f, Omega_2 + /*0.1f**/(k1 / 2.0f));

	//double k3 = dx * function(x[i - 1] + dx / 2.0f, y[i - 1] + /*0.1f**/(k2 / 2.0f));

	//double k4 = dx * function(x[i - 1] + dx, y[i - 1] + /*0.1f**/(k2));

	//std::cout << y[i] << "\n";

	//double output = y[i - 1] + (1.0f / 6.0f * (k1 + (2.0f * k2) + (2.0f * k3) + k4));

	//return output;
}

void Task_1_and_2::Init(double M,double R, double H)
{
	//Inertia_Tensor = { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };

	double u = (3 * M) / 20.0f;

	double xx_yy = pow(R, 2) + (pow(H, 2) / 4.0f);

	xx_yy *= u;

	double zz = 2 * R;
	zz *= u;

	Inertia_Tensor = {xx_yy,	0,	0,
					  0,	xx_yy,	0,
					  0,	0,		zz};

	Centre_of_mass = { 0,0,0 };

	Upsilon[0] = (zz - xx_yy) / xx_yy;
	Upsilon[1] = (xx_yy - zz) / xx_yy;
	Upsilon[2] = (xx_yy - xx_yy) / zz;
}

void Task_1_and_2::Solve_Task_1(std::vector<std::vector<double>>& Out_X, std::vector<std::vector<double>>& Out_Y, std::vector<std::vector<double>>& Out_Z,double Initial_X,double Initial_Y,double Initial_Z,double Step,double Start,double End)
{
	std::vector<double> Times = maths_->Generate_Half_open_interval(Step, Start, End);

	//Set the intial value for these
	Omega_X = maths_->Generate_zeros(End,Step);
	Omega_Y = maths_->Generate_zeros(End, Step);
	Omega_Z = maths_->Generate_zeros(End, Step);

	Omega_X[0] = Initial_X;
	Omega_Y[0] = Initial_Y;
	Omega_Z[0] = Initial_Z;

	std::array<double, 3> Results;

	double Multiple = 1;

	if (Step < 1)
	{
		Multiple = 1 / Step;
	}


	for (double i = (Start + Step)*Multiple; i <= (End*Multiple); i += (Step*Multiple))
	{
		//RK4 Step which can then be given to the Output vectors

		Results = RK4_Task1(Upsilon, Omega_X[i - 1], Omega_Y[i - 1], Omega_Z[i - 1], Step);

		Omega_X[i] = Results[0];
		Omega_Y[i] = Results[1];
		Omega_Z[i] = Results[2];
	}

	Out_X = { Omega_X,Times };
	Out_Y = { Omega_Y,Times };
	Out_Z = { Omega_Z,Times };
}