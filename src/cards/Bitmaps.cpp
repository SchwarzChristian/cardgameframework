/*
 * Bitmaps.cpp
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#include <string>

#include "Bitmaps.h"

using namespace std;

Bitmaps::Bitmaps(int cards) {
	_maxID = 0;
	_bitmaps = new string[cards];
}

Bitmaps& Bitmaps::add(string filename) {
	_bitmaps[_maxID++] = filename;
	return *this;
}

string Bitmaps::operator [](int id) {
	if (id < 0 or id > _maxID) return "";
	return _bitmaps[id];
}





