/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH 3pm
 * HW01       : random number generation
 * DUE DATE   : 04 June 2020
 ******************************************************************************/

#include"MyHeader.h"

//Reverse the given number
void reverse_SumDigits(int rnum)
{
	//Variables
	double rev_rnum = 0;	//PROCESS & OUT - saves the reversed number

	while(rnum>0)
	{
		rev_rnum = rev_rnum*10 + rnum%10;
		rnum = rnum/10;
	}

	//display reversed number
	cout << "Reverse the digits of the number: " << rev_rnum << endl;

	//Sum of digits of number
	int sum = 0;
	int temp = rev_rnum;

	//finding sum of digits of given number
	while(temp>0)
	{
		sum = sum+ temp%10;
		temp = temp/10;
	}

	//display the sum of digits of number
	cout << "Sum the digits of the number: " << sum << endl;

}

//Triple the given number
void triple(int rnum)
{
	//Variables
	int tripleNum = 0;	//PROCESS & OUT - saves the triple of the number

	tripleNum = rnum*3;

	//display the triple of the given number
	cout << "Triple of the number: " << tripleNum << endl;

}

//Sort the array
void sort(int rnumAr[])
{
	//Variables
	int i,j,temp;	//PROCESS - using for sorting

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(rnumAr[j] > rnumAr[j+1])
			{
				temp = rnumAr[j];
				rnumAr[j] = rnumAr[j+1];
				rnumAr[j+1] = temp;
			}
		}
	}

	cout << "The array has been sorted successfully" << endl;
}

//Write the array to an external file
void FileWrite(int rnumAr[])
{
	//Variables
	ofstream outFile;	//PROCESS - file variable for the ecternal file
	outFile.open("Ar_File.txt");	//opens the external file

	//printing the array on an external file
	for(int i = 0; i < 10; i++)
	{
		outFile << rnumAr[i] << "," << endl;
	}

	outFile.close();	//closes the external file

	cout << "The array has been written in the file successfully" << endl;
}

//Call a function to read the external file
void FileRead()
{
	//Variable
	string tempAr[10] = {" "};	//PROCESS - string saving the read input from the file

	ifstream inFile;	//PROCESS - file variable for the external file
	inFile.open("Ar_File.txt");	//opens the external file

	//reading from the external file as a string
	for(int i = 0; i < 10; i++)
	{
		getline(inFile,tempAr[i]);
	}

	inFile.close();	//closes the external file

	cout << "The file has been read as strings successfully" << endl;
}

//Print the array in a function
void print(int rnumAr[])
{
	//printing the array
	for(int i = 0; i < 10; i++)
	{
		cout << rnumAr[i] << ",";
	}

}



