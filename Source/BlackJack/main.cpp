#include "Header.h"

int main(){

	//Randomize seed
	srand(time(NULL));

	//Turns on or off the blinking cursor
	//Sourced from http://stackoverflow.com/questions/18028808/blinking-underscore-with-console
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);

	//Set the console size
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, 50, 700, 800, TRUE);
	

	/// Start Game ///

	//Initiate game controller with start state
	GameController *gameController = new GameController();
	gameController->moveState(new StartState());

	//Run game loop via the game controller until the state is ended
	while (gameController->getStateName() != "EndedState"){
		gameController->gameLoop();
	}

	//Cleanup, release game controller and end game
	gameController->endGame();
	delete gameController;
	
	exit(0);
	return 0;
}