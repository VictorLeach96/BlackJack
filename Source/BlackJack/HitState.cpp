#include "Header.h"

string HitState::stateName(){
	return "HitState";
}
GameState* HitState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	GameState *nextState = NULL;

	//Deal a new card to the player and update screen
	player->dealRandomCardToHand();
	screen->updateScreenWithCards(player, dealer);
	screen->drawScreen();

	//Check if player has won or lost and choose next state
	if (player->checkHasWon()){
		nextState = new PlayerWinState();
	}else if (player->checkHasLost()){
		nextState = new DealerWinState();
	}else{
		nextState = new IdleState();
	}

	return nextState;
}