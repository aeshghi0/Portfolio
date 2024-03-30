/*****************************************************************************
* AUTHORS		: Ali Eshghi - Anna Tsaritove
* STUDENT ID'S  : 1112261    - 
* LAB 10        : Basic Input & Output
* CLASS  		: CS1A
* SECTION		: TTH - 8am
* DUE DATE		: 3/26/19
******************************************************************************/


// the preprocessor directives
#include <iostream>
#include <iomanip>
using namespace std;


/*****************************************************************************
 *	 Pocket Money Program 
 * ___________________________________________________________________________
 * 
 * 	 This Program Receives the pocket money left over from the previous 
 * 			week and the amount spent in the current week from the user and
 * 			calculates how much pocket money is remaining. Each week the user 
 * 			is allocated an allowance
 * ___________________________________________________________________________
 *	 INPUT :
 *	 	name		:	The User's name.
 *	 	amtLeftover :	Amount leftover from the previous week.
 *	 	spent		:	Amount spent this week.
 *	 		
 *	 OUTPUT:
 *	 	name		:	User's Name
 *	 	pocketMoney :	amount of pocket money remaining.
 *****************************************************************************/

int main() 
{
	/**************************************************************************
	* CONSTANTS
	* -------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* -------------------------------------------------------------------------
	* PROGRAMMERS    : Ali Eshghi - Anna Tsaritove ( the names of the Programmers)
	* CLASS          : CS1A ( the class that we are taking)
	* SECTION        : TTH - 8am (which class we are taking)
	* LAB_NUM        : 10 (specific to this lab)
	* LAB_NAME       : Pocket Money
	**************************************************************************/

	const char 	PROGRAMMERS[] 	= "Ali Eshghi - Anna Tsaritove";
	const char 	CLASS[]		 	= "CS1A";
	const char 	SECTION[]     	= "TTh - 8am";
	const float LAB_NUM      	=  10;
	const char 	LAB_NAME[]    	=  "Pocket Money";
		
	// Declare your constants here include a table describing them
	const	float	WEEKLYMONEY = 20.00; // INPUT AND OUTPUT, this is a constant money the user gets and it doesn't change
	char			name[20];			 // INPUT AND OUTPUT, this is the user input of the user's name
	float			amtLeftover;	  	 // OUTPUT AND PROCESSING, this is the amount we get in processing and use it in output
	float			spent;			  	 // INPUT AND OUTPUT, this is the user input of how much the user has spent
	float			pocketMoney;		 // OUTPUT, this is the remaining of the money left			
	
	
	//OUTPUT - this is where we output the class heading
	
	cout << left;
	cout << "*************************************************************\n";
	cout << "*   PROGRAMMED BY : "   << PROGRAMMERS					 << endl;
	cout << "*  "       << setw(14) << "CLASS"   << ": "<< CLASS     << endl;
	cout << "*  "       << setw(14) << "SECTION" << ": "<< SECTION   << endl;
	cout << "*   LAB #" << setw(9)  << LAB_NUM   << ": "<< LAB_NAME  << endl;
	cout << "***********************************************************\n\n";
	cout << right;
	
	
	// INPUT - in the input we need the user input of the name, spent, and the left over from previous week 
	
	cout << "What is your name?	";
	cin  >> name;
	
	cout << "How much is left from last week?	";
	cin  >> amtLeftover;
	
	cout << "How much have you spend?	";
	cin  >> spent;
	
	
	// PROCESS - this is we use the user's input and the newMoney to calculate the remaining of money
	
	pocketMoney = (amtLeftover + WEEKLYMONEY) - spent;
	
	
	// OUTPUT - this is where we output the class heading, the user's name, and the remaining of the money
	
	cout << setprecision(2) << fixed;
	cout << "\n\nHello " << name << endl;
	cout << "You now have $" << pocketMoney << endl;

	return 0;
}