/***********************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #1  : Functions and arrays
 * DUE DATE   : 19 September 2019
 ***********************************************/
#include "MyHeader.h"

/******************************************************************************
 * Function : FileOutput
 * ---------------------------------------------------------------------------
 * This function will out put the results that were assigned to variables in
 * the main from the other functions to the output file. the function is a void
 * type function, so it doesn't need any return.
 *****************************************************************************/

void FileOutput(ostream &outFile,
				string   nameAr[],
				int		 idAr[],
				float    balanceAr[],
				int      option,
				int		 balanceIndex,
				float	 sumOrAvg,
				int		 nameIndex)

{

	//This if statement is for when the user chooses the option 1. It outputs
	//the larger balance along side of the name and id of the person who has
	//the larger balance. It uses the integer returned from the "SearchBalance"
	//function to use in the parallel arrays to get the right data.
	if (option == 1)
	{
		cout    << "\nFinding the larger balance..." << endl << endl;
		outFile << left;
		outFile << "Larger Balance:\n";
		outFile << setw(9) << "ID #" << setw(25) << "NAME"     << "BALANCE DUE\n";
		outFile << setw(9) << "----" << setw(25) <<"--------------------" << "-----------" << endl;
		outFile << setw(9) << idAr[balanceIndex] << setw(25) << nameAr[balanceIndex]
				<< "$"      << right << setw(10) << balanceAr[balanceIndex] << endl << endl;
		outFile << right;
	}//End of if statement

	//This if statement is for when the user chooses the option 2. It outputs
	//the smaller balance along side of the name and id of the person who has
	//the smaller balance. It uses the integer returned from the "SearchBalance"
	//function to use in the parallel arrays to get the right data.
	else if (option == 2)
	{
		cout    << "Finding the smaller balance..." << endl << endl;
		outFile << left;
		outFile << "Smaller Balance:\n";
		outFile << setw(9) << "ID #" << setw(25) << "NAME"     << "BALANCE DUE\n";
		outFile << setw(9) << "----" << setw(25) <<"--------------------" << "-----------" << endl;
		outFile << setw(9) << idAr[balanceIndex] << setw(25) << nameAr[balanceIndex]
				<< "$"      << right << setw(10) << balanceAr[balanceIndex] << endl << endl;
		outFile << right;
	}//End of if statement

	//This if statement is for when the user chooses the option 3. It outputs
	//the sum of all balances using the float number returned to main from the
	// function named "SumOrAvg".
	else if (option == 3)
	{
		cout    << "Obtaining the sum of all balances..." << endl << endl;
		outFile << left;
		outFile << "Sum of Balances for all persons :\n";
		outFile << setw(10) << "$" <<sumOrAvg << endl << endl;
		outFile << right;
	}//End of if statement

	//This if statement is for when the user chooses the option 4. It outputs
	//the average of all balances using the float number returned to main from
	//the function named "SumOrAvg".
	else if (option == 4)
	{
		cout    << "Obtaining the average of all balances..." << endl << endl;
		outFile << left;
		outFile << "Average Balance for all persons\n";
		outFile << setprecision(2) << fixed;
		outFile << setw(10) << "$" << sumOrAvg << endl << endl;
		outFile << right;
	}//End of if statement

	//This if statement is for when the user chooses the option 5. It outputs
	//the name and id and balance of the person searched by the user in the
	//function called "SearchName", using the integer returned from the function
	//as the integer in the parallel arrays.
	else if (option == 5)
	{
		outFile << left;
		outFile << "Search Name :" << endl;

		//This if statement indicated that if the integer returned form the
		//"SearchName" function is between 0 - 9, then it can output the name,
		//id, and balance of the person based on the parallel arrays.
		if (nameIndex >= 0 && nameIndex <10)
		{

			outFile << setw(9) << "ID #" << setw(25) << "NAME"     << "BALANCE DUE\n";
			outFile << setw(9) << "----" << setw(25) <<"--------------------"
					<< "-----------" << endl;
			outFile << setw(9) << idAr[nameIndex] << setw(25) << nameAr[nameIndex]
					<< "$"      << right << setw(10) << balanceAr[nameIndex] << endl << endl;
			outFile << right;
		}//End of if statement

		//else statement indicates that if the integer returned from the
		//"SearchName" function is bigger than 9, that means there are
		//no names in the list matching the searched name.
		else
		{
			outFile << setw(9) << endl;
			outFile << "Name Not Found in the list." << endl << endl;

		}//End of else statement

		outFile << right;
	}



}
