/******************************************************************************
* AUTHOR     : Ali Eshghi
* STUDENT IDs: 1112261
* LAB # 14   : Boolean Expression
* CLASS      : CS1A
* SECTION    : TTH: 8am
* DUE DATE   : 4/23/19
******************************************************************************/
#include<iostream> //for the string sequences
#include<iomanip>  // for mathematics equations
using namespace std;
    /**************************************************************************
	 *   * CONSTANTS
     * ------------------------------------------------------------------------
     * OUTPUT - USED FOR CLASS HEADING
     * ------------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab
	 *************************************************************************/
    const char PROGRAMMERS[]  = "Ali Eshghi";
	 const char CLASS[]       = "CS1A";
	 const char SECTION[]     = "TTH: 8:00a - 10:30a";
	 const int  LAB_NUM       =  14;
	 const char LAB_NAME[]    = "Boolean Expression (pt.4)";

    char    letGrade;
    int     totGrade;
    int     caseCount;
    int     gradeCount;
    double  gpa;

int main()
{
    char classCode;
    bool invalid;

    cout << " Enter the Class Code:  ";
    cin  >> classCode;
    toupper(classCode);

    invalid = (classCode != 'F' && classCode != 'S' && classCode != 'J' && classCode != 'R') &&
              ( classCode != 'f' && classCode != 's' && classCode != 'j' && classCode != 'r') ;

    do
    {
        if(invalid)
        {
            cout << classCode << " is INVALID INPUT - Please try again" << endl;
            cout << " Enter the Class Code:  ";
            cin  >> classCode;
        }
    } while (invalid);

    cout << classCode << " is a valid - thank you" << endl;
    
}