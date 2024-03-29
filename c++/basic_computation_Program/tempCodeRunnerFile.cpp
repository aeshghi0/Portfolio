/******************************************************************************
 * AUTHORS         : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID      : 1112261 & 1103126
 * Lab #1          : Theme Park Day Planner
 * CLASS           : CS1B
 * SECTION         : MW: 7:30pm
 * DUE DATE        : 8/21/19
 *****************************************************************************/
// The preprocessor directives
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

/******************************************************************************
* Lab #1
* -----------------------------------------------------------------------------
* this program will get the name of ten kids and their eating habbits based on
* that are they vegeterians or no, or do they eat cheese or no. also this 
* program gives us the total cost of the theme park based on the admission of 
* the park based on each of the kid's age and the cost of each of the kids based 
* on their eating habitats
* -----------------------------------------------------------------------------
* INPUT:
*       - name of kids                      (kidName)
*       - age                               (kidAge)
        - vegeterian or no                  (vegi)
*       - DO the kid eat cheese or no       (eatCheese)
* OUTPUT:
*       - the ride based on the age of the kid
*       - the snack based on the eating habitats
*       - the total cost of ten kids
*       - the average pay for each kid
******************************************************************************/

int main()
{
	const int 	KID_POPULATION = 10;        // PROCESS - for the loop
	int			kidCount;                   // PROCESS - used for the loop
	string		kidName;                    // INPUT AND OUTPUT - user's input, output too
	int			kidAge;                     // INPUT AND PROCESS - for the process of output
	char		vegiOption;                 // INPUT AND PROCESS - for the process of output
	char		eatCheeseOption;            // INPUT AND PROCESS - for the process of output
    int         adminFee;                   // PROCESS - for the process to get output
    int         foodCost;                   // PROCESS - for the process to get output
    int         totalCost;                  // PROCESS AND OUTPUT - got in the process and used in output
    float       avgCost;                    // PROCESS AND OUTPUT - got in the process and used in output
    bool        vegeterian;                 // PROCESS - for the process to get output
    bool        vegan;                      // PROCESS - for the process to get output
    bool        noDairy;                    // PROCESS - for the process to get output
    bool        eatAny;                     // PROCESS - for the process to get output
    bool        infant;                     // PROCESS - for the process to get output
    bool        child;                      // PROCESS - for the process to get output
    bool        teen;                       // PROCESS - for the process to get output

    /**************************************************************************
	* CONSTANTS
	* -------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* -------------------------------------------------------------------------
	* PROGRAMMER     : Programmer's Name
	* CLASS          : student's Course'
	* SECTION        : class days and times
	* LAB_NUM        : lab Number(or assignment)
	* LAB_NAME       : title of the lab( or assignment)
	**************************************************************************/

    const char PROGRAMMERS[] = "Ali Eshghi & Amirarsalan Valipour";
	const char CLASS[]		 = "CS1B";
	const char SECTION[]     = "MW: 7:30 pm";
	const float LAB          =  1;
	const char ASSIGN_NAME[] =  "Review - Theme Park Day Planner";

    // OUTPUT - this is where we output the class heading first and the rest of output
    cout << left;
    cout << "*************************************************************\n";
	cout << "*  PROGRAMMED BY : "   << PROGRAMMERS  << endl;
	cout << "*  "       << setw(14) << "CLASS   "   << ": " << CLASS       << endl;
	cout << "*  "       << setw(14) << "SECTION "   << ": " << SECTION     << endl;
	cout << "*  LAB #"  << setw(9)   << LAB         << ": " << ASSIGN_NAME << endl;
	cout << "***********************************************************\n\n";
	cout << right;

    /**************************************************************************
     * INPUT - assign the admission fee and the food cost to 0 :
     * adminFee and foodCost
     * ************************************************************************/
    adminFee = 0.00;
    foodCost = 0.00;

    cout << "Welcome to the Theme Park Planner! PLease inpiut each kid's information" << endl << endl;
    //Outputs the welcome message to the program

	for (kidCount = 1; kidCount <= KID_POPULATION; kidCount++)
	{
        cout << left;
		cout << "kid #" << kidCount << endl; // Output the number of the kids investigating

    /**************************************************************************
     * INPUT - the name of the kid, age, is he/she vegeterian, and does he/she 
     * eat cheese:
     * kidName, kidAge, vegiOption, eatCheeseOption
     * ************************************************************************/

		cout << setw(33) <<"What is your kid's name?";
		cin  >> kidName;
        cin.ignore(100,'\n');

		cout << setw(33) <<"How old is the kid?";
		cin  >> kidAge;
        cin.ignore(100,'\n');

		cout << setw(33) << "Vegeterian(Y/N)?";
		cin.get(vegiOption);
        cin.ignore(100,'\n');

		cout << setw(33) << "Does he/she eat cheese(Y/N)?";
        cin.get(eatCheeseOption);
        cin.ignore(100,'\n');

    /*************************************************************************
	 * PROCESS - the process to find which ride and food is good for each kid
     * based on their age and eating habitats
     *************************************************************************/

    vegeterian   = ( vegiOption == 'Y' && eatCheeseOption == 'Y' );
    vegan        = ( vegiOption == 'Y' && eatCheeseOption == 'N' );
    noDairy      = ( vegiOption == 'N' && eatCheeseOption == 'N' );
    eatAny       = ( vegiOption == 'N' && eatCheeseOption == 'Y' );

    infant       = (kidAge < 5);
    child        = (kidAge >= 5 && kidAge <= 12);
    teen         = (kidAge > 12);


        /*************************************************************************
         * OUTPUT AND PROCESS - output the best ride for each kid based on their 
         * age also add the admission fee to the total admission for for the 
         * process of total cost.
         *************************************************************************/
        
        if ( infant )
        {
            adminFee += 0;
            cout << endl << endl << kidName << " will be going on the Ferris Wheel and will be visiting the sheep petting zoo." << endl;

        }
        if ( child )
        {
            adminFee += 15;
            cout << endl << endl << kidName << " will be going on the Tea Cups and will be playing Laser Tag." << endl;
        }
        if ( teen )
        {
            adminFee += 20;
            cout << kidName << " \n\nwill be going to the Roller Coaster and the Zipline." << endl;
        }


        /*************************************************************************
         * OUTPUT AND PROCESS - output the best food for the kid based on the 
         * eating habitats and also add the food cost to the total food cost for 
         * the total cost of the theme park
         *************************************************************************/
        if ( eatAny )
        {
            foodCost += 3.50;
            cout << "Pack a Cheeseburger for " << kidName << "!" << endl << endl << endl;
        }

        if ( noDairy )
        {
            foodCost += 3.25;
            cout << "Pack a Hamburger for " << kidName << "!" << endl << endl << endl;
        }

        if ( vegeterian )
        {
            foodCost += 2.50;
            cout << "Pack a Cheese Pizza for " << kidName << "!" << endl << endl << endl;
        }

        if ( vegan )
        {
            foodCost += 1.75;
            cout << "Pack a Happy Garden meal for " << kidName << "!" << endl << endl << endl;
        }



	}
    /* PROCESS - process the total cost of the theme park and the average cost for each kid*/
    totalCost = foodCost + adminFee;
    avgCost   = (float)totalCost/10;


    /*************************************************************************
     * OUTPUT - the total cost and the average cost per kid
     *************************************************************************/
    cout << left;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << setw(30) << "The total cost for the day is" << right << "$" << setw(6) << totalCost << endl;
    cout << setw(30) << "The averag cost per kid is"    << right << "$" << setw(6) << avgCost   << endl;
    cout << right;


	return 0;
}

