/*
 * Cardlist.h
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#ifndef CARDLIST_H_
#define CARDLIST_H_

#include <string>

#include "Card.h"
#include "test.h"

using namespace std;

class Cardlist {			// TODO needs destructor
private:
	int _count;
	int _maxID;
	Card **_cards;
public:
	Cardlist(int cards);
	Cardlist& add(Card* card);
	Card* operator [](int id);
	string toString();
	int getLen() { return _count; };
	friend int test();
	~Cardlist();
};

#endif /* Cardlist_H_ */
