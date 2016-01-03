#include "Header.h"

//Game controller manages the state of the game and holds main objects
class GameController{

private:

	Screen *screen; //Screen object allows us to use a template view and write information to screen
	GameState *state; //Current state of the game, used to execute the current game loop

	//CardHolders in the game containing their hand and cards
	Player *player;
	Dealer *dealer;

public:

	//State Management
	GameState* getState(); //Get the current state object
	string getStateName(); //Get state name by string (Defined in GameState stringName function)
	void moveState(GameState* newState); //Move to a new state using the given object

	//Game Management
	void setupNewGame(); //Setup/restart the game and player, dealer, scree objects
	void endGame(); //Cleanup and display any end messages
	void gameLoop();

	//Constructor
	GameController(){
		screen = new Screen();
		player = NULL;
		dealer = NULL;
		state = NULL;
	}
	
	//Destructor
	~GameController(){
		delete screen;
		delete player;
		delete dealer;
		delete state;
	}
};