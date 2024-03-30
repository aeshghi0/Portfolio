/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #1  : Deck of cards
 * DUE DATE   : 22 January 2020
 ******************************************************************************/

#include"Header.h"

/************************************************************
 * Deck of Cards
 * _________________________________________________________
 * This program initializes a new deck of cards and does a
 * perfect shuffle on the card and prints out the original
 * deck and the shuffled deck, then it calculates how many
 * more perfect shuffle is needed for the shuffled deck to
 * go back to original deck.
 * _________________________________________________________
 * INPUT: N/A
 *
 * OUTPUT: original deck of card, shuffled deck of card,
 * 		   the final deck of cards, the number of perfect
 * 		   shuffles needed to get back to original.
 *
 *
 ************************************************************/

int main()
{
	//Constants
	 const string asName = "Deck of Cards";	//assignment name
	 const int    asNum  = 1;				//assignment number


	//Variables

	bool 	compare;	//PROCESS - boolean variable for compare
	Deck	card;		//PROCESS - class type3 variable for deck of card


	//printing the header file
	PrintHeader(asName, asNum);

	//initializing the deck of cards
	card.Initialize();

	//printing the deck
	card.print();

	//shuffling the cards
	card.shuffle();

	//printing the deck of card
	card.print();

	//comparing the deck of cards
	compare = card.compare();


	//while loop to shuffle the cards until the shuffled deck is like
	//the original deck
	while(compare == false)
	{
		card.shuffle();
		compare = card.compare();
	}

	//printing the final deck
	if(compare == true)
	{
		card.print();
		card.returnToOriginal();
	}

	//returning the 0 for program that eliminates successfully
	return 0;
}
