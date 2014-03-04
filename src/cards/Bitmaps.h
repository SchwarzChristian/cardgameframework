/*
 * Bitmaps.h
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#ifndef BITMAPS_H_
#define BITMAPS_H_

#include <string>

using namespace std;

class Bitmaps {
private:
	string *_bitmaps;
	int _maxID;
public:
	Bitmaps(int cards);
	Bitmaps& add(string filename);
	string operator[](int id);
};

#endif /* BITMAPS_H_ */
