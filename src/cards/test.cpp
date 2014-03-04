/*
 * test.cpp
 *
 *  Created on: 02.03.2014
 *      Author: user
 */

#include <iostream>

#include "Bitmaps.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int test() {
	Card c1(5, 3), c2(4, 2);
	cout <<	"Card c\n053\n§§§\n"  << c1.getID() << c1.getValue() << c1.getSuit() << "\n§§§\n";
	cout <<	"Card c\n142\n§§§\n"  << c2.getID() << c2.getValue() << c2.getSuit() << "\n§§§\n";

	Bitmaps b(3);
	b.add("bmp1").add("bmp2").add("bmp3");
	cout <<	"b[0]\nbmp1\n§§§\n"  << b[0]  << "\n§§§\n";
	cout <<	"b[1]\nbmp2\n§§§\n"  << b[1]  << "\n§§§\n";
	cout <<	"b[2]\nbmp3\n§§§\n"  << b[2]  << "\n§§§\n";
	cout <<	"b[-1]\n\n§§§\n"     << b[-1] << "\n§§§\n";
	cout <<	"b[8]\n\n§§§\n"      << b[8]  << "\n§§§\n";

	Deck d1;
	Deck d2("the one deck");
	Card *cards[100];
	for (int i = 99; i >= 0; i--) {
		cards[i] = new Card(100 - i, 2);
		d1.add(cards[i]);
	}
//	d1.shuffle();
	d2.add(&c1).add(&c2);
	cout <<	"d1\n\n";
	for (int i = 99; i >= 0; i--)
		cout << i << "," << 100 - i << endl;
	cout << "\n§§§\n" << d1.name << endl;
	for (int i = 0; i < 100; i++) {
		Card* tmp = d1.draw();
		cout << tmp->getID() << "," << tmp->getValue() << endl;
	}
	cout << "\n§§§\n";

//	delete [] cards;
	return 0;
}
