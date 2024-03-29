#include "header.h"



char	    gender;
int		    weight;         //IN & PROCESS-user input and use in the process
int		    height;         //IN & PROCESS-user input and use in the process
int         candCount;      //PROCESS-counter of the times the loop is run
int         acceptCount;    //PROCESS-counter of the an if statement

bool 	acceptableHeight;
bool	acceptableWeight;








int main()
{


    candCount = 1;
    acceptCount = 0;
    



    cout << "Please enter the candidate's information (enter 'X' to exit)" << endl;
 
	gender = GenderErrorCheck();


    while (gender != 'x' && gender != 'X')
	{
        
	    height = IsHeightValid();

	    acceptableHeight = TheAcceptableHeight(height, gender);

        
        weight = IsWeightValid();
        acceptableWeight = TheAcceptableWeight(weight, gender);


        if (acceptableHeight && acceptableWeight)
        {
            cout << "\n\nThe candidate has been ACCEPTED\n\n\n";
            acceptCount++;
        }
        else if (!acceptableWeight && acceptableHeight)
        {
            cout << "\n\nThis candidate has been rejected based on the WEIGHT requirement.\n\n\n";
        }
        else if (!acceptableHeight && acceptableWeight)
        {
            cout << "\n\nThis candidate has been rejected based on the HEIGHTrequirement.\n\n\n";
        }
        else if (!acceptableHeight && !acceptableWeight)
        {
            cout << "\n\nThis candidate has been rejected based on the HEIGHTand WEIGHTrequirements.\n\n\n";
        }

        candCount++;

       
        cin.ignore(100,'\n');
        cout << "Please enter the candidate's information (enter 'X' to exit)" << endl;
        gender = GenderErrorCheck();

	}//end of the while loop

    cout << candCount;
    cout << acceptCount;


	return 0;
}
