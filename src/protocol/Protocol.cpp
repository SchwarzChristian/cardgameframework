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

#ifndef START
#define START "\x23\x42\x13\x37\x83\x42\x59\x06"
#endif


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

string splitPackets(string s = "") {
	static string buf = "";
	string ret = "";
	int pos, pos1;
	buf += s;
	pos = buf.find(START, 0);
	pos1 = buf.find(START, pos + 1);

	if (pos == 0)
	ret = buf.substr(pos, pos1 - pos);
	buf = buf.substr(pos1, buf.length() - pos1);
	return ret;
}

// for servers communication with clients
void forkClient(int sock, int* ppsend, int* pprecv) {
	char buf[BUFSIZE];
	int  len;
	int psend = ppsend[0];
	int precv = pprecv[1];
	if (fork > 0) do {
		close(ppsend[1]);
		close(pprecv[0]);
		usleep(SLEEPTIME);

		if ((len = recv(sock, buf, BUFSIZE, 0)) > 0 )
			write(precv, buf, len);

		if ((len = read(psend, buf, BUFSIZE)) > 0 )
			send(sock, buf, len, 0);
	} while(strcmp(buf + 6, "close"));
	close(ppsend[0]);
}

Protocol::Protocol(int port) {
	Sockaddr_in server;
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock < 0) {
		_status = SOCK_NEW;
		return;
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	for (int i = 0; i < 256; i++) {
		_psend[i] = -1;
	}

	_status = SOCK_BOUND;
	pipe(_precv);

	if ( bind(_sock,(sockaddr *)&server, sizeof(server)) < 0) {
		_status = SOCK_INIT;
		_precv[0] = -1;
		_precv[1] = -1;
	} else listen(_sock, 0);

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

void* Protocol::recvObj() {
	char* buf[BUFSIZE];
	recv(_sock, buf, BUFSIZE, 0);
	return (void*)*buf;
}

void Protocol::sendObj(void *data, int len) {
	send(_sock, data, len, 0);
}

void Protocol::waitForClients() {
	int ptmp[2];
	pipe(ptmp);
	for (int i = 0; i < 256; i++)
		if (_precv[i] < 0)
			_precv[i] = ptmp[0];
	forkClient(accept(_sock, NULL, NULL), ptmp, _precv);
}

Protocol::~Protocol() {
	close(_sock);
}

