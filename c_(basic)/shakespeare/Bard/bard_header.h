#include <iostream>
#include <string>

using namespace std;

//Struct type Node to store data
struct Node {

  string word;
  int frequency;
  int length;
  Node *next;
};

class LinkedList{

  private:
    Node **head; //header pointer to pointer for array of linked list
    Node **sorted; //sorted array of linked list (based on frequency and alphabetically)
    void sort(Node *, int);  //function to insert Node into its correct position.

  public:
    LinkedList();  //constructor
    void insert(string);  //Inserts a new node to the head of the linked list
    Node *find(string); //searches for a string in the list; returns pointer to that node if found; if not returns NULL
    void print_word(Node*, ofstream &); //prints out the

    Node *delete_node(string);  //function to delete a Node
    void delete_and_free_node(string); //function to delete and free the memory of a Node
    void delete_list(); //function to delete the list

    //function to sort the words alphabetically
    void sort_words_by_frequency();
    Node *most_frequent_by_length_and_rank(int, int);  //function to find word based on length and rank


};