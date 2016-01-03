#include "Header.h"

//Card holder gives subclasses a hand of cards and proxy methods to acces them
class CardHolder{

protected:
	Hand *hand; //Hand of cards

public:

	//Card Manipulation
	void dealRandomCardToHand();
	vector<Card*> getCards();

	//Sum Calculation
	virtual int calculateHandSumWithoutAce();
	int calculateHandSumWithAce();

	//Check for Win/Lose
	virtual bool checkHasWon();
	bool checkHasLost();

	//Constructor
	CardHolder(){
		hand = new Hand();
	}
};