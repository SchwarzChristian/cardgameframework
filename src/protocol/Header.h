/*
 * header.h
 *
 *  Created on: 24.03.2014
 *      Author: user
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <string>

typedef unsigned char uchar;

class Header {
private:
	uchar clientID;
	char type[5];
public:
	Header(uchar id, char* type);
	virtual std::string& toString() = 0;
};

#endif /* HEADER_H_ */
