#include "Task_3_and_4.h"

Task_3_and_4::Task_3_and_4()
{
	maths_ = new math_library();
}

Task_3_and_4::~Task_3_and_4()
{
	maths_->~math_library();
	maths_ = nullptr;
	delete maths_;
}

//Init function to set the intial values for the x,y and z of the velocity and position values
void Task_3_and_4::Init(std::array<double, 3> Initial_velocity, std::array<double, 3> Initial_position)
{
	//x at 0		  Inital value x
	velocity[0][0] = Initial_velocity[0];
	//y at 0		  Inital value y
	velocity[1][0] = Initial_velocity[1];
	//z at 0		  Inital value z
	velocity[2][0] = Initial_velocity[2];

	position[0][0] = Initial_position[0];
	position[1][0] = Initial_position[1];
	position[2][0] = Initial_position[2];
}

double Task_3_and_4::Semi_Implict_Euler(double Initial_Value, double Diffrence, double Step)
{
	double Output = 0.0f;
	Output = Initial_Value + (Diffrence * Step);
	return Output;
}

void Task_3_and_4::Solve_Task_3(std::array<double, 3> Initial_velocity, std::array<double, 3> Initial_position,std::vector<std::vector<double>>& Out_Vx, std::vector<std::vector<double>>& Out_Vy, std::vector<std::vector<double>>& Out_Vz, std::vector<std::vector<double>>& Out_Px, std::vector<std::vector<double>>& Out_Py, std::vector<std::vector<double>>& Out_Pz, double Step, double Start, double End)
{
	std::vector<double> Times = maths_->Generate_Half_open_interval(Step, Start, End);

	velocity[0] = maths_->Generate_zeros(End, Step);
	velocity[1] = maths_->Generate_zeros(End, Step);
	velocity[2] = maths_->Generate_zeros(End, Step);

	position[0] = maths_->Generate_zeros(End, Step);
	position[1] = maths_->Generate_zeros(End, Step);
	position[2] = maths_->Generate_zeros(End, Step);

	Init(Initial_velocity,Initial_position);

	double Multiple = 1;
	//If the Stepsize is less than one we use the multipe to still move along the vector based on the value increased to where there are no decimal points
	if (Step < 1)
		Multiple = 1 / Step;

	for (double i = (Start + Step) * Multiple; i <= (End * Multiple); i += (Step * Multiple))
	{
		//Semi-implicit Euler
		velocity[0][i] = Semi_Implict_Euler(velocity[0][i-1],Gravity[0],Step);
		position[0][i] = Semi_Implict_Euler(position[0][i - 1], velocity[0][i], Step);

		velocity[1][i] = Semi_Implict_Euler(velocity[1][i - 1], Gravity[1], Step);
		position[1][i] = Semi_Implict_Euler(position[1][i - 1], velocity[1][i], Step);

		velocity[2][i] = Semi_Implict_Euler(velocity[2][i - 1], Gravity[2], Step);
		position[2][i] = Semi_Implict_Euler(position[2][i - 1], velocity[2][i], Step);
	}
	//Output the Velocity and positional values aswell as the Time values with them
	Out_Vx = { velocity[0],Times };
	Out_Vy = { velocity[1],Times };
	Out_Vz = { velocity[2],Times };

	Out_Px = { position[0],Times };
	Out_Py = { position[1],Times };
	Out_Pz = { position[2],Times };
}