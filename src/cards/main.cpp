/*
 * main.cpp
 *
 *  Created on: 02.03.2014
 *      Author: user
 */

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "test.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc > 1 and not strcmp(argv[1], "test")) return test();

	return 0;
}
