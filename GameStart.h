// Declaraion of the Card GameStart
// The implementation of the game is done in this class

#ifndef GAMESTART_H
#define GAMESTART_H
#include <vector>
#include "Card.h"
class GameStart
{
	public:
		GameStart();		//  constructor of the class
		void StartGame();	// the function that performs the game implementation
		const char* enumSuit_to_string(Card::Suit value); // to return the text value of the type of card
		const char* enumValue_to_string(Card::Value value); // to return the value of the card
		~GameStart();
};
#endif
