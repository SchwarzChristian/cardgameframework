/*
 * ConnectionRequest.h
 *
 *  Created on: 24.03.2014
 *      Author: user
 */

#include "Header.h"

#ifndef CONNECTIONREQUEST_H_
#define CONNECTIONREQUEST_H_

class ConnectionRequest : Header {
private:
	std::string name;
public:
	ConnectionRequest(uchar id = 255) : Header(id, "conrq") {};
	std::string toString();
};

#endif /* CONNECTIONREQUEST_H_ */
