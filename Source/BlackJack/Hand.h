#include "Header.h"

//A hand is composed of x number of card objects
class Hand{

protected:
	vector<Card*> cards; //Array of card objects

public:

	//Deal random card to this hand
	void dealRandomCard();

	//Getter for cards array
	vector<Card*> getCards();

	//Constructor
	Hand(){

	}
};