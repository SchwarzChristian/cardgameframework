/*
 * Disconnect.h
 *
 *  Created on: 24.03.2014
 *      Author: user
 */

#ifndef DISCONNECT_H_
#define DISCONNECT_H_

#include "Header.h"

class Disconnect : Header{
	Disconnect(uchar id) : Header(id, "close") {};
	std::string toString();
};

#endif /* DISCONNECT_H_ */
