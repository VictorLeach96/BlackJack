#include "Header.h"

string IdleState::stateName(){
	return "IdleState";
}
GameState* IdleState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	GameState* nextState = NULL;

	//Update message with instructions
	screen->message = "Press H to hit or S to stand";
	screen->drawScreen();
	Sleep(500);

	//Get key pressed on keyboard and decide which state to move onto
	switch (_getch()){

	case 27: //Escape Key
		nextState = new EndedState();
		break;

	case 104: //H Key
		nextState = new HitState();
		break;

	case 115: //S Key
		nextState = new StandState();
		break;

	default: break; //Other Keys
	}

	return nextState;
}