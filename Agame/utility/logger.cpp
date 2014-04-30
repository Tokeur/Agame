#include "logger.h"

#include <ctime>
#include <iostream>

Logger::Logger() {
	// gets the current time
	std::time_t currenttime;
	time(&currenttime);

	// removes the line-end at the end of the returned value of ctime(time_t*) via a std::string
	std::string timestring(ctime(&currenttime));
	timestring.pop_back();

	_stream << "[" << timestring << "] ";
}

void Logger::_log() {
	std::cout << _stream.str() << std::endl;
	std::clog << _stream.str() << std::endl;
} //*/
