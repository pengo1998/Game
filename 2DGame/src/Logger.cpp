#include "Logger.h"

void Logger::Init()
{
	//_HConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Logger::Inf(std::string message) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // change console text color
	std::cout << "[INFO] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << message << std::endl;
}


void Logger::War(std::string message) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << "[WARNING] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << message << std::endl;
}


void Logger::Err(std::string message) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "[ERROR] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << message << std::endl;
}