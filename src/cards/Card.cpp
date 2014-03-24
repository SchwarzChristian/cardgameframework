/*
 * Card.cpp
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#include <sstream>

#include "Card.h"

Card::Card(int value, char suit,string bitmap) {
	static int lastID = 0;
	_value  = value;
	_suit   = suit;
	_bitmap = bitmap;
}

string Card::toString() {
	stringstream out;
	out << ", Value: " << getValue()
		<< ", Suit: " << getSuit()
		<< ", Bitmap: " << getBitmap() << endl;
	return out.str();
}









