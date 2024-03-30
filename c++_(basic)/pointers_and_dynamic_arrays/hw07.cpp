/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH - 3pm
 * HW07 	  : Pointers and Dynamic arryas
 * DUE DATE   : 30 June 2020
 ******************************************************************************/

#include"inventoryManagement.h"

/*******************************************************************************
* hw07
* ------------------------------------------------------------------------------
* This program will get name, price, and quantity of some sport equipments and
* using the pointer variable, it stores them and send them to a display function
* for output on the screen, then using the struct variables, we calculate that if
* a user buys something from store, how many of that item is going to be
* available after that and also it calculates that how much the cost is going to
* be, before and after tax.
* ------------------------------------------------------------------------------
* INPUT  : Nothing
* ------------------------------------------------------------------------------
* PROCESS: the program calculates Mark's purchas bill for four pairs of Nike
* 		   basketball shoes, five Under Armour T-shirts, six Under Armour shorts
* 		   , and one pair of Asics running shoes, including the total cost
* 		   before and after tax. Assume the tax rate is 7.75%
* ------------------------------------------------------------------------------
* OUTPUT : The progeam will output a recipt of the items that mark purchased,
* 		   and outputs the total price of what mark has purchased before and
* 		   after tax. It also outputs the store inventory before and after
* 		   mark's purchase
*******************************************************************************/
int main()
{
	/***************
	 *  VARIABLES  *
	 ***************/

    inventoryManagement inventory;		//PROCESS - classType object
	// inventoryManagement *inventory2(inventory);	//PROCESS - calls the copy constructor
	double total;								//PROCESS & OUT - calculating the total price
	double tax;									//PROCESS & OUT - calculating the tax

	inventory.addItem("Nike basketball shoes", 145.99, 22);
	inventory.addItem("Under Armor T-shirt", 29.99, 33);
	inventory.addItem("Brooks running shoe", 111.44, 11);
	inventory.addItem("Asics running shoe", 165.88, 20);
	inventory.addItem("Nike Shorts", 45.77, 77);

	//inventoryManagement *inventory2(inventory);	//PROCESS - calls the copy constructor


    cout << "Inventory before marks purchase:" << endl;
	inventory.displayInventory();	//displays the inventory
	cout << endl << endl;

	cout <<"Secondary Inventory list(Using copy constructor): " << endl;
	//inventory2->displayInventory();	//displays the inventory using object initialized 
									//by copy constructor
	cout << endl << endl;

	cout<<"*** Purchase bill *** "						  <<endl;
	cout<<"Item No. Name of equipment\tCost\t\tQuantity"  <<endl;
	cout<<"1. Nike basketball shoes\t$145.99\t\t2 "       <<endl;
	cout<<"2. Under Armour T-shirt\t\t$29.99\t\t3 "       <<endl;
	cout<<"3. Nike shorts\t\t\t$45.77\t\t4 "      		  <<endl;
	cout<<"4. Brooks running shoes\t\t$111.44\t\t1 "	  <<endl;

	//calculating total purchase price
	total = 2 * 145.99 + 3 * 29.99 + 4 * 45.77 + 111.44;
	cout<<" Total Cost: $"<< total << endl;

	//calculating the tax
	tax = total * 8.25/100;

	cout << "Tax(8.25%) $" << tax << endl;

	cout <<"Total cost $" << (total + tax) << endl << endl;

	//calling member function to change the inventory after the purchase
	inventory.changeInventory();

	//inventory after the purchase
	cout << "\n\nInventory after marks purchase:" << endl;
	inventory.displayInventory();

	return 0;
}
