/*
 * Protocol.h
 *
 *  Created on: 12.03.2014
 *      Author: user
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <string>
#include <unistd.h>

#ifndef PORT
#define PORT 1337
#endif

using namespace std;

class Protocol {
private:
	int _sock;
	int _status;
	int _precv[2];
	int _psend[256];
public:
	Protocol(int port = PORT);				// server
	Protocol(string addr, int port = PORT);	// client
	void sendObj(void* data, int length);
	void* recvObj();
	void waitForClients();
	virtual ~Protocol();
};

#endif /* PROTOCOL_H_ */
