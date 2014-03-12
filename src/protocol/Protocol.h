/*
 * Protocol.h
 *
 *  Created on: 12.03.2014
 *      Author: user
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <string>

using namespace std;

class Protocol {
private:
	int _sock;
	int _status;
public:
	Protocol();
	Protocol(int port);
	Protocol(string addr, int port);
	virtual ~Protocol();
};

#endif /* PROTOCOL_H_ */
