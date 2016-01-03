#include "Header.h"

//State management functions
GameState* GameController::getState(){
	return state;
}
string GameController::getStateName(){
	return state->stateName();
}
void GameController::moveState(GameState* newState){

	//Restet the entire game if state is dealing
	if (newState->stateName() == "DealState"){
		setupNewGame();
	}

	state = newState;
}

//Setup/restart the game and player, dealer, scree objects
void GameController::setupNewGame(){

	//Release main objects if they exist
	if (player != NULL){
		delete player;
		player = NULL;
	}
	if (dealer != NULL){
		delete dealer;
		dealer = NULL;
	}

	//Alloc new versions of the main objects
	player = new Player();
	dealer = new Dealer();
}

//Cleanup and display any end messages
void GameController::endGame(){

	//Clear current screen
	screen->dealerCards.clear();
	screen->playerCards.clear();
	screen->dealerCardsSum = "";
	screen->playerCardsSum = "";

	//Display ended message
	screen->message = "Thanks for playing, please come again";
	screen->drawScreen();
}

//Game Loop
void GameController::gameLoop(){

	//Clear any current keypresses so they aren't transfered between loops
	cin.clear();

	//Execute game loop for current state passing in player, dealer and screen
	GameState* nextState = state->gameLoop(player, dealer, screen);

	//Check if game loop has returned the next state to move onto and if not just repeat the loop
	if (nextState != NULL){
		moveState(nextState);
	}
}