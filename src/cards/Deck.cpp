/*
 * Deck.cpp
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#include <cstdlib>

#include "Deck.h"


Card* Deck::draw(int number, bool nodelete) {
	getFirst();
	for (int i = 0; i < number; i++) (*this)++;
	Card* tmp = getCurr();
	if (not nodelete) remove();
	return tmp;
}



Deck& Deck::add(Card *card, bool bottom) {
	if (bottom)	insertTail(card);
	else insertHead(card);
	return *this;
}

void Deck::shuffle() {
	List<Card> tmp;
	getFirst();
	srand(23);
	while (getLen() > 0) {
		for (int i = 0; i < 1 + rand() * tmp.getLen() / RAND_MAX; i++) {
			tmp.insertBefore(getCurr());
			remove();
			tmp++;
		}
	}
	tmp.getFirst();
	while (tmp.getLen() > 0) {
		for (int i = 0; i < 1 + rand() * getLen() / RAND_MAX; i++) {
			insertBefore(getCurr());
			tmp.remove();
			(*this)++;
		}
	}
}



