/*
 * Protocol.cpp
 *
 *  Created on: 12.03.2014
 *      Author: user
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <cstdio>
#include <cstring>

#include "Protocol.h"

#ifndef BUFSIZE
#define BUFSIZE 1024
#endif

#define START "\x23\x42\x13\x37\x83\x42\x59\x06"

#define SHUTDOWN "shutdown\n\n"

#ifndef SLEEPTIME
#define SLEEPTIME 1000
#endif

#define SOCK_NEW		(-2)
#define SOCK_INIT		(-1)
#define SOCK_BOUND		0
#define SOCK_CONNECTED	1

typedef struct {
    unsigned long s_addr;          // load with inet_pton()
} In_addr;

typedef struct {
    short            sin_family;   // e.g. AF_INET, AF_INET6
    unsigned short   sin_port;     // e.g. htons(3490)
    In_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
} Sockaddr_in;

typedef struct {
    unsigned short    sa_family;    // address family, AF_xxx
    char              sa_data[14];  // 14 bytes of protocol address
} Sockaddr;

string* getPacket(int file, bool pvalid = false) {
	static string ret;
	bool valid = pvalid;
	char buf;
	char start[5];
	char null[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int i;
	ret = "";
	do {
		if (!read(file, &buf, 1)) return NULL;
		start[i] = buf;
		if (start[i] == START[i]) i++;
		if (i > 7) {
			memcpy(null, start, 8);
			ret.clear();
			i = 0;
			valid = true;
			continue;
		}
		ret += buf;
		if (ret.length() < 2) continue;
	} while (valid && ret.substr(ret.length() - 2) == "\n\n");

	return &ret;
}

// for servers communication with clients
bool forkClient(int port, int maxClients, int *ppsend, int *pprecv) {
	if (fork > 0) {
		int  server = 0;
		string *packet;
		Sockaddr_in serverAddr;
		server = socket(AF_INET, SOCK_STREAM, 0);
		if (server < 0) return false;

		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = INADDR_ANY;
		serverAddr.sin_port = htons(port);

		if ( bind(server, (sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) return false;
		else listen(server, 0);

		int  psend = ppsend[0];
		int  precv = pprecv[1];
		int  sock[maxClients];
		int  socks = 0;

		close(ppsend[1]);
		close(pprecv[0]);

		for (;;) {
			// route data from sockets to pipe
			packet->clear();
			for (int i = 0; i < socks; i++)
				if ((packet = getPacket(sock[i])))
					if (*packet == SHUTDOWN)
						write(precv, packet->c_str(), packet->length());

			// route data from pipe to the right socket
			packet->clear();
			while ((packet = getPacket(psend, true)))
				send(sock[(int)packet->at(9)], (string(START) + *packet).c_str(), packet->length() + 8, 0);

			// TODO accept-zeug

			usleep(SLEEPTIME);
		}
		for (int i = 0; i < socks; i++)
			close(sock[i]);
		close(ppsend[0]);
		close(pprecv[1]);
	}
	return true;
}

Protocol::Protocol(int port, int maxClients) {
	int ptmp[4];

	_status = SOCK_BOUND;
	pipe(ptmp);
	pipe(ptmp + 2);

	_psend = ptmp[1];
	_precv = ptmp[2];

	forkClient(PORT, maxClients > 256 ? 256 : maxClients, ptmp, ptmp + 2);

}

Protocol::Protocol(string addr, int port) {
	 sockaddr_in server;
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock < 0) {
		_status = SOCK_NEW;
		return;
	}

    server.sin_addr.s_addr = inet_addr(addr.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    _status = SOCK_CONNECTED;
    if (connect(_sock, (sockaddr *)&server, sizeof(server)) < 0) {
        _status = SOCK_BOUND;
    }
}

// TODO recv objects
void* Protocol::recvObj() {
	char* buf[BUFSIZE];
	recv(_sock, buf, BUFSIZE, 0);
	return (void*)*buf;
}

// TODO send objects
void Protocol::sendObj(void *data, int len) {
}

