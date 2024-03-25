#include "Printer.h"

Printer::Printer()
{

}

Printer::~Printer()
{

}

//Writes out the provided vectors to the test.csv file
void Printer::Write_to_file(std::vector<double>& Output_1, std::string Out_name_1, std::vector<double>& Output_2, std::string Out_name_2, std::vector<double>& Output_3, std::string Out_name_3, std::vector<double>& Time_out)
{
	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << Out_name_1;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_1.size(); i++)
	{
		my_file << Output_1.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_2;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_2.size(); i++)
	{
		my_file << Output_2.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_3;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_3.size(); i++)
	{
		my_file << Output_3.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file.close();
}

//Writes out the provided vectors to the test.csv file
void Printer::Write_to_file(std::vector<double>& Output_1, std::string Out_name_1, std::vector<double>& Output_2, std::string Out_name_2, std::vector<double>& Output_3, std::string Out_name_3, std::vector<double>& Output_4, std::string Out_name_4, std::vector<double>& Output_5, std::string Out_name_5, std::vector<double>& Output_6, std::string Out_name_6, std::vector<double>& Time_out)
{
	std::ofstream my_file("test.csv");

	my_file << std::setprecision(10);

	my_file << Out_name_1;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_1.size(); i++)
	{
		my_file << Output_1.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_2;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_2.size(); i++)
	{
		my_file << Output_2.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_3;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_3.size(); i++)
	{
		my_file << Output_3.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_4;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_4.size(); i++)
	{
		my_file << Output_4.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_5;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_5.size(); i++)
	{
		my_file << Output_5.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file << Out_name_6;

	my_file << ",";

	my_file << "Time";

	my_file << std::endl;

	for (int i = 0; i < Output_6.size(); i++)
	{
		my_file << Output_6.at(i) << ",";
		my_file << Time_out[i] << std::endl;
	}

	my_file << std::endl;
	my_file << std::endl;

	my_file.close();
}
