/*
 * Command.h
 *
 *  Created on: 24.03.2014
 *      Author: user
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Header.h"

class Command : Header{
public:
	std::string key;
	std::string value;
	Command(uchar id, ) : Header(id, "cmdpk") {};
	std::string toString();
};

#endif /* COMMAND_H_ */
