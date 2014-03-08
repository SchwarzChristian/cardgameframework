/*
 * test.cpp
 *
 *  Created on: 02.03.2014
 *      Author: user
 */
#define TESTING				//strip on release

#ifdef TESTING

#include <iostream>
#include <sstream>

#include "Cardlist.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

template <class X, class Y, class Z>
void out(X const& name, Y const& exp, Z const& got) {
	cout << name << endl << exp << "\n§§§\n" << got << "\n§§§\n";
}


int test() {
	/*****   Card   *****/
	{
		stringstream got;
		Card c(5, 3);

		got << c._value << (int)c._suit << c._bitmap;

		out("Card(5, 3)", "53", got.str());
	} /**/ {
		stringstream got;
		Card c(4, 2, "test.png");

		got << c._value << (int)c._suit << c._bitmap;

		out("Card(4, 2, \"test.png\")", "42test.png", got.str());
	}

	/*****   Cardlist   *****/
	{
		stringstream exp, got;
		Cardlist b(100);

		exp << "100/100" << endl;
		for (int i = 0; i < 100; i++) {
			b.add(new Card(100 - i, 23));
			exp << i << ": " << 100 - i << endl;
		}
		got << b._count << "/" << b._maxID << endl;
		for (int i = 0; i < 100; i++)
			got << i << ": " << b[i]->_value << endl;

		out("Cardlist(100)", exp.str(), got.str());
	} /**/ {
		stringstream got;
		Cardlist c(3);

		c.add(new Card(2, 3)).add(new Card(4, 2));
		got << c._count << "/" << c._maxID << endl << c[0]->_value << c[1]->_value;

		out("Cardlist(3)", "2/3\n24", got.str());
	}

	/*****   Deck   *****/
	{
		stringstream got;
		Deck d("the one deck");
		Cardlist c(3);
		c.add(new Card(1, 1)).add(new Card(2, 2)).add(new Card(3, 3));

		d.add(c);
		d.getFirst();

		got << d.show(1)->_value << d.show(2)->_value << d.show(3)->_value
			<< d.draw(1, true)->_value << d.draw(2, true)->_value << d.draw(3, true)->_value;

		out("Deck(\"the one deck\")", "321321", got.str());
	} /**/ {
		stringstream got;
		Deck d("the one deck");
		Cardlist c(10);
		for (int i = 0; i < 10; i++)
			c.add(new Card(i, i));
		d.add(c);
		d.shuffle();
		for (int i = 0; i < 10; i++)
			got << d.draw()->_value;
		out("Deck(\"the one deck\").shuffle()", "have to fail!", got.str());
	}

	/*****   -   *****/
	return 0;
}
#endif //TESTING
