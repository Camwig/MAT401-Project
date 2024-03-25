#include "Task_5.h"

Task_5::Task_5()
{
	maths_ = new math_library();
	std::vector<double> new_x = maths_->Generate_zeros(3);
	std::vector<double> new_y = maths_->Generate_zeros(3);

	Rotation_Matrix = { new_x,new_y };
}

Task_5::~Task_5()
{
	maths_->~math_library();
	maths_ = nullptr;
	delete maths_;
}

//Sets the values of the Rotation Matrix
void Task_5::Set_rotation_matrix(double alpha, double beta, double gamma, double theta)
{
	Rotation_Matrix	=	{{ ((alpha*alpha) * (1 - cos(theta))) + cos(theta),				((alpha * beta) * (1 - cos(theta))) - (gamma * sin(theta)),					((alpha * gamma) * (1 - cos(theta)) + (beta * sin(theta))) },
						{ ((alpha * beta) * (1 - cos(theta))) + (gamma * sin(theta)),		((beta*beta) * (1 - cos(theta))) + cos(theta),								((beta * gamma) * (1 - cos(theta))) - (alpha * sin(theta)) },
						{ ((alpha * gamma) * (1 - cos(theta))) - (beta * sin(theta)),		((beta * gamma) * (1 - cos(theta))) + (alpha * sin(theta)),					((gamma*gamma) * (1 - cos(theta))) + cos(theta) }};

}


void Task_5::Solve_Task_5(std::vector<std::vector<double>>& Omega_x, std::vector<std::vector<double>>& Omega_y, std::vector<std::vector<double>>& Omega_z, std::vector<std::vector<double>>& Position_x, std::vector<std::vector<double>>& Position_y, std::vector<std::vector<double>>& Position_z, double Step, double Start, double End, std::array<std::vector<double>, 3>& Output, std::array<double, 3> Initial_position_)
{
	double px = Initial_position_[0],
	py = Initial_position_[1],
	pz = Initial_position_[2];

	std::array<std::vector<double>,3> Resultant;

	Resultant[0] = maths_->Generate_zeros(End, Step);
	Resultant[1] = maths_->Generate_zeros(End, Step);
	Resultant[2] = maths_->Generate_zeros(End, Step);

	//x at 0		  Inital value x
	Resultant[0][0] = Initial_position_[0];
	//y at 0		  Inital value y
	Resultant[1][0] = Initial_position_[1];
	//z at 0		  Inital value z
	Resultant[2][0] = Initial_position_[2];

	double Multiple = 1;
	//If the Stepsize is less than one we use the multipe to still move along the vector based on the value increased to where there are no decimal points
	if (Step < 1)
		Multiple = 1 / Step;

	for (double i = (Start + Step) * Multiple; i <= (End * Multiple); i += (Step * Multiple))
	{
		//Calculate the magnitude of the vector to get the theta,alpha,beta and gamma values
		double magnitude = sqrt((Omega_x[0][i-1]* Omega_x[0][i - 1]) + (Omega_y[0][i - 1] * Omega_y[0][i - 1]) + (Omega_z[0][i - 1] * Omega_z[0][i - 1]));
		double theta = magnitude * (Step);

		double alpha = Omega_x[0][i - 1] / magnitude;
		double beta = Omega_y[0][i - 1] / magnitude;
		double gamma= Omega_z[0][i - 1] / magnitude;

		Set_rotation_matrix(alpha,beta,gamma,theta);

		std::vector<std::vector<double>> New_Output = { {px},{py},{pz} };
		//Calculate the result of the matrix multiplication between the New output(position of the object) matrix and the rotation matrix
		std::vector<std::vector<double>> Result = maths_->Matrix_multiplication(New_Output, Rotation_Matrix,3,1,3,3);

		//Set the new p values to be that of the newly calculated the rotational position
		px = Result[0][0];
		py = Result[1][0];
		pz = Result[2][0];

		Resultant[0][i] = Position_x[0][i - 1] + px;
		Resultant[1][i] = Position_y[0][i - 1] + py;
		Resultant[2][i] = Position_z[0][i - 1] + pz;
	}

	Output = Resultant;
}