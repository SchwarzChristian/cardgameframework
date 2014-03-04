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

using namespace std;

class Deck : private List<Card> {
public:
	string name;
	Deck(string name = "") : List() { this->name = name; };
	void shuffle();
	Deck& add(Card *card, bool bottom = false );
	Card* draw(int number = 1, bool nodelete = false);
};

#endif /* DECK_H_ */
