// Defenition of the functions of the class ClassDeck

#include "CardDeck.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

// Constructor of the class
// return nothing

CardDeck::CardDeck()
{
    m_pCards = vector<Card>(); //creates heap space for 52 cards.
}

// constructor with single parameter
// return nothing

CardDeck::CardDeck(int setNum)
{
    try {
        m_pCards = vector<Card>();
        int k = 0;
        while (k < setNum) { // based on the number of card decks to be used. setNum taken as an input from user

            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 4; ++j) {

                    m_pCards.push_back(Card(Card::Suit(j), Card::Value(i))); // to add a card to the Card object
                }
            }
            k++;
        }
    } catch (bad_alloc& exBA) { // catch the memory allocation exception
        cout << "Encountered a memory allocation issue. Exiting..." << endl;
        exit(0);
    } catch (exception& ex) { // catch general exception
        cout << "Encountered an unknown issue. Exiting..." << endl;
        exit(0);
    }
    shuffleCards(setNum); // to shuffle a card deck
}

// to get a card from the card deck based on the index(input parameter)
// return type: class Card

Card CardDeck::GetCard(int index)
{
    Card getCard;
    try {
        getCard = m_pCards[index]; // get the card that is in the position: index
        return getCard;
    } catch (out_of_range& exOOR) {
        cout << "Encountered an out of range exception. Exiting..." << endl;
        exit(0);
    } catch (exception& ex) { // catch general exception
        cout << "Encountered an unknown issue. Exiting..." << endl;
        exit(0);
    }
    return getCard;
}

void CardDeck::addCard(Card card)
{
    m_pCards.push_back(card); // to insert a card 'card' into the card deck
}


// to shuffle a card deck.
// 'setNum' is the total number of card decks that we are using
// logic: take a random card from the deck and place it as the first card.
// continue this for a number of times so that the entire card deck is shuffled.

void CardDeck::shuffleCards(int setNum)
{
    srand(time(0));
    for (unsigned int i = 0; i < m_pCards.size(); i++) {
        int second = rand() % (52 * setNum); // to randomize the card selection
        Card temp = m_pCards[i];
        m_pCards[i] = m_pCards[second]; // to interchange the card
        m_pCards[second] = temp;
    }

}

// return type: integer
// input type: a card
// logic: search a card 'card' that is sent to this function.
// iterate through the entire length of the card deck until the end of the card deck is reached

int CardDeck::findCardIndex(Card card)
{
    vector<Card>::iterator itr3;
    int index = -1;
    for (itr3 = m_pCards.begin(); itr3 != m_pCards.end(); itr3++) {
        if (itr3->GetSuit() == card.GetSuit() || itr3->GetValue() == card.GetValue()) {
            index = distance(m_pCards.begin(), itr3);
            break;
        } else {

            index = -1;
        }
    }
    return index;
}

// return nothing
// input parameter: the index of the card to be deleted
// logic: find the card based on the index and delete it from the deck

void CardDeck::deleteCard(int index)
{
    try {
        m_pCards.erase(m_pCards.begin() + index); // to delete a card from the deck
    } catch (out_of_range& exOOR) { // to catch the out of range exceptions
        cout << "Encountered an out of range exception. Exiting..." << endl;
        cin.ignore();
        cin.get(); // to wait for a user input before console close in case of windows
        exit(0);
    } catch (exception& ex) { // catch general exception
        cout << "Encountered an unknown issue. Exiting..." << endl;
        cin.ignore();
        cin.get(); // to wait for a user input before console close in case of windows
        exit(0);
    }
}

// to get the total number of cards in the deck
// return type: integer

int CardDeck::getNumberOfCards()
{
    return m_pCards.size(); // to get the size of the deck
}

// to get the top most card in the deck
// return type: class Card
// logic: take the top most card in the deck and return it

Card CardDeck::getTopCard()
{
    Card topCard;
    try {
        topCard = m_pCards.back();
        m_pCards.pop_back();
    } catch (out_of_range& exOOR) {
        cout << "Encountered an out of range exception. Exiting..." << endl;
        exit(0);
    } catch (exception& ex) { // catch general exception
        cout << "Encountered an unknown issue. Exiting..." << endl;
        exit(0);
    }

    return topCard;
}

// to move the cards from the [layed deck to the hidden deck once the hidden deck is empty
// input parameterL a deck of cards. In this case, its the played deck.
// return nothing

void CardDeck::moveAllCards(CardDeck deck2)
{
    vector<Card>::iterator itr1;
    for (itr1 = deck2.m_pCards.begin(); itr1 != deck2.m_pCards.end(); itr1++) {
        m_pCards.push_back(*itr1);
    }
}

// to empty the card deck

void CardDeck::emptyCardDeck()
{
    m_pCards.clear();
}

CardDeck::~CardDeck()
{
}
