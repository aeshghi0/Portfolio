#include "MyHeader.h"

void CreatList(MovieNode *&head)
{

	fstream     inFile;

	//OPEN FILE

	inFile.open("inFile.txt");

	MovieNode *movPtr;		//In & Calc  - node to input data
	MovieNode *searchPtr;		//Calc       - node to go through the loop
	MovieNode node;
								//				main linked list

	bool found;					//Proc - lcv  varibale

	movPtr = new MovieNode;

	while (inFile)
	{
		//FIRST INPUT

		getline(inFile,node.title);
		getline(inFile,node.leadActor);
		getline(inFile,node.supportActor);
		getline(inFile,node.genre);
		getline(inFile,node.altGenre);
		inFile >> node.year;
		inFile.ignore(10000,'\n');
		inFile >> node.rate;
		getline(inFile,node.synopsis);
		inFile.ignore(10000,'\n');
		inFile.ignore(10000,'\n');


		//CREATE A NEW NODE

		movPtr   = new MovieNode;
		*movPtr  = node;
		searchPtr= head;

		found     = false;

		//IF EMPTY
		if (head == NULL)
		{

			movPtr -> next = head;
			movPtr -> prev = NULL;
			head           = movPtr;
			movPtr         = NULL;

		}


		//ADDING IN TO THE FRONT

		else if(head -> title > movPtr -> title)
		{

			movPtr -> prev  = NULL;
			movPtr -> next  = head;
			head -> prev    = movPtr;
			head            = movPtr;
			movPtr          = NULL;

		}

		else
		{
			//COMPARING NODES TO SEE WHICH SHOULD GO WHERE

			while ((searchPtr -> next != NULL) && !found)
			{

				if (searchPtr -> next -> title > movPtr -> title)
				{

					found = true;

				}

				else
				{

					searchPtr = searchPtr -> next;

				}
			}

			//TAIL

			if(searchPtr -> next == NULL)
			{

				movPtr -> next = NULL;
				movPtr -> prev = searchPtr;
				searchPtr -> next = movPtr;

				movPtr = NULL;
			}

			//MIDDLE

			else
			{

				movPtr -> next = searchPtr -> next;
				movPtr -> prev = searchPtr;
				searchPtr -> next -> prev = movPtr;
				searchPtr -> next = movPtr;

				searchPtr = movPtr = NULL;

			}

		} // END - ELSE


	} // END - WHILE

	//CLOSE FILE

	inFile.close();

	cout << endl;

}



