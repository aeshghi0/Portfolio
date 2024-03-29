#pragma once
#include<iostream>
#include"Dnode.h"
using namespace std;

template<typename T>
class DLinkedList
{
public:
    DLinkedList() 
    { 
        head = NULL; 
        current = NULL;
    }

    bool isEmptyList()
    {
        return !getHead();
    }

    void InsertAtTail(T val)
    {
        DNode<T>* temp = new DNode<T>;
        temp->setData(val);

        if(isEmptyList())
        {
            setHead(temp);
            setCurrent(getHead());
        }

        else
        {
            getCurrent()->setNext(temp);
            temp->setPrevious(getCurrent());
            setCuurent(temp);
        }
    }

    void deleteFromTail()
    {
        if(!isEmptyList())
        {
            if(getHead()->getNext())
            {
                DNode<T>* temp = getCurrent();
                setCurrent(getCurrent()->getPrevious());
                getCurrent()->setNext(NULL);
                delete temp;
            }

            else
            {
                delete getHead();
                setHead(NULL);
                setCurrent(NULL);
            }
            
        }
    }

    void insertAtHead(T val)
    {
        DNode<T>* temp = new DNode<T>;
        temp->setData(val);

        if(isEmptyList())
        {
            setHead(temp);
            setCurrent(getHead());
        }

        else
        {
            getHead()->setPrevious(temp);
            temp->setNext(getHead());
            setHead(temp);
        }
        
    }

    void DeleteFromHead()
    {
        if(!isEmptyList())
        {
            if(getHead()->getNext())
            {
                DNode<T>* temp = getHead();
                setHead(getHead()->getNext());
                getHead()->getPrevious(NULL);
                delete temp;
            }

            else
            {
                DNode<T>* temp = getHead();
                delete temp;
                setHead(NULL);
                setCurrent(NULL);
            }
            
        }
    }

    void printFromHead()
    {
        DNode<T>* temp = getHead();
        cout << "Current List: ";

        while(temp)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }

        cout << endl;
    }

    void printFromTail()
    {
        DNode<T>* temp = getCurrent();
        cout << "Current List: ";

        while(temp)
        {
            cout << temp->getData() << " ";
            temp = temp->getPrevious();
        }

        cout << endl;
    }

    ~DLinkedList() = default;

private:
    DNode<T>* head;
    DNode<T>* current;
    
    void setHead(DNode<T>* val) { this->head = val; }
    DNode<T>* getHead() { return this->head; }
    void setCurrent(DNode<T>* val) { this->current = val; }
    DNode<T>* getCurrent() { return this->current; }
};