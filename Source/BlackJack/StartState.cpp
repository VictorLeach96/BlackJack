#include "Header.h"

string StartState::stateName(){
	return "StartState";
}
GameState* StartState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	GameState* nextState = NULL;

	//Update screen with welcome message
	screen->message = "Welcome to BlackJack, Press Enter to play";
	screen->drawScreen();
	Sleep(500);

	//Get key pressed on keyboard and decide which state to move onto
	switch (_getch()){

	case 27: //Escape Key
		nextState = new EndedState();
		break;

	case 13: //Enter Key
		nextState = new DealState();
		break;

	default: break; //Other Keys
	}

	return nextState;
}