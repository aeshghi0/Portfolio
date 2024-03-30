/******************************************************************************
* AUTHOR     : Ali Eshghi
* STUDENT IDs: 1112261
* AS #6	     : Assignment 6 - Loop & Boolean Expressions
* CLASS      : CS1A
* SECTION    : TTH: 8am
* DUE DATE   : 5/07/19
******************************************************************************/

#include "header.h"

/******************************************************************************
* Army Recruit Program
*
* -----------------------------------------------------------------------------
*
* This program helps the recruiters in the Army to decide who is valid to enroll
* in the Academy and who is not based on the Height and Weight requirement
* -----------------------------------------------------------------------------
* INPUT:
*      gender    : Gender of the candidate
*      height	 : Height of the candidate
*      weight	 : Weight of the candidate
*
* OUTPUT:
*      acceptableHeight : tells if the candidate met the height requirement
*      acceptableWeight : tells if the candidate met the weight requirement
*      acceptCount		: tells how many candidate(s) have been accepted
*      acceptPercent	: tells the percentage of the candidates who has been
*      					  accepted
* ****************************************************************************/

/**************************************************************************
	 *   * CONSTANTS
     * ------------------------------------------------------------------------
     * OUTPUT - USED FOR CLASS HEADING
     * ------------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * AS_NUM     : Assignment number (specific to this Assignment)
	 * LAB_NAME   : Title of the Lab
	 *************************************************************************/
	 const char PROGRAMMERS[] = "Ali Eshghi";
	 const char CLASS[]       = "CS1A";
	 const char SECTION[]     = "TTH: 8:00a - 10:30a";
	 const int  AS_NUM        =  6;
	 const char LAB_NAME[]    = "Military Academy candidates accpetance";

int main()
{

	const	int		MALE_MIN_HEIGHT  = 65;
	const	int		MALE_MAX_HEIGHT  = 80;
	const	int		FMALE_MIN_HEIGHT = 62;
	const	int		FMALE_MAX_HEIGHT = 75;

	const	int		MALE_MIN_WEIGHT  = 130;
	const	int		MALE_MAX_WEIGHT  = 250;
	const	int		FMALE_MIN_WEIGHT = 110;
	const	int		FMALE_MAX_WEIGHT = 185;

	char	    gender;			 //IN & PROCESS-user input and use in the process
	int         candCount;       //PROCESS-counter of the times the loop is run
	int         acceptCount;     //PROCESS-counter of the an if statement
	double		acceptPercent;	 //PROCESS & OUTPUT - got in the process and used in the output

	bool 		acceptableHeight;//PROCESS- helps the program for the boolean expression
	bool		acceptableWeight;//PROCESS- helps the program for the boolean expression


	/**********************************************************************
	 * OUTPUT - Class Heading
	 **********************************************************************/
	 cout << left;
	 cout << "*************************************************\n";
	 cout << "* PROGRAMMED BY : "     << PROGRAMMERS<< endl;
     cout << "* "         << setw(14) << "CLASS"    << ": " << CLASS    << endl;
     cout << "* "         << setw(14) << "SECTION"  << ": " << SECTION  << endl;
     cout << "* LAB_NAME" << setw(9)  << AS_NUM    << ": " << LAB_NAME << endl;
     cout << "**************************************************\n\n";
     cout << right;

    /**************************************************************************
     * INPUT - assign the counter to the 0 :
     * candCount & acceptCount
     * ************************************************************************/

    candCount = 0;
    acceptCount = 0;



    cout << "Please enter the candidate's information (enter 'X' to exit)" << endl;

    /**************************************************************************
     * INPUT - gender gets the character from the function:
     * gender
     * ************************************************************************/

	gender = GenderErrorCheck();


	/*************************************************************************
	 * PROCESS - the process to find if the candidate is accepted:
     *************************************************************************/
    while (gender != 'x' && gender != 'X')
	{
    	/**************************************************************************
         * INPUT - the boolean expression gets the height from the function :
         * acceptableHeight
         * ************************************************************************/

	    acceptableHeight = IsHeightValid(MALE_MIN_HEIGHT, MALE_MAX_HEIGHT,
	    					   FMALE_MIN_HEIGHT, FMALE_MAX_HEIGHT, gender);


	    /**************************************************************************
         * INPUT - the boolean expression gets the height from the function :
         * acceptableWeight
         * ************************************************************************/

    	acceptableWeight = IsWeightValid(MALE_MIN_WEIGHT, MALE_MAX_WEIGHT,
    			 	 	 	 	FMALE_MIN_WEIGHT, FMALE_MAX_WEIGHT, gender);




    	/*************************************************************************
         * OUTPUT - the output based on the Height and Weight of the candidate as
         * 			told in the paper:
         *************************************************************************/

        if (acceptableHeight && acceptableWeight)
        {
            cout << "\n\nThe candidate has been ACCEPTED!\n\n\n";
            acceptCount++;
        }
        else if (acceptableHeight)
        {
            cout << "\n\nThis candidate has been rejected based on the WEIGHT requirement.\n\n\n";
        }
        else if (acceptableWeight)
        {
            cout << "\n\nThis candidate has been rejected based on the HEIGHT requirement.\n\n\n";
        }
        else
        {
            cout << "\n\nThis candidate has been rejected based on the HEIGHT and WEIGHT requirements.\n\n\n";
        }

        candCount++;	//the counter for the final output


        cin.ignore(100,'\n');
        cout << "Please enter the candidate's information (enter 'X' to exit)" << endl;
        gender = GenderErrorCheck();

	}//end of the while loop



	/*************************************************************************
     * OUTPUT - the output of the percentage and accepted candidates based on
     * 			the counter:
     *************************************************************************/

    if (candCount > 0)
    {
    	acceptPercent = (acceptCount * 100 ) / (float)candCount;
		cout << left;
		cout << setprecision(0) << fixed <<endl << endl;
		cout << acceptCount << " candidate(s) accepted!" << endl;
		cout << "That's "   << acceptPercent << "%!" << endl;
	}//end of if-statement

	return 0;
}//end of main


