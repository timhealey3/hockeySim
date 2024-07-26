#pragma once
#include <string>
#include <ctime>
#include <fstream> 
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
class GenerateName
{
private:
	std::vector<std::string> firstNames;
	std::vector<std::string> lastNames;
public:
	GenerateName();
	~GenerateName();
	void readNameFile();
	std::string generateName();
	std::string generateFirstName();
	std::string generateLastName();
};

