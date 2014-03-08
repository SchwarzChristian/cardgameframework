/*
 * Card.h
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

class Card {
private:
	int    _value;
	char   _suit;
	string _bitmap;
public:
	Card(int value, char suit, string bitmap = "");
	int    getValue() { return _value; };
	int    getSuit() { return (int)_suit; };
	string getBitmap() { return _bitmap; };
	string toString();
	friend int test();
};

#endif /* CARD_H_ */
