/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#include "MyHeader.h"
#include "ClassHeader.h"


/*******************************************************************************
 * Methods for class StackList
 *******************************************************************************/

/****************************************************************
 * StackList ();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/

StackList::StackList()
{
	stackCount = 0;
	head       = NULL;
}


/****************************************************************
 * ~StackList ();
 * Destructor; does not perform any specific function
 * Parameters: none
 * Return: none
 ***************************************************************/
StackList::~StackList()
{
	DVDNode *DVDPtr;

	//Clear the list
	DVDPtr = head;
	while(DVDPtr != NULL)
	{
		head = head -> next;
		delete DVDPtr;

		DVDPtr = head;
	}
}


/*******************************************************************
 * void Push (DVDNode newDVD);
 *
 * Mutator; This method will add a DVD node to the list to the front
 *------------------------------------------------------------------
 * Parameter: newDVD (DVDNode) //IN - node to be added to list
 *------------------------------------------------------------------
 * Return: none
 *******************************************************************/
void StackList::Push(DVDNode newDVD)
{
	DVDNode *movPtr;		//In & Calc  - node to input data


	movPtr = head;

	movPtr = new DVDNode; //adding new node for the list
	*movPtr = newDVD;	  //constents copied

	//add to the front
	movPtr -> next = head;
	head = movPtr;

	//increment the stack count
	stackCount++;

	movPtr = NULL;


}

/*******************************************************************
 * DVDNode Pop ();
 *
 * Mutator; This method will remove a DVD node from the front of the
 * list and return the DVDNode being removed
 *------------------------------------------------------------------
 * Parameter: none
 *------------------------------------------------------------------
 * Return: popDVD (DVDNode)
 *******************************************************************/
DVDNode StackList::Pop()
{
	DVDNode		searchPtr;
	DVDNode		*movPtr;

	movPtr = head;


	if(IsEmpty())
	{
		cout << "The list is empty";

		return searchPtr;
	}

	searchPtr = Peek();
	movPtr = movPtr -> next;

	delete movPtr;

	movPtr = NULL;

	return searchPtr;
}

/****************************************************************
 * bool IsEmpty () const;
 *
 * Accessor; This method will return the boolean value whether
 * the list is empty or not empty
 * --------------------------------------------------------------
 * Parameters: none
 * --------------------------------------------------------------
 * Return: empty (bool)
 ***************************************************************/
bool StackList::IsEmpty() const
{
	bool empty;

	if(stackCount == 0)
	{
		empty = true;
	}
	else
	{
		empty = false;
	}

	return empty;
}

/****************************************************************
 * DVDNode Peek () const;
 *
 * Accessor; This method will return the DVD node of the first
 * element on the list
 * --------------------------------------------------------------
 * Parameters: none
 * --------------------------------------------------------------
 * Return: returnDVD (DVDNode)
 ***************************************************************/
DVDNode StackList::Peek() const
{
	DVDNode	DVDPtr;
	DVDPtr.title = "EMPTY";

	if(IsEmpty())
	{
		DVDPtr = *head;
	}

	return DVDPtr;

}

/****************************************************************
 * int Size () const;
 *
 * Accessor; This method will return the size of the list
 * --------------------------------------------------------------
 * Parameters: none
 * --------------------------------------------------------------
 * Return: stackCount (int)
 ***************************************************************/
int StackList::Size() const
{
	return stackCount;
}


/*******************************************************************************
 * Methods for class MovieList
 *******************************************************************************/

/****************************************************************
 * MovieList ();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
MovieList::MovieList() {}

/****************************************************************
 * ~MovieList ();
 * Destructor; does not perform any specific function
 * Parameters: none
 * Return: none
 ***************************************************************/
MovieList::~MovieList() {}


/*******************************************************************
 * void CreateList (string inputFileName);
 *
 * Mutator; This method will create a movie list using the input file
 * data
 *------------------------------------------------------------------
 * Parameter: inputFileName (string) //IN - input file name
 *------------------------------------------------------------------
 * Return: none
 *******************************************************************/
void MovieList::CreatList(string inFileName)
{
	ifstream	inFile;

	DVDNode		node;

	inFile.open(inFileName);

	while(inFile)
	{
		getline(inFile, node.title);
		getline(inFile, node.leadActor);
		getline(inFile, node.supActor);
		getline(inFile, node.genre);
		getline(inFile, node.altGenre);
		inFile >> node.year;
		inFile >> node.rating;
		inFile.ignore(10000,'\n');
		getline(inFile, node.synopsis);
		inFile.ignore(10000,'\n');

		StackList::Push(node);

	}

	inFile.close();
}


/****************************************************************
 * void OutputList (string outputFileName) const;
 *
 * Accessor; This method will output the list onto the output file
 * --------------------------------------------------------------
 * Parameters: outputFileName (string) //IN - output file name
 * --------------------------------------------------------------
 * Return: none
 ***************************************************************/
void MovieList::OutputList(string outFileName) const
{

	ofstream	outFile;
	int			movieCount;
	string		plot;
	DVDNode		*ptr;


	outFile.open(outFileName);

	movieCount = 0;
	ptr = NULL;
	ptr = head;

	//printing the class header to the output file
	PrintHeader(outFile, "OOP - DVD Movie List", 5, 'A');

	while(ptr != NULL)
	{
		movieCount++;


		outFile << endl;
		outFile << left;
		outFile << "****************************************************";
		outFile << "****************************************************";
		outFile << setw(18) << "MOVIE #: " << movieCount << "Title: "
				<< ptr -> title
				<< endl;
		outFile << "----------------------------------------------------";
		outFile << "----------------------------------------------------";
		outFile << "-" << endl;
		outFile << setw(18) << "Year: " << ptr -> year << "Rating: "
		  << ptr -> rating;
		outFile << "----------------------------------------------------";
		outFile << "----------------------------------------------------";
		outFile << "-" << endl;
		outFile << setw(57) << "Leading Actor:    " << ptr -> leadActor;
		outFile << right;
		outFile << "Genre 1: " << ptr -> genre << endl;
		outFile << left;
		outFile << setw(57) << "Supporting Actor: "
		  << ptr -> supActor;
		outFile << right;
		outFile << "Genre 2: " << ptr -> altGenre << endl;
		outFile << "----------------------------------------------------";
		outFile << "----------------------------------------------------";
		outFile << "-" << endl;
		outFile << "PLOT:" << endl;
		plot = WordWrap(ptr -> synopsis);
		outFile << plot << endl;
		outFile << "****************************************************";
		outFile << "****************************************************";

		//next node on the list
		ptr = ptr -> next;

	}

	outFile.close();

}


/****************************************************************
 * string WorpWarp (string plot) const;
 *
 * Accessor; This method alter the string to wordwrap around a
 * certain length of characters
 * --------------------------------------------------------------
 * Parameters: plot (string) //IN - synopsis
 * --------------------------------------------------------------
 * Return: returnStr (string)
 ***************************************************************/
string MovieList::WordWrap(string plot) const
{
	const int MAX_SIZE = 75;
	int		i;
	int		size;
	string	str;
	string	line;
	string	word;

	size = plot.length();

	str.clear();
	word.clear();
	line.clear();

	//plot
	for(int i = 0; i <= size; i++)
	{
		if(plot[i] != ' ')
		{
			//concatenates chars until space is reached
			word = word + plot[i];
		}
		else
		{
			if(line.length() + word.length() > MAX_SIZE)
			{
				str = str + line + '\n';
				line.clear();
			}
		}

		line = line + word + " ";
		word.clear();
	}

	//output the last line
	if(line != " ")
	{
		str = str + line + word + '\n';
	}

	word.clear();
	line.clear();

	return str;

}
/********************************************************************
 * FUNCTION PrintHeader
 * __________________________________________________________________
 *
 * This function outputs a header including the lab name, lab number,
 * the programmer's name, the class name, and the section time
 * as a string by ostream
 * __________________________________________________________________
 * PRE-CONDITIONS:
 * output - ostream variable to dynamically choose datatype
 * of cout or ofstream
 * labName - Name of the lab. The labName should be previously
 * defined
 * labNumber - Number of the lab. The labNumber should be
 * previously defined
 * labType - type of assignment
 * 'A' - assignment
 * 'L' - lab
 *
 * POST-CONDITIONS:
 * outputs header as string
 *******************************************************************/
void MovieList::PrintClassHeader(ostream	&output,
								 string		labName,
								 int		labNumber,
								 char		labType) const
{
	//Defining and initializing constant variables
	const char PROGRAMMER[30] = "Ali Eshghi";
	const char CLASS[5] = "CS1B";
	const char SECTION[20] = "MW: 7:30p - 9:50p";

	// OUTPUT - Class Heading
	output << left;
	output << endl;
	output << "********************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* ";

	if (toupper(labType) == 'L')
	{
		output << "LAB #" << setw(8);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(1);
	}
	output << labNumber << " : " << labName;
	output << "\n******************************************************";
	output << "**\n\n";
	output << right;

}





