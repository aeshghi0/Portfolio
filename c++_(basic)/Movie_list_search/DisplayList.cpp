#include "MyHeader.h"


void DisplayList(MovieNode *head, ofstream &outFile)
{
	//VARIABLES

	int i;	//Calc & Out - used for quantity

	//INITIALIZING

	i = 1;

	 if (head == NULL)
	 {
		 cout << endl;

		 cout << "Can't Display an empty list!";

		 cout << endl;
	 }


	 else
	 {
		//SETTING UP THE TABLE

		cout << "Listing all movies!" << endl << endl;

		outFile << endl;

		outFile << left;

		outFile << setw(9)  << "MOVIE #"           ;
		outFile << setw(49) << "TITLE"             ;
		outFile << setw(6)  << "YEAR"              ;
		outFile << setw(9)  << "RATING"            ;
		outFile << setw(19) << "GENRE"             ;
		outFile << setw(19) << "ALT GENRE"         ;
		outFile << setw(20) << "LEAD ACTOR"        ;
		outFile << setw(20) << "SUPPORTING ACTOR"  ;

		outFile << left;

		outFile << endl;

		outFile << "------- ";
		outFile << "------------------------------------------------ ";
		outFile << "---- ";
		outFile << "------ ";
		outFile << "----------------- ";
		outFile << "----------------- ";
		outFile << "------------------- ";
		outFile << "------------------- ";

		outFile << endl;

		//OUTPUTTING DATA IN ALPHABETICAL ORDER

		while(head != NULL)
		{
			outFile << right;
			outFile << setw(4)  << i << "      "       ;
			outFile << left;
			outFile << setw(49) << head -> title       ;
			outFile << setw(9)  << head -> year        ;
			outFile << setw(6)  << head -> rate        ;
			outFile << setw(19) << head -> genre       ;
			outFile << setw(19) << head -> altGenre    ;
			outFile << setw(20) << head -> leadActor   ;
			outFile << setw(20) << head -> supportActor;
			outFile << endl;
			outFile << left;

			i++;
			head = head -> next;
		}

	 }

	 outFile << endl;
}



