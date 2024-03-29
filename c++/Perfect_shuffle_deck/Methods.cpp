/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #1  : Deck of cards
 * DUE DATE   : 22 January 2020
 ******************************************************************************/

#include"Header.h"


/*******************************************************************************
 * Methods for class Deck
 *******************************************************************************/


/****************************************************************
 * Deck();
 * Constructor: initializes the count of the shuffles
 * Parameters: shuffleCount
 * Return: none
 ****************************************************************/
Deck::Deck()
{
	shuffleCount = 0;
}


/****************************************************************
 * ~Deck();
 * Constructor: performs nothing
 * Parameters: none
 * Return: none
 ****************************************************************/
Deck::~Deck() {}

/*******************************************************************
 * void Initialize();
 * This method will initialize a new deck of cards.
-----------------------------------------------------------------
 * Parameter:
-----------------------------------------------------------------
 * Return: none
*******************************************************************/
void Deck::Initialize()
{
	int index;

	//all the face values in an string array
	string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	//put all the suit values in an array as strings
	string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			index = (i * 13) +j;

			deck[index].suit = suits[i];
			deck[index].rank = faces[j];
		}
	}
}


/*******************************************************************
 * void Print() const;
 * This method will print deck of cards.
-----------------------------------------------------------------
 * Parameter:
-----------------------------------------------------------------
 * Return: none
*******************************************************************/
void Deck::print() const
{
	for(int i = 0; i < DECK_SIZE; i++)
	{
		cout << deck[i].rank << " of " << deck[i].suit << endl;
	}

	cout << endl << endl;

}

/*******************************************************************
 * void shuffle();
 * This method will shuffle the deck of cards.
-----------------------------------------------------------------
 * Parameter:
-----------------------------------------------------------------
 * Return: none
*******************************************************************/
void Deck::shuffle()
{
	shuffleCount++;

	Card temp[DECK_SIZE];

	for(int i = 0; i < DECK_SIZE; i += 2)
	{
		temp[i] = deck[i/2];
	}

	for(int j = 1; j < DECK_SIZE; j += 2)
	{
		temp[j] = deck[j/2 + DECK_SIZE/2];
	}

	for(int k = 0; k < DECK_SIZE; k++)
	{
		shuffled[k] = temp[k];
		deck[k] = temp[k];
	}

}

/*******************************************************************
 * bool compare();
 * This method will compare the two deck of cards
-----------------------------------------------------------------
 * Parameter:
-----------------------------------------------------------------
 * Return: cmpr (bool type variable)
*******************************************************************/
bool Deck::compare() const
{
	bool cmpr;

	Deck card;

	card.Initialize();

	for(int i = 0; i < DECK_SIZE; i++)
	{
		if((deck[i].suit == shuffled[i].suit)
		&&  deck[i].rank == shuffled[i].rank)
		{
			cmpr = true;
		}

		else
		{
			cmpr = false;
		}

	}

	return cmpr;
}

/*******************************************************************
 * void returnToOriginal();
 * This method will prints out how many shuffles needed to
-----------------------------------------------------------------
 * Parameter:
-----------------------------------------------------------------
 * Return: none
*******************************************************************/
void Deck::returnToOriginal() const
{
	cout << shuffleCount << "  shuffles needed to return the deck to "
		 << "its original form" << endl;
}


