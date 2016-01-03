#include "Header.h"

//Override the superclass method to include checking the calculation when aces are replaced with 11
bool Player::checkHasWon(){
	if (calculateHandSumWithoutAce() == 21 || calculateHandSumWithAce() == 21){
		return true;
	}else{
		return false;
	}
}