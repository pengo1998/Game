#pragma once // Only include Random thing ONE TIME so it doesnt keep going like a nerd
#include <iostream>
#include <string>
#include <fstream>

#include <Windows.h>

class Logger
{
public:
	static void Init();
	static void Inf(std::string message);
	static void War(std::string message);
	static void Err(std::string message);
};

