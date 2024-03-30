#pragma once
#include"node.h"
#include<iostream>
using namespace std;

template<typename T>
class LinkedList
{
public:
    //constructor sets head and tail to NULL
    LinkedList() 
    { 
        setHead(NULL); 
        setCurrent(NULL); 
    }

    //copy constructor
    LinkedList(LinkedList &obj)
    {
        Node<T>temp;

        for(Node<T>* o = obj.getHead(), *n = &temp; o; o = o->getNext())
        {
            n->setNext(new Node<T>(o->getData()));
            n = n->getNext();
        }

        this->head = temp.getNext();
    }

    //assignment operator overload
    void operator=(LinkedList &obj)
    {
        Node<T>temp;
        
        for(Node<T>* o = obj.getHead(), *n = &temp; o; o = o->getNext())
        {
            n->setNext(new Node<T>(o->getData()));
            n = n->getNext();
        }

        this->head = temp.getNext();
    }

    //Returns if list is empty or not
    bool isEmptyList()
    {
        if(getHead() == NULL)
        {
            return true;
        }

        return false;
    }

    //Returns the data of current list from head
    T getHeadData()
    {
        return getHead()->getData();
    }

    //Returns the data of current list from tail
    T getTailData()
    {
        return getCurrent()->getData();
    }

    //Prints the current list from head to tail
    void print()
    {
        Node<T>* temp = getHead();
        cout << "Current List: ";

        while(temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }

        cout << endl;
    }

    //Insert the new value at Head
    void insertAtHead(int val)
    {
        Node<T>* temp = new Node<T>;
        temp->setData(val);
        temp->setNext(this->head);

        if(getHead() == NULL)
        {
            setHead(temp);
            setCurrent(head);
        }

        else
        {
            temp->setNext(getHead());
            setHead(temp);
        }
        
    }

    //Insert the new value at tail
    void insertAtTail(T val)
    {
        Node<T>* temp = new Node<T>;
        temp->setData(val);
        temp->setNext(NULL);

        if(head == NULL)
        {
            setHead(temp);
            setCurrent(head);
        }

        else
        {
            getCurrent()->setNext(temp);
            setCurrent(temp);
        }
        
    }

    //Delete the value at head
    void deleteFromHead()
    {
        if(!isEmptyList())
        {
            if(getHead()->getNext() != NULL)
            {
                Node<T>* temp = getHead();
                setHead(getHead()->getNext());
                delete temp;
            }

            else
            {
                Node<T>* temp = getHead();
                delete temp;
                setHead(NULL);
            }
            
        }
    }

    //Delete value from the tail
    void deleteFromTail()
    {
        if(!isEmptyList())
        {
            setCurrent(getHead());
            if(getCurrent() == getHead() && getCurrent()->getNext() == NULL)
            {
                delete getCurrent();
                setHead(NULL);
            }

            else
            {
                while(getCurrent()->getNext()->getNext() != NULL)
                {
                    setCurrent(getCurrent()->getNext());
                }

                delete getCurrent()->getNext();
                getCurrent()-> setNext(NULL);
            }
            
        }
    }

    //Searches for a value, and returns the address of node which contains the value
    Node<T>* search(T val)
    {
        setCurrent(getHead());

        if(isEmptyList())
            return NULL;
        
        else
        {
            while(getCurrent() != NULL)
            {
                if(getCurrent()->getData() == val)
                    return getCurrent();
                
                setCurrent(getCurrent()->getNext());
            }

            return NULL;
        }
        
    }

    //Insert a value, after a specific value
    void insertAfter(T check, T val)
    {
        setCurrent(getHead());
        Node<T>* ptr = search(check);

        if(!ptr)
            cout << "***value not found***" << endl;

        else
        {
            Node<T>* temp = new Node<T>;
            temp->setData(val);
            temp->setNext(ptr->getNext());
            ptr->setNext(temp);
        }
        
    }

    //Insert a value before a specific value
    void insertBefore(T check, T val)
    {
        setCurrent(getHead());
        Node<T>* ptr = search(check);
        
        if(!ptr)
            cout << "***Value not found***" << endl;
        
        else
        {
            Node<T>* temp = new Node<T>;
            temp->setData(ptr->getData());
            ptr->setData(val);
            temp->setNext(ptr->getNext());
            ptr->setNext(temp);

        }
        
    }

    //sorts the list value by value in descending, not node by node, until the list is fully in order
    void sortDescending()
    {
        Node<T>* temp;
        bool swap = true;

        while(swap)
        {
            swap = false;
            setCurrent(head);

            while(getCurrent())
            {
                temp = getCurrent();
                setCurrent(getCurrent()->getNext());

                if(getCurrent() && current->getData() > temp->getData())
                {
                    swap = true;
                    T val;
                    val = temp->getData();
                    temp->setData(getCurrent()->getData());
                    getCurrent()->setData(val);
                }
            }
        } 
    }

    //sorts the list value by vlaue in ascending order, not node by node, until the list is fully in order
    void sortAscending()
    {
        Node<T>* temp;
        bool swap = true;

        while(swap)
        {
            swap = false;
            setCurrent(head);

            while(getCurrent())
            {
                temp = getCurrent();
                setCurrent(getCurrent()->getNext());

                if(getCurrent() && current->getData() < temp->getData())
                {
                    swap = true;
                    T val;
                    val = temp->getData();
                    temp->setData(getCurrent()->getData());
                    getCurrent()->setData(val);
                }
            }
        }
    }

    //destructor
    ~LinkedList() = default;
private:
    //Head
    Node<T>* head;

    //Tail
    Node<T>* current;

    //Set head as it is a private member
    void setHead(Node<T>* val) { this->head = val; }

    //Set tail as it is a private member
    void setCurrent(Node<T>* val) { this->current = val; }

    //get head as it is a private member
    Node<T>* getHead() { return this->head; }

    //get tail as it is a private member
    Node<T>* getCurrent() { return this-> current; }
};