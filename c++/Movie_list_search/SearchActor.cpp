#include "MyHeader.h"

void SearchActor(MovieNode *head, ofstream &outFile)
{
	/**************************************************************************
	 *                             VARIABLES
	 **************************************************************************/

	MovieNode *moviePtr;	//Proc - stores the target name
	MovieNode node;			//Proc & In - passes the info into persPtr


	int i;					//Int - counts the founded data

	/**************************************************************************
	 *                            INITIALIZING
	 **************************************************************************/

	i = 1;

	/**************************************************************************
	 *                             PROCESSING
	 **************************************************************************/


	if (head == NULL)
	{
		cout << endl;

		cout << "Search operation is not available for an empty list.";

		cout << endl;
	}

	else
	{
		//NEW NODE

		moviePtr = new MovieNode;

		//INPUT

		cout << endl;

		cout << "Which actor are you looking for? ";

		getline(cin, node.leadActor);

		*moviePtr = node;

		cout << endl;

		cout << "Searching for the actor " << moviePtr -> leadActor;

		cout << endl;

		outFile << "\nSearch by actor for " << moviePtr -> genre << " found:";

		outFile << endl << endl;

		outFile << left;

		outFile << setw(9)  << "MOVIE #"           ;
		outFile << setw(48) << "TITLE"             ;
		outFile << setw(5)  << "YEAR"              ;
		outFile << setw(8)  << "RATING"            ;
		outFile << setw(18) << "GENRE"             ;
		outFile << setw(18) << "ALT GENRE"         ;
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

		//GOES THROUGH THE LIST

		while(head->next != NULL)
		{
			if ((head -> leadActor    == moviePtr -> leadActor) ||
				(head -> supportActor == moviePtr -> leadActor))
			{

				outFile << right;
				outFile << setw(4)  << i << "      "       ;
				outFile << left;
				outFile << setw(47) << head -> title       ;
				outFile << setw(8)  << head -> year        ;
				outFile << setw(5)  << head -> rate        ;
				outFile << setw(18) << head -> genre       ;
				outFile << setw(18) << head -> altGenre    ;
				outFile << setw(20) << head -> leadActor   ;
				outFile << setw(20) << head -> supportActor;
				outFile << endl;
				outFile << left;

				i++;
				head = head -> next;

			}

			else
			{
				head  = head -> next;
			}

		} // END - WHILE


		if ((head -> next == NULL &&
			(head -> leadActor    == moviePtr -> leadActor)) ||
			(head -> next == NULL &&
			(head -> supportActor == moviePtr -> leadActor)))
		{

			outFile << right;
			outFile << setw(4)  << i << "      "       ;
			outFile << left;
			outFile << setw(47) << head -> title       ;
			outFile << setw(8)  << head -> year        ;
			outFile << setw(5)  << head -> rate        ;
			outFile << setw(18) << head -> genre       ;
			outFile << setw(18) << head -> altGenre    ;
			outFile << setw(20) << head -> leadActor   ;
			outFile << setw(20) << head -> supportActor;
			outFile << endl;
			outFile << left;
			i++;
			head = head -> next;

		}

		//IF NOT FOUND IN THE LIST

		if (i == 1)
		{
			cout << "Sorry, no movies for the actor, " << moviePtr -> genre
			 	 << " were found.";

			cout << endl;
		}

		//OUTPUT RESULT INTO THE CONSOLE

		if(i > 1)
		{
			cout << "Found " << i-1 << " movies for the actor "
				 << moviePtr -> genre << '!' << endl;
		}

		moviePtr = NULL;
		delete moviePtr;

	 }

}
