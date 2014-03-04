/*
 * Card.h
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>

class Card {
private:
	int  _id;
	int  _value;
	char _suit;
public:
	Card(int value, char suit);
	int getID() { return _id; };
	int getValue() { return _value; };
	int getSuit() { return (int)_suit; };
};

#endif /* CARD_H_ */
