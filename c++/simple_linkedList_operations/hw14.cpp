#include<iostream>
#include"LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> list1;
    list1.insertAtTail(88);
    list1.insertAtTail(78);
    list1.insertAtTail(62);
    list1.insertAtTail(143);
    list1.insertAtTail(60);
    list1.print();
    cout << endl;

    LinkedList<int> list2 = list1;
    list2.print();
    cout << endl;

    LinkedList<int> list3;
    list3 = list2;
    list3.print();
    list3.deleteFromHead();
    list3.print();
    list3.deleteFromTail();
    list3.print();
    list3.insertAfter(62, 111);
    list3.print();
    list3.insertBefore(62, 222);
    list3.print();
    list3.sortAscending();
    list3.print();
    list3.sortDescending();
    list3.print();
    cout << endl;

    return 0;

}