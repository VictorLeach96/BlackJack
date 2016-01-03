#include "Header.h"

string EndedState::stateName(){
	return "EndedState";
}
GameState* EndedState::gameLoop(Player *player, Dealer *dealer, Screen* screen){
	return NULL;
}