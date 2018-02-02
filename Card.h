// Declaration of the methods of Class Card
#ifndef CARD_H
#define CARD_H

class Card
{
	public:
		// setting the different card types and the values
		enum Suit { HEARTS, CLUBS, SPADES, DIAMONDS };
		enum Value {
			TWO, THREE, FOUR, FIVE, SIX, SEVEN,
			EIGHT, NINE, TEN, JACK , QUEEN , KING , ACE
		};
		// Constructors
		Card();
		Card(Suit suit, Value value); // to set the properties of a card

		// Destructor
		~Card();


		Suit GetSuit();				// to get the suit of the card
		Value GetValue();			// to get the value of the card

	private:
		Suit m_cardSuit;			// the suit of the card (Heart, Spade, Clubs, Diamonds)
		Value m_cardValue;			// the value of the card (Ace to king)
};

#endif // !CARD_H