#include "Logger.h"

void Logger::Inf(std::string message) {
	SetConsoleTextAttribute(_HConsole, 8);
	std::cout << "[INFO] ";
	SetConsoleTextAttribute(_HConsole, 7);
	std::cout << message << std::endl;
}


void Logger::War(std::string message) {
	SetConsoleTextAttribute(_HConsole, 6);
	std::cout << "[WARNING] ";
	SetConsoleTextAttribute(_HConsole, 7);
	std::cout << message << std::endl;
}


void Logger::Err(std::string message) {
	SetConsoleTextAttribute(_HConsole, 4);
	std::cout << "[ERROR] ";
	SetConsoleTextAttribute(_HConsole, 7);
	std::cout << message << std::endl;
}


void Logger::WriteToFile(std::string message) {
	static std::ofstream logFile;
	logFile.open("Log.txt", std::ios::out | std::ios::app);
	if (!logFile.is_open()) { Logger::Err("Failed to write to file!", false); return; }
	logFile << message << std::endl;
	logFile.close();
}