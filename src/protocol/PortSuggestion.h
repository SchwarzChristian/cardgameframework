/*
 * PortSuggestion.h
 *
 *  Created on: 24.03.2014
 *      Author: user
 */

#ifndef PORTSUGGESTION_H_
#define PORTSUGGESTION_H_

#include "Header.h"

class PortSuggestion : Header {
private:
	int newPort;
public:
	PortSuggestion(uchar client, int port) : Header(client, "prtsg") {};
	std::string toString();
};

#endif /* PORTSUGGESTION_H_ */
