#pragma once
template<typename T>
class DNode
{
public:
    DNode()
    {
        //this->setData(NULL);
        this->setNext(NULL);
        this->setPrev(NULL);
    }

    //DNode(T val) {this->setData(val);}

    ~DNode() = default;


    T getData()
    {
        return this->Data;
    }

    void setData(T val)
    {
        this->Data = val;
    }

    DNode* getNext()
    {
        return this->next;
    }

    void setNext(DNode* val)
    {
        this->next = val;
    }

    DNode* getPrevious()
    {
        return this->prev;
    }

    void setPrevious(DNode* val)
    {
        this->prev = val;
    }
private:
    T Data;
    DNode<T>* next;
    DNode<T>* prev;
};