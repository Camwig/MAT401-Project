#pragma once

#include <iomanip>
#include <fstream>
#include <vector>

class Printer
{
public:
	Printer();
	~Printer();
	void Write_to_file(std::vector<double>& Output_1, std::string Out_name_1, std::vector<double>& Output_2, std::string Out_name_2, std::vector<double>& Output_3, std::string Out_name_3, std::vector<double>& Time_out);
	void Write_to_file(std::vector<double>& Output_1, std::string Out_name_1, std::vector<double>& Output_2, std::string Out_name_2, std::vector<double>& Output_3, std::string Out_name_3, std::vector<double>& Output_4, std::string Out_name_4, std::vector<double>& Output_5, std::string Out_name_5, std::vector<double>& Output_6, std::string Out_name_6, std::vector<double>& Time_out);
};

