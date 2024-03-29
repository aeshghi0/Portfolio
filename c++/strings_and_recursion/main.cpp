/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #10 : Recursion
 * DUE DATE   : 6 April 2020
 ******************************************************************************/

#include<iostream>	//using input and output
#include<string>	//using string
using namespace std;//using namespace standard

void reverse(string& alpha, int x, int y)     //function reverse
{
	//Variables

	char t;	//PROCESS - using to store the swapped character of the string

	if ((x>y))
	{                                  //here does not use any additional string.
		return;
	}

	//PROCESS - swapping the characters
	t=alpha[x];
	alpha[x]=alpha[y];
	alpha[y]=t;
	reverse(alpha, x + 1 , y - 1); //revesre function called again (recursion)
}

int main()
{
	/************************************************************
	 * Recursion
	 * _________________________________________________________
	 * This program has a pre-saved alphabet string data. the
	 * program promts the user for two integers, the starting
	 * index and the ending index. then the program reverses the
	 * alphabet letter character of the index in the string from
	 * the starting index to the ending index (user input). the
	 * program does that two times and the third time the program
	 * has presaved data on the starting and ending index so that
	 * the whole string gets reversed
	 * _________________________________________________________
	 * INPUT: u; k; - input for the start and end index
	 *
	 * OUTPUT: FIRST - the string with start to end index characters
	 * 		   reversed
	 *		   SECOND - the string with start to end index characters
	 * 		   reversed
	 * 		   THIRD - the whole string reversed
	 *
	 ************************************************************/

	cout << "/************************************************************\n"
		 << "* Recursion\n"
		 << "* _________________________________________________________\n"
		 << "* This program has a pre-saved alphabet string data. the \n"
		 << "* program promts the user for two integers, the starting \n"
		 << "* index and the ending index. then the program reverses the \n"
		 << "* alphabet letter character of the index in the string from\n"
		 << "* the starting index to the ending index (user input). the \n"
		 << "* program does that two times and the third time the program \n"
		 << "* has presaved data on the starting and ending index so that \n"
		 << "* the whole string gets reversed\n"
		 << "* _________________________________________________________\n"
		 << "* INPUT: u; k; - input for the start and end index\n"
		 << "*\n"
		 << "* OUTPUT: FIRST - the string with start to end index characters\n"
		 << "* 		   reversed\n"
		 << "*		   SECOND - the string with start to end index characters\n"
		 << "* 		   reversed\n"
		 << "* 		   THIRD - the whole string reversed\n"
		 << "*\n"
		 << "************************************************************/\n\n";

	//Variables

	string alpha;	//PROCESS - stores the alphabet string
	int u,k;		//INPUT & PROCESS - stores the number of start and end of characters
					//for swapping

	//FIRST MODIFYING
	cout <<"The string input as default (Alphabet):\n";          //storing.
	alpha = "abcdefghijklmnopqrstuvwxyz";
	cout << alpha << endl;
	cout<<"enter starting index:"; //reading starting index.
	cin>>u;
	cout<<"enter ending index:";     //reading ending index.
	cin>>k;
	reverse(alpha, --u, --k);	//reverse function called
	cout<<endl<<"your modified string is "<<alpha;      //printing modified string
	cout << endl << endl;

	//SECOND MODIFYING
	alpha = "abcdefghijklmnopqrstuvwxyz";	//reinitializing the data
	u = 0;
	k = 0;
	cout<<"enter starting index:"; //reading starting index.
	cin>>u;
	cout<<"enter ending index:";     //reading ending index.
	cin>>k;
	reverse(alpha, --u, --k);	//reverse function called
	cout<<endl<<"your modified string is "<<alpha;      //printing modified string
	cout << endl << endl;

	//THIRD MODIFYING
	alpha = "abcdefghijklmnopqrstuvwxyz";	//reinitializing the data
	u = 1;	//storing the pre-input data for the whole length of alphabet
	k = 26;
	reverse(alpha, --u, --k);
	cout<<endl<<"your modified string is "<<alpha;      //printing modified string





    return 0;
}
