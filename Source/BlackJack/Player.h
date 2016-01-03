#include "Header.h"

//Players are card holders who are also able to replace Ace with 11
class Player: public CardHolder{
public:

	//Check if player has won
	bool checkHasWon();

	//Constructor
	Player(): CardHolder(){

	}
};