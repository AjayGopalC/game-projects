// the implementation of the game sequence
// pseudocode for card distribution:
// Until total number of cards to be distributed(set as 7)
//		loop through the number of players
//				increment the card deck of a player
//
// pseudocode for playing the game:
// While no players's card deck is empty
//		check the top most card
//			loop through a player's deck and check for match condition(suit or value matching)
//				in case no match is found the user withdraws from hidden deck
//				in case match is found, that card is removed from his deck and added to the played deck
//			move to the next player and repeat the same
//			in case a matching card was found in a player's deck, it is used as the top most playable card going ahead
//		repeat the same until the hidden deck is empty
//		once the hidden deck is empty move all the card from the played card deck, shuffle it and use as the hidden deck

#include "GameStart.h"
#include "CardDeck.h"
#include "CardDeck.cpp"
#include "Card.cpp"
#include <iostream>
#include <string>

GameStart::GameStart()
{
}

void GameStart::StartGame()
{
    int setNum = 0, players = 0;
    bool gameOn = true;
    cout << "How many sets of cards do you want to play with:" << endl;
    while (1) {
        cin >> setNum; // the total number of card decks to be used
        if (setNum < 1) {
            cout << "Please enter a number greater than or equal to 1:" << endl;
        } else {
            break;
        }
    }
    //setNum < 1 ? setNum = 1 : setNum = setNum;
    cout << "Enter number of Players:" << endl;
    while (1) {
        cin >> players; // total number of players involved
        if (players < 2) {
            cout << "Please enter a number greater or equal to 2:" << endl;
        } else {
            break;
        }
    }
    //players < 2 ? players = 2 : players = players;
    CardDeck hiddenDeck = CardDeck(setNum); // create a hidden deck i.e. intialising the cards to be used
    CardDeck playedDeck = CardDeck(); // the deck where played cards are placed
    vector<CardDeck> player = vector<CardDeck>(players);
    vector<CardDeck>::iterator itr3; // iteration pointer used to traverse the deck
    int cardCount = 0;
    while (cardCount < 7) { // for distributing 7 cards to each player
        for (itr3 = player.begin(); itr3 != player.end(); itr3++) {
            Card topCard = hiddenDeck.getTopCard(); // top card is taken
            itr3->addCard(topCard); // and given to a player's deck

        }
        cardCount++;
    }
    Card topCard = hiddenDeck.getTopCard();
    string cardSuit = enumSuit_to_string(topCard.GetSuit()); // display the suit of the card as a string
    string cardValue = enumValue_to_string(topCard.GetValue()); // display the card value as a string
    cout << "Top Card is: " << cardSuit << "-" << cardValue << endl; // display the card

    vector<CardDeck>::iterator itr2;
    Card playedCard = Card();
    playedDeck.addCard(topCard); // keeping the top card taken from the hidden deck and placing it in the played card deck

    while (gameOn) { // to repeat until a player wins the game
        try {
            for (itr2 = player.begin(); itr2 != player.end(); itr2++) { // iterating through each player

                int index = itr2->findCardIndex(topCard); // find the index of a matching card in player's deck

                if (index != -1) { // to see if the card is present in teh player's deck

                    playedCard = itr2->GetCard(index); // get the suitable card from the player's deck
                    string cardSuit = enumSuit_to_string(playedCard.GetSuit());
                    string cardValue = enumValue_to_string(playedCard.GetValue());
                    cout << "Player" << distance(player.begin(), itr2) + 1 << " plays: " << cardSuit << "-" << cardValue << endl;
                    playedDeck.addCard(playedCard); // the new played card is the card played by the player
                    itr2->deleteCard(index); // delete the card from the player's deck
                    topCard = playedCard; // and update the new playable card as the player's played card
                } else { // in case the player doesn't have any card to play, a card is to be taken from the hidden deck
                    Card topCard2 = hiddenDeck.getTopCard();
                    itr2->addCard(topCard2);
                    string cardSuit = enumSuit_to_string(topCard2.GetSuit());
                    string cardValue = enumValue_to_string(topCard2.GetValue());
                    cout << "Player " << distance(player.begin(), itr2) + 1 << " takes: " << cardSuit << "-" << cardValue << endl;
                    cout << "Player " << distance(player.begin(), itr2) + 1 << "'s current hand: " << endl;
                    for (int i = 0; i < itr2->getNumberOfCards(); i++) // displays the set of card the player has right now
                    {
                        cout << enumSuit_to_string(itr2->GetCard(i).GetSuit()) << "-" << enumValue_to_string(itr2->GetCard(i).GetValue()) << endl;

                    }
                }
                if (itr2->getNumberOfCards() == 0) { // chc=eck if the player has won. i.e. emptied his deck
                    gameOn = false; // setting the condition to exit the loop
                    cout << "\nPlayer " << distance(player.begin(), itr2) + 1 << " won! Good Job! Congrats :)";
                    break;
                }

                if (hiddenDeck.getNumberOfCards() == 0) { // to move the played card set to the hidden card deck once hidden set is empty
                    hiddenDeck.moveAllCards(playedDeck);
                    playedDeck.emptyCardDeck(); // to empty the played card deck and reset it
                    hiddenDeck.shuffleCards(setNum); // hidden deck is shuffled
                }
            }
        } catch (exception& ex) { // to catch general uncaught exceptions
            cout << "Encountered an issue. Exiting...";
            cin.ignore();
            cin.get(); // to wait for a user input before console close in case of windows
            exit(0);
        }
    }
}

// to display the string value of the suit when a card of suit 'suit' is passed along

const char* GameStart::enumSuit_to_string(Card::Suit suit)
{
    switch (suit) {
        case Card::HEARTS:
            return "HEARTS";
            break;
        case Card::CLUBS:
            return "CLUBS";
            break;
        case Card::SPADES:
            return "SPADES";
            break;
        case Card::DIAMONDS:
            return "DIAMONDS";
            break;
        default:
            return "Wrong Card!";
            break;
    }
}

// to display the string value of the value when a card of value 'value' is passed along

const char* GameStart::enumValue_to_string(Card::Value value)
{
    switch (value) {
        case Card::TWO:
            return "TWO";
            break;
        case Card::THREE:
            return "THREE";
            break;
        case Card::FOUR:
            return "FOUR";
            break;
        case Card::FIVE:
            return "FIVE";
            break;
        case Card::SIX:
            return "SIX";
            break;
        case Card::SEVEN:
            return "SEVEN";
            break;
        case Card::EIGHT:
            return "EIGHT";
            break;
        case Card::NINE:
            return "NINE";
            break;
        case Card::TEN:
            return "TEN";
            break;
        case Card::JACK:
            return "JACK";
            break;
        case Card::QUEEN:
            return "QUEEN";
            break;
        case Card::KING:
            return "KING";
            break;
        case Card::ACE:
            return "ACE";
            break;
        default:
            return "Wrong Card!";
            break;
    }
}

GameStart::~GameStart()
{
}
