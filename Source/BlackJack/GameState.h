#include "Header.h"

//Abstract class fo the GameState
class GameState{
public:
	virtual string stateName() = 0; //Return a string which is the name of this state, used for comparisons
	virtual GameState* gameLoop(Player* player, Dealer* dealer, Screen* screen) = 0; //Execute the current game loop with main objects passed in
};