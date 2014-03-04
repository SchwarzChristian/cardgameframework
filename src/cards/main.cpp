/*
 * main.cpp
 *
 *  Created on: 02.03.2014
 *      Author: user
 */

#define TESTING

#include <string>
#include <iostream>
#include <cstring>

#ifdef TESTING
#include "test.h"
#endif

using namespace std;

int main(int argc, char* argv[]) {
#ifdef TESTING
	if (argc > 1 and not strcmp(argv[1], "test")) return test();
#endif

	return 0;
}
