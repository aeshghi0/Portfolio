#pragma once
template <typename T>
class Node
{
public:
    //Set data can not be NULL for some structs, Remove this statement if didn't work
    Node()
    {
        //this->setData(NULL);
        this->setNext(NULL);
    }

    Node(T val)
    {
        this->setData(val);
    }

    T getData()
    {
        return this->Data;
    }

    void setData(T val)
    {
        this->Data = val;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* val)
    {
        this->next = val;
    }

private:
    T Data;
    Node* next;
};