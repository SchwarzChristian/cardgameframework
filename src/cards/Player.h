/*
 * Player.h
 *
 *  Created on: 03.03.2014
 *      Author: user
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Deck.h"

class Player: public Deck {
public:
	Card* operator[](int id) { return NULL; };
};

#endif /* PLAYER_H_ */
