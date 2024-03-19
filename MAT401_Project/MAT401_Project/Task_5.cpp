#include "Task_5.h"

Task_5::Task_5()
{
	maths_ = new math_library();
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
	Rotation_Matrix = { (pow(alpha,2))*(1 - cos(theta)) + cos(theta),	0,	0,
					    0,	0,	0,
					    0,	0,  0 };
}

//Pass in by refrence so Im not copying all this stuff over constantly
void Task_5::Solve_Task_5(std::vector<std::vector<double>>& Omega_x, std::vector<std::vector<double>>& Omega_y, std::vector<std::vector<double>>& Omega_z, std::vector<std::vector<double>>& Position_x, std::vector<std::vector<double>>& Position_y, std::vector<std::vector<double>>& Position_z, std::vector<std::vector<double>>& Velocity_x, std::vector<std::vector<double>>& Velocity_y, std::vector<std::vector<double>>& Velocity_z, double Step, double Start, double End, std::vector<std::vector<double>>& Output)
{
	std::vector<double> Times = maths_->Generate_Half_open_interval(Step, Start, End);



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
	// r(timestep) = Position(at timestep)(Task 3) + timestep(velocity)(Task 3) + RotationMatrix*r(n-1)
	//

	//Needs to just be looped over no real fancy method needed


}