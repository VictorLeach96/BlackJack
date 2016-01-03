#include "Header.h"

//Special Cards
class Ace: public Card{
public:
	Ace(){
		cardName = "Ace";
		cardValue = 1;
	}
};

//Value 10 Cards
class Jack: public Card{
public:
	Jack(){
		cardName = "Jack";
		cardValue = 10;
	}
};
class Queen: public Card{
public:
	Queen(){
		cardName = "Queen";
		cardValue = 10;
	}
};
class King: public Card{
public:
	King(){
		cardName = "King";
		cardValue = 10;
	}
};

//Other Value Cards
class Two: public Card{
public:
	Two(){
		cardName = "Two";
		cardValue = 2;
	}
};