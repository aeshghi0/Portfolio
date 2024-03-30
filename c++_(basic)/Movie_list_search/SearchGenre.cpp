#include "MyHeader.h"

void SearchGenre(MovieNode *head, ofstream &outFile)
{
	 MovieNode *movPtr;	//Proc - stores the target name
	 MovieNode node;		//Proc & In - passes the info into persPtr

	 bool found;			//Proc - condition value for the searched name

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

		 cout << endl;
		 cout << "What genre are you looking for? ";
		 getline(cin, node.genre);

		 *movPtr = node;

		 cout << endl << endl;
		 cout << "Searching for the genre" << movPtr -> genre;
		 cout << endl;

		 //GOES ATHROUGH THE LIST




		 while ((head -> next != NULL) && !found)
		 {
			 //IF FOUND

			 if (head -> genre    == movPtr -> genre ||
				 head -> altGenre == movPtr -> genre ||
				 (head -> genre + " " +head -> altGenre) == movPtr -> genre||
				 (head -> altGenre + " " +head -> genre) == movPtr -> genre)
			 {

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

		 if ((head -> next == NULL && (head -> genre == movPtr -> genre)) ||
			 (head -> next == NULL && (head -> altGenre == movPtr -> genre)) ||
			 (head -> next == NULL &&(head -> genre + " " + head -> altGenre == movPtr -> genre)) ||
			 (head -> next == NULL &&(head -> altGenre + " " + head -> genre == movPtr -> genre)))
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
			 cout << "sorry, no movies for the genre, " << movPtr -> genre;
			 cout << " were not found!";
			 cout << endl;
		 }

		 if(found)
		 {
			 cout << "Found " << i << "movies for the genre "
				  << movPtr -> genre << endl << endl;
		 }

	 }

}

