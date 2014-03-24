/*
 * StartGame.h
 *
 *  Created on: 24.03.2014
 *      Author: user
 */

#ifndef STARTGAME_H_
#define STARTGAME_H_

#include "Header.h"

class StartGame : Header{
	StartGame(uchar id) : Header(id, "start") {};
	std::string toString();
};

#endif /* STARTGAME_H_ */
