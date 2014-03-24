/*
 * Cardlist.cpp
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#include <sstream>
#include <string>

#include "Cardlist.h"
#include "Card.h"

using namespace std;

Cardlist::Cardlist(int cards) {
	_count = 0;
	_maxID = cards;
	_cards = new Card*[cards];
}

Cardlist& Cardlist::add(Card* card) {
	if (_count < _maxID)
		_cards[_count++] = card;
	return *this;
}

Card* Cardlist::operator [](int id) {
	if (id < 0 or id > _count) return NULL;
	return _cards[id];
}

string Cardlist::toString() {
	stringstream out;
	out << "count: " << _count << "/" << _maxID << "\n";
	for (int i = 0; i < _count; i++) {
		out << _cards[i]->toString();
	}
	return out.str();
}

Cardlist::~Cardlist() {
	for (int i = 0; i < _count; i++) delete _cards[i];
 	delete [] _cards;
}









