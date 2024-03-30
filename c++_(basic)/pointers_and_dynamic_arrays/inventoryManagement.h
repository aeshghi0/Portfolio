/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH - 3pm
 * HW07 	  : Pointers and Dynamic arryas
 * DUE DATE   : 30 June 2020
 ******************************************************************************/

#include<iostream>		//For input, output
#include<iomanip>		//For style
#include<string>		//For using string
using namespace std;	//using namespace standard

#define SIZE 5			//defining the constant SIZE = 5


struct inventory
{
    /***************
     *  VARIABLES  *
     ***************/

    string 	eqpName;  //PROCESS & OUT - storing the name
    double 	price;	  //PROCESS & OUT - storing the price
    int		quantity; //PROCESS & OUT - storing the quantity
};

class inventoryManagement
{
public:

    //default constructor
    inventoryManagement();

    //copy constructor
    inventoryManagement(const inventoryManagement& obj);

    //Destructor
    ~inventoryManagement();

    //function to add the item to the array
    void addItem(string name, double price, int qnt);

    //member function that prints the inventory
    void displayInventory();

    //member function that changes the inventory after the purchase
    void changeInventory();

private:
    int count;
    inventory** inv;
};

