#include "Header.h"

//Deal random card to the current hand
void CardHolder::dealRandomCardToHand(){
	hand->dealRandomCard();
}

//Get a list of cards from the current hand
vector<Card*> CardHolder::getCards(){
	return hand->getCards();
}

//Calculate the sum of hand with aces value as 1
int CardHolder::calculateHandSumWithoutAce(){
	int sum = 0;

	//Loop through each card and calculate sum
	vector<Card*> cards = hand->getCards();
	for (int i=0; i< cards.size(); i++){
		sum += cards[i]->getCardValue();
	}

	return sum;
}

//Calculate the sum of hand with aces value as 11
int CardHolder::calculateHandSumWithAce(){
	int sum = 0;

	//Loop through each card and calculate sum
	vector<Card*> cards = hand->getCards();
	for (int i=0; i< cards.size(); i++){
		
		//Check each card for aces and replace value with 11
		if (cards[i]->getCardName() == "Ace"){
			sum += 11;
		}else{
			sum += cards[i]->getCardValue();
		}
	}

	return sum;
}

//Check if the card holder has won the game
bool CardHolder::checkHasWon(){
	if (calculateHandSumWithoutAce() == 21){
		return true;
	}else{
		return false;
	}
}

//Check if the cardholder hsa lost the game
bool CardHolder::checkHasLost(){
	if (calculateHandSumWithoutAce() > 21){
		return true;
	}else{
		return false;
	}
}