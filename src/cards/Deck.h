/*
 * Deck.h
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#ifndef DECK_H_
#define DECK_H_

#include <string>

#include "List.h"
#include "Card.h"
#include "Cardlist.h"


using namespace std;

class Deck : private List<Card*> {
public:
	string name;
	Deck(string name = "") : List() { this->name = name; };
	Deck& shuffle(int count = 1);
	Deck& add(Card *card, bool bottom = false);
	Deck& add(Cardlist& cards, bool bottom = false);
	Card* draw(int number = 1, bool nodelete = false);
	Card* show(int number) { return draw(number, true); };
	string toString();
	friend int test();
};

#endif /* DECK_H_ */
