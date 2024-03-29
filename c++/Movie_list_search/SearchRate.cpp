#include "MyHeader.h"

void SearchRate(MovieNode *head, ofstream &outFile)
{
	 MovieNode *movPtr;	    //PROCESS - stores the target name
	 MovieNode node;		//PROCESS & IN - passes the info into persPtr

	 bool found;			//PROCESS - condition value for the searched name

	 int i;

	 i = 1;


	 found = false;

	 if (head == NULL)
	 {
		 cout << endl;
		 cout << "Search operation is not available for an empty list.";
		 cout << endl;
	 }

	 else
	 {
		 //NEW NODE

		 movPtr = new MovieNode;

		 //INPUT

		 do
		 {
			 cout << endl;
			 cout << "Which rating are you looking for? ";
			 cin  >> node.rate;

			 if(!(cin >> node.rate))
			 {
				 cin.clear();
				 cout << "**** Please input a number between 0 and 9 ****"
					  << endl;
			 }

			 else if(node.rate > 0 || node.rate < 9)
			 {
				 cout << "**** The number " << node.year << "is an invalid ";
				 cout << "entry     ****" << endl;
				 cout << "**** Please input a number between 0 and 9 ****"
					  << endl;
			 }

		 }while(node.rate < 0 || node.rate > 9);


		 *movPtr = node;

		 cout << endl << endl;
		 cout << "Searching for the rating";
		 cout << endl;

		 //GOES ATHROUGH THE LIST


		 outFile << endl;

		 outFile << left;

		 outFile << setw(9)  << "MOVIE #"           ;
		 outFile << setw(50) << "TITLE"             ;
		 outFile << setw(6)  << "YEAR"              ;
		 outFile << setw(8)  << "RATING"            ;
	   	 outFile << setw(19) << "GENRE"             ;
		 outFile << setw(19) << "ALT GENRE"         ;
		 outFile << setw(21) << "LEAD ACTOR"        ;
		 outFile << setw(21) << "SUPPORTING ACTOR"  ;

		 outFile << left;

		 outFile << endl;

		 outFile << "-------- ";
		 outFile << "------------------------------------------------- ";
		 outFile << "----- ";
		 outFile << "------- ";
		 outFile << "------------------ ";
		 outFile << "------------------ ";
		 outFile << "-------------------- ";
		 outFile << "-------------------- ";

		 outFile << endl;



		 while ((head -> next != NULL) && !found)
		 {
			 //IF FOUND

			 if (head -> rate    == movPtr -> rate)
			 {



					while(head != NULL)
					{
						outFile << right;
						outFile << setw(4)  << i << "      "        ;
						outFile << left;
						outFile << setw(50) << head -> title       ;
						outFile << setw(6)  << head -> year        ;
						outFile << setw(8)  << head -> rate        ;
						outFile << setw(19) << head -> genre       ;
						outFile << setw(19) << head -> altGenre    ;
						outFile << setw(21) << head -> leadActor   ;
						outFile << setw(21) << head -> supportActor;
						outFile << endl;
						outFile << left;

						i++;
						head = head -> next;
					}

				 found = true;
			 }

			 else
			 {
				 head  = head -> next;
				 found = false;

			 }


		 }

		 cout << " ";

		 if (head -> next == NULL && (head -> rate == movPtr -> rate))
		 {
				while(head != NULL)
				{
					outFile << right;
					outFile << setw(4)  << i << "      "        ;
					outFile << left;
					outFile << setw(50) << head -> title       ;
					outFile << setw(6)  << head -> year        ;
					outFile << setw(8)  << head -> rate        ;
					outFile << setw(19) << head -> genre       ;
					outFile << setw(19) << head -> altGenre    ;
					outFile << setw(21) << head -> leadActor   ;
					outFile << setw(21) << head -> supportActor;
					outFile << endl;
					outFile << left;

					i++;
					head = head -> next;
				}

			found = true;
		 }

		 //IF NOT FOUND IN THE LIST

		 else if (!found)
		 {
			 cout << endl;
			 cout << "sorry, no movies for rating, " << movPtr -> rate;
			 cout << " were not found!";
			 cout << endl;
		 }

		 if(found)
		 {
			 cout << "Found " << i << "movies for the rating "
				  << movPtr -> rate << endl << endl;
		 }

	 }

}

