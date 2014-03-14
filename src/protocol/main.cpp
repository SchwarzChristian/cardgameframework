/*
 * main.cpp
 *
 *  Created on: 13.03.2014
 *      Author: user
 */

#include <iostream>

#include <unistd.h>
#include <cstring>

#include "Protocol.h"

using namespace std;

int main() {
	if (fork() > 0) {
		char* bla = "LALALAL";
		sleep(1);
		Protocol p("127.0.0.1");
		p.sendObj(bla, strlen(bla) - 1);
		p.sendObj(bla, strlen(bla) - 1);
		p.sendObj(bla, strlen(bla) - 1);
		return 0;
	}

	Protocol(1337).waitForClients();

	return 0;
}
