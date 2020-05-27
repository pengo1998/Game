#include "Logger.h"

void Logger::Inf(std::string message) {
	SetConsoleTextAttribute(_HConsole, 8); // change console text color
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
	std::ofstream logFile;
	logFile.open("Log.txt", std::ios::out | std::ios::app);	// Create a filestream that appends and outputs to the sepcified file
	if (!logFile.is_open()) { Logger::Err("Failed to write to file!", false); return; } // make sure we actuall opened the file before writing
	logFile << message << std::endl; // write to file
	logFile.close(); // close file
}