// CardGame.cpp : Defines the entry point for the console application: Card game
// Authors : Team 6
// Date: 24 November 2017
// Implementation of a sample card game.
// User is asked for hte number of card sets to be used and the total number of cards.
// The computer plays out the scenario and displayed the result
#include "GameStart.h"
#include "GameStart.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
//test

using namespace std;

int main()
{
    // Entry Point of the Game
    GameStart start;
    start.StartGame(); // Initiating the Game
    cin.ignore();
    cin.get(); // to wait for a user input before console close in case of windows
    return EXIT_SUCCESS;
}
