
#include "MyHeader.h"

void SearchTitle(MovieNode *head, ofstream &outFile)
{
	 MovieNode *movPtr;	    //PROCESS - stores the target name


	 bool found;			//PROCESS - condition value for the searched name

	 int strLen;
	 int i;

	 int maxSizeLine;

	 string word;
	 string line;
	 string summary;

	 word.clear();
	 line.clear();

	 maxSizeLine = 75;


	 //CHECKS FOR EMPTY LIST

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
		 cout << "Which title are you looking for? ";
		 getline(cin, movPtr -> title);

		 cout << endl << endl;
		 cout << "Searching for the title " << movPtr -> title;
		 cout << endl;

		 //GOES ATHROUGH THE LIST



		 while ((head -> next != NULL) && !found)
		 {
			 //IF FOUND
			 cout << head -> title;

			 if (head -> title == movPtr -> title)
			 {
				 cout << "Found the movie " << head -> title << "!";

				 outFile << endl;
				 outFile << left;
				 outFile << "****************************************************";
				 outFile << "****************************************************";
				 outFile << "*" << endl;
				 outFile << "Title: " << head -> title << endl;
				 outFile << "----------------------------------------------------";
				 outFile << "----------------------------------------------------";
				 outFile << "-" << endl;
				 outFile << setw(18) << "Year: " << head -> year << "Rating: "
					  << head -> rate;
				 outFile << "----------------------------------------------------";
				 outFile << "----------------------------------------------------";
				 outFile << "-" << endl;
				 outFile << setw(57) << "Leading Actor:    " << head -> leadActor;
				 outFile << right;
				 outFile << "Genre 1: " << head -> genre << endl;
				 outFile << left;
				 outFile << setw(57) << "Supporting Actor: "
					  << head -> supportActor;
				 outFile << right;
				 outFile << "Genre 2: " << head -> altGenre << endl;
				 outFile << "----------------------------------------------------";
				 outFile << "----------------------------------------------------";
				 outFile << "-" << endl;
				 outFile << "PLOT:" << endl;

				 strLen = head -> synopsis.length();

				 summary = head -> synopsis;

				 for(i = 0; i <= strLen; i++)
				 {
					 if(summary[i] != ' ')
					 {
						 word = word + head -> synopsis[i];
					 }
					 else
					 {
						 if(line.length() + word.length() > maxSizeLine)
						 {
							 outFile << line;
							 line.clear();

						 }

						 line = word + " ";
						 word.clear();
					 }
				 }
				 outFile << "****************************************************";
				 outFile << "****************************************************";
				 outFile << "*" << endl;

				 found = true;
			 }

			 else
			 {
				 head  = head -> next;
				 found = false;

			 }

		 }

		 if (head -> next == NULL && head -> title == movPtr -> title)
		 {
			 outFile << endl;
			 outFile << left;
			 outFile << "****************************************************";
			 outFile << "****************************************************";
			 outFile << "*" << endl;
			 outFile << "Title: " << head -> title << endl;
			 outFile << "----------------------------------------------------";
			 outFile << "----------------------------------------------------";
			 outFile << "-" << endl;
			 outFile << setw(18) << "Year: " << head -> year << "Rating: "
				  << head -> rate;
			 outFile << "----------------------------------------------------";
			 outFile << "----------------------------------------------------";
			 outFile << "-" << endl;
			 outFile << setw(57) << "Leading Actor:    " << head -> leadActor;
			 outFile << right;
			 outFile << "Genre 1: " << head -> genre << endl;
			 outFile << left;
			 outFile << setw(57) << "Supporting Actor: "
				  << head -> supportActor;
			 outFile << right;
			 outFile << "Genre 2: " << head -> altGenre << endl;
			 outFile << "----------------------------------------------------";
			 outFile << "----------------------------------------------------";
			 outFile << "-" << endl;
			 outFile << "PLOT:" << endl;

			 strLen = head -> synopsis.length();

			 summary = head ->synopsis;

			 for(i = 0; i <= strLen; i++)
			 {
				 if(head -> synopsis[i] != ' ')
				 {
					 word = word + head -> synopsis[i];
				 }
				 else
				 {
					 if(line.length() + word.length() > maxSizeLine)
					 {
						 outFile << line;
						 line.clear();

					 }

					 line = word + " ";
					 word.clear();
				 }
			 }
			 outFile << "****************************************************";
			 outFile << "****************************************************";
			 outFile << "*" << endl;

			 found = true;
		 }

		 //IF NOT FOUND IN THE LIST

		 else if (!found)
		 {
			 cout << endl;
			 cout << "sorry, the movie \"" << movPtr -> title;
			 cout << "\" was not found!";
			 cout << endl;
		 }

	 }

	 movPtr = NULL;
}
