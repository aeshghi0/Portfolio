/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #8  : Templates
 * DUE DATE   : 25 March 2020
 ******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

//Preprocessor directives

#include<iostream>	//for input and output

//using the name space standard
using namespace std;

//template class for Queue
template <class X>

//class Queue: class with attributes of the queues
class Queue
{
private:
	X *a;
	int frnt,rear;
	int size;
	int maxSize;

public:
//constrcutor
	Queue(int n)
	{
		a=new X[n];
		maxSize=n;
		frnt =0;
		rear=-1;
		size=0;
	}

	//function to insert element in queue
	void enqueue(X value)
	{
		if(isFull())
		{
			cout<<"Queue is full... Can't insert'\n";
			return;
		}
		rear=(rear+1)%maxSize;
		a[rear]=value;
		cout<<"Inserted element "<<value<<"\n";
		size++;
	}


	//function to remove element from queue
	X dequeue()
	{
		X temp;
		if(isEmpty())
		{
			cout<<"Queue is empty.....\n";
			return temp;
		}

		temp=a[frnt];
		frnt=(frnt+1)%maxSize;
		size--;
		cout<<"Removed element "<<temp<<"\n";
		return temp;
	}


	//function to get the front element from queue
	X front()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty...\n";
		}
		return a[frnt];
	}


	//function to check if the queue is full
	bool isFull()
	{
		if(size==maxSize)
			return true;
		else
			return false;
	}


	//function to check is queue is empty
	bool isEmpty()
	{
		if(size==0)
			return true;
		else
			return false;
	}


	//function to get the size of the queue
	int Size()
	{
		return size;
	}
};



#endif /* MYHEADER_H_ */
