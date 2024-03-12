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

void Task_3_and_4::Init(std::array<float, 3> Initial_velocity, std::array<float, 3> Initial_position)
{
	velocity[0][0] = Initial_velocity[0];
	velocity[1][0] = Initial_velocity[1];
	velocity[2][0] = Initial_velocity[2];

	position[0][0] = Initial_position[0];
	position[1][0] = Initial_position[1];
	position[2][0] = Initial_position[2];
}

float Task_3_and_4::Semi_Implict_Euler(float Initial_Value, float Diffrence, float Step)
{
	float Output = 0.0f;
	Output = Initial_Value + (Diffrence * Step);
	return Output;
}

void Task_3_and_4::Solve_Task_3(std::array<float, 3> Initial_velocity, std::array<float, 3> Initial_position,std::vector<std::vector<float>>& Out_Vx, std::vector<std::vector<float>>& Out_Vy, std::vector<std::vector<float>>& Out_Vz, std::vector<std::vector<float>>& Out_Px, std::vector<std::vector<float>>& Out_Py, std::vector<std::vector<float>>& Out_Pz, float Step, float Start, float End)
{
	std::vector<float> Times = maths_->Generate_Half_open_interval(Step, Start, End);

	velocity[0] = maths_->Generate_zeros(End);
	velocity[1] = maths_->Generate_zeros(End);
	velocity[2] = maths_->Generate_zeros(End);

	position[0] = maths_->Generate_zeros(End);
	position[1] = maths_->Generate_zeros(End);
	position[2] = maths_->Generate_zeros(End);

	Init(Initial_velocity,Initial_position);


	for (float i = Start; i <= End - 1; i += Step)
	{
		//Semi-implicit Euler
		velocity[0][i] = Semi_Implict_Euler(velocity[0][i-1],Gravity,Step);
		position[0][i] = Semi_Implict_Euler(position[0][i - 1], velocity[0][i], Step);

		velocity[1][i] = Semi_Implict_Euler(velocity[1][i - 1], Gravity, Step);
		position[1][i] = Semi_Implict_Euler(position[1][i - 1], velocity[1][i], Step);

		velocity[2][i] = Semi_Implict_Euler(velocity[2][i - 1], Gravity, Step);
		position[2][i] = Semi_Implict_Euler(position[2][i - 1], velocity[2][i], Step);
	}

	Out_Vx = { velocity[0],Times };
	Out_Vy = { velocity[1],Times };
	Out_Vz = { velocity[2],Times };

	Out_Px = { position[0],Times };
	Out_Py = { position[1],Times };
	Out_Pz = { position[2],Times };
}