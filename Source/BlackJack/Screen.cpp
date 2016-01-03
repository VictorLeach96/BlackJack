#include "Header.h"

//Use player and dealer object to populate the sum and cards fields
void Screen::updateScreenWithCards(Player* player, Dealer *dealer){

	//Update screen with player card values
	playerCards.clear();
	vector<Card*> playerCardsList = player->getCards();
	for (int i=0; i<playerCardsList.size(); i++){
		string cardName = playerCardsList[i]->getCardName();
		playerCards.push_back(cardName);
	}

	//Update screen with dealer card values
	dealerCards.clear();
	vector<Card*> dealerCardsList = dealer->getCards();
	for (int i=0; i<dealerCardsList.size(); i++){
		string cardName = dealerCardsList[i]->getCardName();

		//Check whether this card should be hidden
		if (dealer->getHideCard() && i == dealerCardsList.size()-1){
			dealerCards.push_back("* Hidden *");
		}else{
			dealerCards.push_back(cardName);
		}
	}

	//Update totals on screen
	playerCardsSum = to_string(player->calculateHandSumWithoutAce());
	dealerCardsSum = to_string(dealer->calculateHandSumWithoutAce());
}

//Draw the current screen state to the console
void Screen::drawScreen(){
	
	//Clear console window
	system("CLS");

	//Print Header
	cout << "===========================================================================" << endl;
	cout << "" << endl;
	cout << " Welcome to BlackJack!" << endl;
	cout << "" << endl;
	cout << " Magiced toggether by Victor Leach" << endl;
	cout << "    Press Escape to end me!" << endl;
	cout << "" << endl;
	cout << "===========================================================================" << endl;

	//Print message
	if (message != ""){
		cout << endl << endl << " " << message << endl << endl;
	}

	//Print player cards
	if (playerCards.size() > 0){
		cout << endl;
		cout << "===========================================================================" << endl << endl;
		cout << " Player Cards";
		if (playerCardsSum != ""){
			cout << " (" << playerCardsSum << ")";
		}
		cout << endl << endl;

		//Loop through each card and print
		for (int i=0; i<playerCards.size(); i++){
			cout << " " << playerCards[i] << endl;
		}
	}

	//Print dealer cards
	if (dealerCards.size() > 0){
		cout << endl;
		cout << "===========================================================================" << endl << endl;
		cout << " Dealer Cards";
		if (dealerCardsSum != ""){
			cout << " (" << dealerCardsSum << ")";
		}
		cout << endl << endl;

		//Loop through each card and print
		for (int i=0; i<dealerCards.size(); i++){
			cout << " " << dealerCards[i] << endl;
		}
	}

	cout << endl;
}