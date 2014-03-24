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
	int _status;
	int _sock;
	int _psend;		// data that should be send
	int _precv;		// data that should be received
public:
	Protocol(int port = PORT, int maxClients = 256);				// server
	Protocol(string addr, int port = PORT);	// client
	void sendObj(void* data, int length);
	void* recvObj();
};

#endif /* PROTOCOL_H_ */
