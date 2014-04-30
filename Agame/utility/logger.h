#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>
#include <string>

/*!
 * \class Logger
 * \brief sends messages to the console
 *
 * A simple Logger class which sends debug messages to log file(s).
 *
 * \author Stan "DeinDall" H.
 */
class Logger {
public: // static
	/*!
	 * \brief log, sends a message to the log
	 *
	 * it writes into srd::cout and std::clog
	 *
	 * \param all items to print into the message, as individual arguments (which means separated by commas)
	 */
	template<class... Args>
	static void log(Args&&... args) {
		Logger logger;
		logger._push(std::forward<Args>(args)...);
		logger._log();
	}

private:
	template<class Type, class... Args>
	void _push(Type&& o, Args&&... args) {
		_push(std::forward<Type>(o));
		_push(std::forward<Args>(args)...);
	}

	template<class Type>
	void _push(Type&& o) {
		_stream << o;
	}

	Logger();
	void _log();
private:
	std::stringstream _stream;
};
#endif // LOGGER_H
