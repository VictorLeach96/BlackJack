#include "Header.h"

class Card{

protected:

	//Card information
	string cardName;
	int cardValue;

public:

	//Getter/setter for card information
	string getCardName();
	int getCardValue();

	//Constructor
	Card(string cardName, int cardValue){
		this->cardName = cardName;
		this->cardValue = cardValue;
	}
};