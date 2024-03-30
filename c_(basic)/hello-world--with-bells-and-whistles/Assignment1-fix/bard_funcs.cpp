#include "bard_header.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

#define SIZE 50

using namespace std;

//Default constructor to set the head to NULL
LinkedList:: LinkedList(){

  head = new Node*[SIZE]; //initializing array of linked list for creating the list of words
  sorted = new Node*[SIZE]; //initializing array of linked list for sorting the list of words
  
  for(int i = 0; i < SIZE; i++){  //initializing all the indicies to point to NULL for start
    *(head + i) = NULL;
    *(sorted + i) = NULL;
  }

}

//Function to insert a word into the linked list
void LinkedList::insert(string word){ //TEST: modifying inserting to the list


  int indx = word.length() - 5; //getting the index of position the word belongs to (-5 becuase there is no words less than 5 characters)
  Node *ptr = head[indx]; //assigning the pointer to the list of the index on array
  
  if(ptr != NULL){  //if the list is not empty, checks the list if the word already exist, otherwise ignores checking process

    Node *curr = ptr;   //a pointer to traverse the list on the index

    while(curr != NULL){  //Test: for insert checking until the curr node is NULL
      if(curr->word.compare(word) == 0){  //if the word already in the list then just increment the frequency
        curr->frequency++;
        return;
      }
      curr = curr->next;
    }
  }
  //if not - add the word to the list
  //creating a new node and specifying all the attributes
  Node *new_node = new Node;
  new_node->word = word;
  new_node->frequency = 1;
  new_node->length = word.length();

  //Adding the Node to the list
  new_node->next = ptr;
  head[indx] = new_node;  
}

//Function to search for a word passed onto it; if found returns a pointer to the node; if not found returns NULL (not used in this program)
Node *LinkedList::find(string word){

  int indx = word.length() - 5;

  //A pointer that goes through the list from head
  Node *curr = head[indx];

  //Goes through the list until it points to NULL (end of the list)
  while(curr->next != NULL){

    //if the concerned word is the same as the node word; return the pointer to the node
    if(curr->word.compare(word) == 0){
      return curr;
    }
    //(if not) the pointer points to the next node
    curr = curr->next;
  }
  
  //if the none of the words in the nodes of the linkedlist matches the concerned word; return NULL
  return NULL;
}


//funtion to print the word
void LinkedList::print_word(Node *node, ofstream &ofile){

  if(node != NULL){
    //Test with Frequency
    cout << node->word << " : " << node->frequency <<endl; //print on screen
    ofile << node->word << endl;  //print into file
  }else{
    cout << "-" << endl;  //non existance - print on screen 
    ofile << "-" << endl; //non existance - print to file
  }
}


//Function to delete the Node (for this program the implementation of this Node is not required--maybe later)
Node *LinkedList::delete_node(string word){

  int indx = word.length() - 5;

  Node *curr = head[indx];
  Node *prev = NULL;

  while(curr->next != NULL){

    if(curr->word.compare(word) == 0){
      break;
    }

    prev = curr;
    curr = curr->next;
  }

  //if the word found is in the head
  if(prev == NULL){
    head[indx] = head[indx]->next;
    return head[indx];
  }
  
  prev->next = curr->next;
  curr->next = NULL;

  return curr;
}

//function to delete and free memory of a node--used for deleting and freeing memory
void LinkedList::delete_and_free_node(string word){}

//function to delete the list
void LinkedList::delete_list(){

  for(int i = 0; i < SIZE; i++){
    Node *curr = head[i]; //pointer to the current node start from head
    Node *temp = NULL; //temperary pointer to point to the next node

    //loop over the list; first store pointer to next node, then delete the current node
    while(curr != NULL){
      temp = curr->next;
      delete(curr);
      curr = temp;
    }
  }

  head = NULL; 
}



//helper function to sort by frequence (and alphabetically)
void LinkedList::sort(Node *node, int indx){

  //special case: if the sorted at index is empty, or the node has higher frequency than sorted at index, inserts the node to the head of the list
  if(sorted[indx] == NULL || sorted[indx]->frequency < node->frequency){
    
    node->next = sorted[indx];
    sorted[indx] = node;
  
  }
  
  else{ //else : if the list is not empty and the frequency of the node is smaller than the frequency of head of the list at index
    Node *curr = sorted[indx], *prev = NULL;
    
    //traversing the list to insert the node by the order of frequency (descending)
    while(curr->next != NULL && curr->frequency > node->frequency){
      prev = curr;
      curr = curr->next;
    }

    //if the same frequency, traverse the list until found place alphabetically within the same frequency nodes
    while(curr->next != NULL && curr->frequency == node->frequency){

      if(node->word.compare(curr->word) < 0){ //if (alphabetically) word of the node comes before the word of the current node at index
        if(prev == NULL){ //if the prev is NULL = the node with same frequency comes before the head of list at index, inserts node at head of the list at index
          node->next = sorted[indx];
          sorted[indx] = node;
          return;
        }else{  //else the node is inserted after the previous node at the index
          prev->next = node;
          node->next = curr;
          return;
        }
      }
      else{ //else (alphabetically) word of the node comes after the word of the current node at index -> update the current node and previous node and check again
        prev = curr;
        curr = curr->next;
      }
    }

    //PROBLEM FOUND! : When there was only one node in the list, the next node was going to be added before that node regardless of frequency or lexographically,
    //                 same problem with just two nodes in the list, it was going to add the next node to the previous of second node without considering the 
    //                 frequency and lexographically. 

    //if The node is going to be added to the head of the linked list
    if(prev == NULL){
      if(node->frequency == curr->frequency){ //checks for the same frequency 
        if(curr->word.compare(node->word) > 0){ //checks alphabetically the curr word comes after the node word
            node->next = sorted[indx];  //places the word before the head of the list
            sorted[indx] = node;
            return;
        }
        else{
            node->next = sorted[indx]->next;  //places the word after the head of the list
            sorted[indx]->next = node;
            return;
        }
      }
      else if(node->frequency > curr->frequency){ //if the frequency of node is bigger than frequency of curr node
        node->next = sorted[indx];  //place node before the head of the list
        sorted[indx] = node;
        return;
      }
      else{
        node->next = sorted[indx]->next;  //else if frequency of node is less than frequeny of curr node
        sorted[indx]->next = node;  //place node after the head of the list
        return;
      }
    }
    else{ //else there is 2 nodes in the list and the third passed has less frequency than first but more than second
      if(node->frequency < curr->frequency){  //checks if the frequency of node is bigger than frequency of curr node
        node->next = curr->next;  //places node after the curr node
        curr->next = node;
      }
      else if(node->frequency > curr->frequency){ //else if frequency of the node is bigger than frequency of the curr node
        node->next = prev->next;  //places before the currency of the head
        prev->next = node;
      }
      else{ //else the frequency is equal 
        if(node->word.compare(curr->word) < 0){ //checks for alphabetically, if the word of node comes before the curr word
          node->next = prev->next;  //places the node after the previous node
          prev->next = node;
        }
        else{ //else the node comes after the curr word
          node->next = curr->next;  //places the word after the curr word
          curr->next = node;
        }
      }
    }

  }
}


//function to sort the words alphabetically with same frequency
void LinkedList::sort_words_by_frequency(){


  for(int i = 0; i < SIZE; i++){  //traversing through all lists of all indecies of the array of linked list
    
    Node *curr = head[i], *next = NULL; //updating the current node to the list at the next indices, and reassigning next to NULL
    
    //TEST: changed the process of incrementing until the next node is NULL
    while(curr != NULL){  //traversing through the list at indecies
      next = curr->next;  //storing the next node in the list
      sort(curr,i); //inserting the node into the sorted linked list at index of i
      curr = next;  //updating the current node to the next node
    }

  }

  head = sorted;  //updating the list to the new sorted list

}

//function to find a word based on length and rank
Node *LinkedList::most_frequent_by_length_and_rank(int length, int rank){

  int indx = length - 5;  //based on the length we are looking for, looks at the sorted list at correct index

  Node *curr = head[indx];  //curr pointer to traverse through the list at index of the desired word length
  int rcount = 0; //counter for rank

  while(curr != NULL){  //untill there is still nodes in the list
      
    if(rcount == rank){ //checks if the rank is the rank desired breaks the loop -- if not, updates the rank
      break;
    }

    rcount++;
    curr = curr->next;  //updates the current pointer to the next pointer
  }

  return curr;  //returns the node found with desired length and rank, if it is NULL then such word does not exist

}