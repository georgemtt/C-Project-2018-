//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

// Abstract CardDeck header

#include <algorithm>    // std::random_shuffle
#include <type_traits>
#include "Reward.h"
#include "Card.h"
#include <iostream>

#ifndef rewarddeck_h
#define rewarddeck_h

template <class C> class Deck {
	C** cList;
	int listSize;
public:
	//constructor
	Deck() {
		if (std::is_same<C,Card>::value){
		cList = new C*[25];
		listSize = 25;
		}
		if (std::is_same<C, Reward>::value) {
			cList = new C*[7];
			listSize = 7;
		}
	}

	//methods

	virtual void shuffle() = 0;
	virtual C* getNext() = 0;
	virtual bool isEmpty() = 0;
};

#endif