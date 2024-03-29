//hw12
//Implementation of an array based Queue

#include<iostream>
#include<cstdlib>
using namespace std;

/*************************************************************************
 * AUTHOR     : Ali Eshghi
 * HW12       : Templates Queue
 * CLASS      : CS 1C
 * SECTION    : July 16th, 2020
*************************************************************************/

//Template class for Queue
template <class X>
class Queue
{
public:
    //constructor
    Queue(int n)
    {
        a = new X[n];
        maxSize = n;
        front = 0;
        back = -1;
        size = 0;

    }

    //copy constructor
    Queue(const Queue& obj);

    //function to insert element in queue
    void enqueue(X value)
    {
        if(isFull())
        {
            cout << "<Queue is full, can not insert>" << endl;
            return;
        }

        back = (back+1) % maxSize;
        a[back] = value;
        cout << "<The element " << value << " has been inserted successfully>" << endl;
        size++;
    }

    //function to remove element from queue
    X dequeue()
    {
        X temp;

        if(isEmpty())
        {
            cout << "<The Queue is empty>" << endl;
            return temp;
        }

        temp = a[front];
        front = (front+1) % maxSize;
        size--;
        cout << "<Element " << temp << " was removed from the list>" << endl;
        return temp;
    }

    //function to retrieve the first element from the queue
    X getFront()
    {
        if(isEmpty())
        {
            cout << "<Queue is empty... terminating the program>" << endl;
            exit(-1);
        }

        return a[front];
    }

    //function to check is the queue is full
    bool isFull()
    {
        if(size == maxSize)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    //function to check is the queue is empty
    bool isEmpty()
    {
        if(size == 0)
        {
            return true;
        }

        else
        {
            return false;
        }
        
    }

    //function to get the size of the queue
    int getSize()
    {
        return size;
    }

    //function to print the Queue
    void printQueue()
    {
        
        if(isEmpty())
        {
            cout << "<The Queue is empty... nothing to print" << endl;
            return;
        }

        else
        {
            cout << "------------------------------------" << endl;
            cout << "printing Queue: ";

            for(int i = 0; i < size; i++)
            {
                cout << a[i] << " ";
            }

            cout << "\n------------------------------------" << endl;
        }
        



    }

    //Assignment operator overload
    const Queue& operator=(const Queue& obj)
    {
        Queue<int> dummy(size);

        if(this != &obj)
        {
            dummy(size) = obj;
        }
        
        return *this;
    }

private:
    X *a;
    int front;
    int back;
    int size;
    int maxSize;
};

//*********************** HW12 main ************************
int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*           Running HW12             * " << endl;
	cout << "*      Programmed by Ali Eshghi      * " << endl;
	cout << "*      CS1C July 16th, 2020          * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

    //creating a string queue
    cout << "Testing Queue implementation on string data type: " << endl;
    Queue<string> q(7);

    //calling the copy constructor
    //Queue<string> p = q;

    //Performing 6 additions
    q.enqueue("a");
    q.printQueue();
    q.enqueue("b");
    q.printQueue();
    q.enqueue("c");
    q.printQueue();
    q.enqueue("d");
    q.printQueue();
    q.enqueue("e");
    q.printQueue();
    q.enqueue("f");
    q.printQueue();

    //performing 4 deletation
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.printQueue();

    //performing 5 addition
    q.enqueue("g");
    q.printQueue();
    q.enqueue("h");
    q.printQueue();
    q.enqueue("i");
    q.printQueue();
    q.enqueue("j");
    q.printQueue();
    q.enqueue("k");
    q.printQueue();

    //performing three deletation
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.dequeue();
    q.printQueue();

    cout << endl << endl;


    //creating a float queue
    cout << "Testing Queue implementation on float data type: " << endl;
    Queue<float> f(7);
    //Performing 6 additions
    f.enqueue(1);
    f.printQueue();
    f.enqueue(2);
    f.printQueue();
    f.enqueue(3);
    f.printQueue();
    f.enqueue(4);
    f.printQueue();
    f.enqueue(5);
    f.printQueue();
    f.enqueue(6);
    f.printQueue();

    //performing 4 deletation
    f.dequeue();
    f.printQueue();
    f.dequeue();
    f.printQueue();
    f.dequeue();
    f.printQueue();
    f.dequeue();
    f.printQueue();

    //performing 5 additions
    f.enqueue(7);
    f.printQueue();
    f.enqueue(8);
    f.printQueue();
    f.enqueue(9);
    f.printQueue();
    f.enqueue(10);
    f.printQueue();
    f.enqueue(11);

    //performing three deletation
    f.dequeue();
    f.printQueue();
    f.dequeue();
    f.printQueue();
    f.dequeue();
    f.printQueue();


    return 0;
}