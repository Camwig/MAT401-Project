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

//Will need to fill this out but I can do that later I just need to make sure I get the basics correct first

void Task_5::Set_rotation_matrix(double alpha, double beta, double gamma, double theta)
{
	//Rotation_Matrix = { (pow(alpha,2))*(1 - cos(theta)) + cos(theta),				(alpha*beta)*(1-cos(theta)+(gamma*sin(theta))),				(alpha * gamma) * (1 - cos(theta) + (beta * sin(theta))),	0,
	//					(alpha * beta)* (1 - cos(theta) + (gamma * sin(theta))),	(pow(beta,2))* (1 - cos(theta)) + cos(theta),				(beta * gamma)* (1 - cos(theta) + (alpha * sin(theta))),	0,
	//					(alpha * gamma)* (1 - cos(theta) + (beta * sin(theta))),	(beta * gamma)* (1 - cos(theta) + (alpha * sin(theta))),	(pow(gamma,2))* (1 - cos(theta)) + cos(theta),				0,
	//					0,															0,											0,																			1};
	
	//Should be okay as I beleive that sin and cos are expecting radian based inputs for themselves but rember that is the case

	Rotation_Matrix[0][0] = (pow(alpha, 2)) * (1 - cos(theta)) + cos(theta);
	Rotation_Matrix[0][1] = (alpha * beta) * (1 - cos(theta) + (gamma * sin(theta)));
	Rotation_Matrix[0][2] = (alpha * gamma) * (1 - cos(theta) + (beta * sin(theta)));

	Rotation_Matrix[1][0] = (alpha * beta) * (1 - cos(theta) + (gamma * sin(theta)));
	Rotation_Matrix[1][1] = (pow(beta, 2)) * (1 - cos(theta)) + cos(theta);
	Rotation_Matrix[1][2] = (beta * gamma) * (1 - cos(theta) + (alpha * sin(theta)));

	Rotation_Matrix[2][0] = (alpha * gamma) * (1 - cos(theta) + (beta * sin(theta)));
	Rotation_Matrix[2][1] = (beta * gamma) * (1 - cos(theta) + (alpha * sin(theta)));
	Rotation_Matrix[2][2] = (pow(gamma, 2)) * (1 - cos(theta)) + cos(theta);


	//Rotation_Matrix = { (pow(alpha,2)) * (1 - cos(theta)) + cos(theta),				(alpha * beta) * (1 - cos(theta) + (gamma * sin(theta))),				(alpha * gamma) * (1 - cos(theta) + (beta * sin(theta))),
	//				(alpha * beta) * (1 - cos(theta) + (gamma * sin(theta))),	(pow(beta,2)) * (1 - cos(theta)) + cos(theta),								(beta * gamma) * (1 - cos(theta) + (alpha * sin(theta))),
	//				(alpha * gamma) * (1 - cos(theta) + (beta * sin(theta))),	(beta * gamma) * (1 - cos(theta) + (alpha * sin(theta))),					(pow(gamma,2)) * (1 - cos(theta)) + cos(theta)			};

	//Rotation_Matrix.at[0];
}

//Pass in by refrence so Im not copying all this stuff over constantly
void Task_5::Solve_Task_5(std::vector<std::vector<double>>& Omega_x, std::vector<std::vector<double>>& Omega_y, std::vector<std::vector<double>>& Omega_z, std::vector<std::vector<double>>& Position_x, std::vector<std::vector<double>>& Position_y, std::vector<std::vector<double>>& Position_z, std::vector<std::vector<double>>& Velocity_x, std::vector<std::vector<double>>& Velocity_y, std::vector<std::vector<double>>& Velocity_z, double Step, double Start, double End, std::variant <std::vector<std::array<double, 3>>>& Output)
{
	std::vector<double> Times = maths_->Generate_Half_open_interval(Step, Start, End);

	//Shouldnt use these here will need to use something with three sets of vectors
	std::vector<double> New_output_x = maths_->Generate_zeros(End);// Will need to figure out a way to fill this with zeroes
	std::vector<double> New_output_y = maths_->Generate_zeros(End);
	std::vector<double> New_output_z = maths_->Generate_zeros(End);

	std::array<std::vector<double>,3> Resultant;

	Resultant[0] = maths_->Generate_zeros(End);
	Resultant[1] = maths_->Generate_zeros(End);
	Resultant[2] = maths_->Generate_zeros(End);

	//This below is disgusting and should be changed please I beg you!!!!!
	//--------------------------------------------------------------------------

	std::vector<double> pos_values_x = maths_->Generate_zeros(End);
	std::vector<double> vel_values_x = maths_->Generate_zeros(End);

	for (int i = 0; i < Position_x.size(); i++)
	{
		for (int j = 0; j < Position_x[i].size(); j++)
		{
			pos_values_x[j] = Position_x[i][j];
		}
		break;
	}

	for (int i = 0; i < Velocity_x.size(); i++)
	{
		for (int j = 0; j < Velocity_x[i].size(); j++)
		{
			vel_values_x[j] = Velocity_x[i][j];
		}
		break;
	}

	std::vector<double> pos_values_y = maths_->Generate_zeros(End);
	std::vector<double> vel_values_y = maths_->Generate_zeros(End);

	for (int i = 0; i < Position_y.size(); i++)
	{
		for (int j = 0; j < Position_y[i].size(); j++)
		{
			pos_values_y[j] = Position_y[i][j];
		}
		break;
	}

	for (int i = 0; i < Velocity_y.size(); i++)
	{
		for (int j = 0; j < Velocity_y[i].size(); j++)
		{
			vel_values_y[j] = Velocity_y[i][j];
		}
		break;
	}

	std::vector<double> pos_values_z = maths_->Generate_zeros(End);
	std::vector<double> vel_values_z = maths_->Generate_zeros(End);

	for (int i = 0; i < Position_z.size(); i++)
	{
		for (int j = 0; j < Position_z[i].size(); j++)
		{
			pos_values_z[j] = Position_z[i][j];
		}
		break;
	}

	for (int i = 0; i < Velocity_z.size(); i++)
	{
		for (int j = 0; j < Velocity_z[i].size(); j++)
		{
			vel_values_z[j] = Velocity_z[i][j];
		}
		break;
	}

	std::vector<double> ome_values_x = maths_->Generate_zeros(End);
	std::vector<double> ome_values_y = maths_->Generate_zeros(End);
	std::vector<double> ome_values_z = maths_->Generate_zeros(End);

	for (int i = 0; i < Omega_x.size(); i++)
	{
		for (int j = 0; j < Omega_x[i].size(); j++)
		{
			ome_values_x[j] = Omega_x[i][j];
		}
		break;
	}

	for (int i = 0; i < Omega_y.size(); i++)
	{
		for (int j = 0; j < Omega_y[i].size(); j++)
		{
			ome_values_y[j] = Omega_y[i][j];
		}
		break;
	}

	for (int i = 0; i < Omega_z.size(); i++)
	{
		for (int j = 0; j < Omega_z[i].size(); j++)
		{
			ome_values_x[j] = Omega_z[i][j];
		}
		break;
	}

	//--------------------------------------------------------------------------
	float theta, alpha, beta, gamma,magnitude;

	for (double i = Start; i <= End - 1; i += Step)
	{
		//Need to do the full matrix additive stuff but it makes more sense to do all the x,y and z values as matrix at a time

		//(Rotation_Matrix * New_output_x[i - 1])

		//Need to setup the rotation matrix
		
		magnitude = sqrt(pow(ome_values_x[i], 2) + pow(ome_values_y[i], 2) + pow(ome_values_z[i], 2));
		//Theta outputs as radians
		theta = magnitude*Step;

		alpha = ome_values_x[i] / magnitude;
		beta = ome_values_y[i] / magnitude;
		gamma= ome_values_z[i] / magnitude;

		Set_rotation_matrix(alpha,beta,gamma,theta);

		New_output_x[i] = pos_values_x [i]+ (Step * vel_values_x[i]);
		New_output_y[i] = pos_values_y[i] + (Step * vel_values_y[i]);
		New_output_y[i] = pos_values_z[i] + (Step * vel_values_z[i]);

		std::vector<double> Row = maths_->Generate_zeros(3);

		Row[0] = New_output_x[i-1];
		Row[1] = New_output_y[i-1];
		Row[2] = New_output_z[i-1];

		std::vector<double> Column = maths_->Generate_zeros(1);

		std::vector<std::vector<double>> New_Output = {Row,Column};

		std::vector<std::vector<double>> Result = maths_->Matrix_multiplication(New_Output, Rotation_Matrix,Row.size(),Column.size(),4,4);

		for (int z = 0; z < Result.size(); i++)
		{
			New_output_x[i] += Result[z][0];
			New_output_y[i] += Result[z][1];
			New_output_z[i] += Result[z][2];
		}

		// r(timestep) = Position(at timestep)(Task 3) + timestep*(velocity)(Task 3) + RotationMatrix*r(n-1) - Should all in all result in a 3 row matrix with x,y and z

	}

	Resultant[0] = New_output_x;
	Resultant[1] = New_output_y;
	Resultant[2] = New_output_z;

	//omega = {alpha,beta,gamma}

	//r = r(cm,dt) + dt*vcm + RotationMatrix*unitvector of r(dt) 
	//r = 1.		 5.		  2.3.4.			 

	//Before any of this will need to use Task 1 and 3 for those values

	//1. Centre of mass position at time step point Courtesy of task 3

	//2. Theta value = maginitude of omega * the timestep point omega courtesy of task 1.

	//3.alpha beta and gamma are equal to the omega values(x,y,z) each divided by the magnitude for a unit vector

	//4. Rotation matrix * alpha ,beta and gamma vector
	//		Will need to figure out a way to create a matrix multiplication thing hopefully the standard library has one

	//5. timestep point multiplied by the velocity at the time step position cuortesy of task 3.

	//
	// r(timestep) = Position(at timestep)(Task 3) + timestep*(velocity)(Task 3) + RotationMatrix*r(n-1)
	//

	//Needs to just be looped over no real fancy method needed


}