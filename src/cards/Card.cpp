/*
 * Card.cpp
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#include "Card.h"

Card::Card(int value, char suit) {
	static int lastID = 0;
	_id = lastID++;
	_value = value;
	_suit = suit;
}




