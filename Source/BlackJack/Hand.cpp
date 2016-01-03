#include "Header.h"

//Deal a random card to this hand
void Hand::dealRandomCard(){

	//Generate random number and lookup the coresponding card object
	Card* card;
	switch (rand() % 12){
	case 0: card = new Card("Ace", 1); break;
	case 1: card = new Card("Jack", 10); break;
	case 2: card = new Card("Queen", 10); break;
	case 3: card = new Card("King", 10); break;
	case 4: card = new Card("Two", 2); break;
	case 5: card = new Card("Three", 3); break;
	case 6: card = new Card("Four", 4); break;
	case 7: card = new Card("Five", 5); break;
	case 8: card = new Card("Six", 6); break;
	case 9: card = new Card("Seven", 7); break;
	case 10: card = new Card("Eight", 8); break;
	case 11: card = new Card("Nine", 9); break;
	}

	//Add card to the hand
	cards.push_back(card);
}

//Getter for cards in this hand
vector<Card*> Hand::getCards(){
	return cards;
}