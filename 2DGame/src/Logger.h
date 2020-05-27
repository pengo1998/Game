#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <Windows.h>

class Logger
{
private:
	void WriteToFile(std::string message);

	std::string _Filename;
	HANDLE _HConsole;
public:
	Logger(std::string fileName)
		: _Filename(fileName), _HConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {}; // Initialize filename and console handle

	void Inf(std::string message);
	void War(std::string message);
	void Err(std::string message);
};

