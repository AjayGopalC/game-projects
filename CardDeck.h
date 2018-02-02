// Declaration of the class CardDeck

#ifndef CARDDECK_H
#define CARDDECK_H
#include <vector>
#include "Card.h"

using namespace std;
class CardDeck
{
	public:
		// Constructors
		CardDeck();			// to initialize a card deck. i.e. a list of cards
		CardDeck(int num);	// to initialize a set number of card decks

		Card GetCard(int index);	// to get a card from deck based on the index
		void addCard(Card card);	// to add a card to the deck
		void shuffleCards(int setNum);	// to shuffle a set of cards
		int findCardIndex(Card card);	// to get a card index based on the card
		void deleteCard(int index);		// to delete a card based on the index
		int getNumberOfCards();			// to get the total number of cards in a deck
		Card getTopCard();				// to get the top card in a deck
		void emptyCardDeck();	// to empty a card deck
		void moveAllCards(CardDeck deck2);	// to move all cards from played set to the hidden card deck

		// Desctructor
		~CardDeck();

	private:
		vector <Card> m_pCards;			// a list of cards
};
#endif
