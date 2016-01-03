#include "Header.h"

string DealState::stateName(){
	return "DealState";
}
GameState* DealState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	GameState* nextState = new IdleState();

	//Update screen with message
	screen->message = "Dealing first cards...";
	screen->updateScreenWithCards(player, dealer);
	screen->drawScreen();
	Sleep(500);

	//Deal 2 cards for both player and dealer (Dealers card is face down)
	for (int i=0; i<2; i++){

		//Deal card to player and update screen
		player->dealRandomCardToHand();
		screen->updateScreenWithCards(player, dealer);
		screen->drawScreen();
		Sleep(500);

		//Check whether the player has won or lost
		if (player->checkHasWon()){
			nextState = new PlayerWinState();
		}
		if (player->checkHasLost()){
			nextState = new DealerWinState();
		}

		//Deal card to dealer and update screen
		dealer->dealRandomCardToHand();
		screen->updateScreenWithCards(player, dealer);
		screen->drawScreen();
		Sleep(500);

		//Check whether the dealer has won or lost
		if (dealer->checkHasWon()){
			nextState = new DealerWinState();
		}
		if (dealer->checkHasLost()){
			nextState = new PlayerWinState();
		}
	}

	return nextState;
}