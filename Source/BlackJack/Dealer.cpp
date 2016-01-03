#include "Header.h"

//Setter/getter for hiding dealers last card
void Dealer::setHideCard(bool hide){
	hideCard = hide;
}
bool Dealer::getHideCard(){
	return hideCard;
}

//Override superclass method and remove last card from sum calculation
int Dealer::calculateHandSumWithoutAce(){
	
	//If the last card SHOULDN'T be hidden just call the superclass method instead
	if (!hideCard){
		return CardHolder::calculateHandSumWithoutAce();
	}

	//Loop through each card but the last and calculate sum
	int sum = 0;
	vector<Card*> cards = hand->getCards();
	if (cards.size() > 0){
		for (int i=0; i< cards.size() - 1; i++){
			sum += cards[i]->getCardValue();
		}
	}

	return sum;
}