/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #1  : Deck of cards
 * DUE DATE   : 22 January 2020
 ******************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

//Preprocessor directives

#include<iostream>	 //for input,  output
#include<iomanip>	 //for output style
#include<stdlib.h>	 //for srand, rand
#include<time.h>	 //for time

using namespace std; //using namespace standard


const int DECK_SIZE = 52;

struct Card
{
	string suit;	//(spades, diamonds, hearts, clubs)
	string rank;	//(Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king)

};


class Deck
{
public:
	//default constructor: assigning the 52 cards
	Deck();

	//destructor
	~Deck();

	//initializing the deck of cards
	void Initialize();

	//shuffle the deck when the cards are assign
	void shuffle();

	//print the current deck with the current order
	void print() const;

	//compares the two decks
	bool compare() const;

	//method for stating how many perfect shuffle
	//needed to return the deck to original
	void returnToOriginal() const;

private:

	//variable Deck to the pointer of deck
	Card deck[DECK_SIZE];
	Card shuffled[DECK_SIZE];
	int  shuffleCount;

};


void PrintHeader (string asName, // IN - assignment Name
				  int    asNum);    // In - assignment number

#endif /* HEADER_H_ */
