#include "MyHeader.h"

void SearchYear(MovieNode *head, ofstream &outFile)
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
			 cout << "Which year are you looking for? ";
			 cin  >> node.year;

			 if(!(cin >> node.year))
			 {
				 cin.clear();
				 cout << "**** Please input a number between 1878 and 3000 ****"
					  << endl;
			 }

			 else if(node.year > 3000 || node.year < 1878)
			 {
				 cout << "**** The number " << node.year << "is an invalid ";
				 cout << "entry         ****" << endl;
				 cout << "**** Please input a number between 1878 and 3000 ****"
					  << endl;
			 }

		 }while(node.year < 1878 || node.year > 3000);



		 *movPtr = node;

		 cout << endl << endl;
		 cout << "Searching for the year";
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

			 if (head -> year    == movPtr -> year)
			 {



					while(head != NULL)
					{
						outFile << right;
						outFile << setw(4)  << i << "      "       ;
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

		 if (head -> next == NULL && (head -> year == movPtr -> year))
		 {
				while(head != NULL)
				{
					outFile << right;
					outFile << setw(4)  << i << "      "       ;
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
			 cout << "sorry, no movies for year, " << movPtr -> year;
			 cout << " were not found!";
			 cout << endl;
		 }

		 if(found)
		 {
			 cout << "Found " << i << "movies for the actor "
				  << movPtr -> year << endl << endl;
		 }

	 }

}

