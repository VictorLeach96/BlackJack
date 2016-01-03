#include "Header.h"

//Main menu for the game, ask user whether to play
class StartState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};

//Deal the first two cards to both player and dealer (Last dealer card is hidden)
class DealState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};

//Wait for the player to either hit or stand
class IdleState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};

//Player asked to hit, so deal them a random card
class HitState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};

//Player asked to stand so continue to give dealer cards until the game is over
class StandState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};

//Player or dealer has won, display message and ask what to do next
class PlayerWinState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};
class DealerWinState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};

//Game has been ended, terminate the program
class EndedState: public GameState{
	string stateName();
	GameState* gameLoop(Player *player, Dealer *dealer, Screen* screen);
};