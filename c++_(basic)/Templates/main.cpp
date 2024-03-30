/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #8  : Templates
 * DUE DATE   : 25 March 2020
 ******************************************************************************/

#include"MyHeader.h"

int main(){
	/****************************************************************
	 * Queuing and deleting the objects to the stacks
	 * ______________________________________________________________
	 * using the templates and the functions, the user can queue or
	 * delete objects from the head of the stacks and delete from the
	 * end of the stack. Also, using the class function, the program
	 * determines if the stack is empty or full
	 * ______________________________________________________________
	 * INPUT: N/A
	 *
	 * OUTPUT: outputs step by step of adding the objects the objects
	 * 		   or deleting the objects from the stack, also outputs
	 * 		   if the
	 *
	 ****************************************************************/


	cout << "/****************************************************************\n"
		 << " * Queuing and deleting the objects to the stacks\n"
		 << " * ______________________________________________________________\n"
		 << " * using the templates and the functions, the user can queue or\n"
		 << " * delete objects from the head of the stacks and delete from the\n"
		 << " * end of the stack. Also, using the class function, the program\n"
		 << " * determines if the stack is empty or full\n"
		 << " * ______________________________________________________________\n"
		 << " * INPUT: N/A\n"
		 << " *\n"
		 << " * OUTPUT: outputs step by step of adding the objects the objects\n"
		 << " * 		   or deleting the objects from the stack, also outputs\n"
		 << " * 		   if the\n"
		 << " *\n"
		 << "****************************************************************/\n\n";

//creating a Character queue
Queue<string> q(10);

//Queuing the string characters to the head of the stack
q.enqueue("a");
q.enqueue("b");
q.enqueue("c");
q.enqueue("d");
q.enqueue("e");
q.enqueue("f");
//deleting the string characters from buttom of the stack
q.dequeue();
q.dequeue();
q.dequeue();
//Queuing the string characters to the head of the stack
q.enqueue("g");
q.enqueue("h");
q.enqueue("i");
q.enqueue("j");
//deleting the string characters from buttom of the stack
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
cout<<"Front of queue: "<<q.front()<<"\n";


//creating an integer queue
Queue<int> d(10);

//Queuing the integers to the head of the stack
d.enqueue(1);
d.enqueue(2);
d.enqueue(3);
d.enqueue(4);
d.enqueue(5);
d.enqueue(6);
//deleting the integers from buttom of the stack
d.dequeue();
d.dequeue();
//Queuing the integers to the head of the stack
d.enqueue(7);
d.enqueue(8);
d.enqueue(9);
//deleting the integers from buttom of the stack
d.dequeue();
d.dequeue();
cout<<"Front of queue: "<<d.front()<<"\n\n";


//creating an Double queue
Queue<double> i(10);

//Queuing the doubles to the head of the stack
i.enqueue(1.1);
i.enqueue(2.1);
i.enqueue(3.3);
i.enqueue(4.4);
i.enqueue(5.5);
i.enqueue(6.6);
//deleting the doubles from buttom of the stack
i.dequeue();
//Queuing the doubles to the head of the stack
i.enqueue(7.7);
i.enqueue(8.8);
//deleting the doubles from buttom of the stack
i.dequeue();
i.dequeue();
i.dequeue();
i.dequeue();
i.dequeue();
cout<<"Front of queue: "<<i.front()<<"\n\n";


return 0;
}




