/*
 * Protocol.cpp
 *
 *  Created on: 12.03.2014
 *      Author: user
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include "Protocol.h"

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

Protocol::Protocol() {
	_sock = socket(AF_INET, SOCK_STREAM, 0);
}

Protocol::Protocol(int port) {
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	Sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	_status = 1;
	//Bind
	if ( bind(_sock,(sockaddr *)&server , sizeof(server)) < 0) {
		_status = 0;
	}

}

Protocol::Protocol(string addr, int port) {
	_sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(addr.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    _status = 2;
    if (connect(_sock, (sockaddr *)&server , sizeof(server)) < 0) {
        _status = 0;
    }
}

Protocol::~Protocol() {

}
