#include "Header.h"

//Screen allows us to use a preset template to draw information to the screen
class Screen{
public:
	string message; //Message or next instruction to be displayed
	
	//Total sum to display for both the player and dealers cards
	string playerCardsSum;
	string dealerCardsSum;

	//List of cards to display for both the player and dealer
	vector<string> playerCards;
	vector<string> dealerCards;

	//Methods
	void updateScreenWithCards(Player* player, Dealer *dealer); //Use player and dealer object to populate the sum and cards fields
	void drawScreen(); //Draw the current screen state to the console
};