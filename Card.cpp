// Defenition of functions the class Card

#include "Card.h"

Card::Card()
{
}


// input: the type and value of card. eg- suit: Heart value: SIX

Card::Card(Suit suit, Value value)
{
    this->m_cardSuit = suit;
    this->m_cardValue = value;
}

Card::Suit Card::GetSuit()
{
    return m_cardSuit;
}

// return type: class Value

Card::Value Card::GetValue()
{
    return m_cardValue;
}

Card::~Card()
{
}
//
