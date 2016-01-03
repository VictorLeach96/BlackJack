#include "Header.h"

string StandState::stateName(){
	return "StandState";
}
GameState* StandState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	GameState* nextState = NULL;

	//Reveal all dealer cards onscreen
	screen->message = "Dealer taking cards...";
	dealer->setHideCard(false);
	screen->updateScreenWithCards(player, dealer);
	screen->drawScreen();
	Sleep(500);
	
	//Give dealer new cards until he has won or lost
	while (nextState == NULL){

		//Deal card to dealer and update screen
		dealer->dealRandomCardToHand();
		screen->updateScreenWithCards(player, dealer);
		screen->drawScreen();
		Sleep(500);

		//Check if dealer has won or lost and move state
		if (dealer->checkHasWon()){
			nextState = new DealerWinState();
			break;
		}else if (dealer->checkHasLost()){
			nextState = new PlayerWinState();
			break;
		}

		//Check if dealer has higher card sum than player
		if (dealer->calculateHandSumWithoutAce() > player->calculateHandSumWithAce()){
			nextState = new DealerWinState();
			break;
		}
	}

	return nextState;
}