#include "Header.h"

string DealerWinState::stateName(){
	return "DealerWinState";
}
GameState* DealerWinState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	GameState* nextState = NULL;

	//Update screen with win message
	screen->message = "Dealer has won, Press Enter for a rematch or Escape to quit";
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