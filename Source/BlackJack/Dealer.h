#include "Header.h"

//Dealers are card holders who can hide their last card
class Dealer: public CardHolder{

private:
	bool hideCard; //Specifies whether the dealers last card is hidden

public:

	//Setter/getter for hiding the last card
	void setHideCard(bool hide);
	bool getHideCard();

	//Override superclass method
	int calculateHandSumWithoutAce();

	//Constructor
	Dealer(): CardHolder(){
		hideCard = true;
	}
};