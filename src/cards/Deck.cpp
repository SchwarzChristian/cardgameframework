/*
 * Deck.cpp
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#include <cstdlib>
#include <sstream>

#include "Deck.h"
#include "Cardlist.h"


Card* Deck::draw(int number, bool nodelete) {
	getFirst();
	for (int i = 1; i < number; i++) (*this)++;
	Card* tmp = *getCurr();
	if (not nodelete) remove();
	return tmp;
}

Deck& Deck::add(Card *card, bool bottom) {
	if (bottom)	insertTail(new Card*(card));
	else insertHead(new Card*(card));
	return *this;
}

Deck& Deck::add(Cardlist& cards, bool bottom) {
	for (int i = 0; i < cards.getLen(); i++)
		add(cards[i], bottom);
	return *this;
}

Deck& Deck::shuffle(int count) {
	Deck tmp;

	srand(23);

	for (int i = 0; i < count; i++) {
		while (getLen() > 0)
			tmp.add(draw(rand() % getLen()));

		while (tmp.getLen() > 0)
			add(tmp.draw(rand() % tmp.getLen()));
	}
	return *this;
}

string Deck::toString() {
	stringstream out;
	out << "count: " << getLen() << endl;
	while(not iswrapped() and getLen() > 0)
		out << (*getCurr())->toString();
	return out.str();

}





