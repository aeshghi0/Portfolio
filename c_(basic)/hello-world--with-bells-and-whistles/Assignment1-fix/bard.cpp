// Filename: bard.cpp
//
// This is the main function for the LinkedList class.
// 
// After running make, the usage is:
//     ./bard <INPUT_FILE> <OUTPUT_FILE>
// 
// The input file contains a list of length (l) and rank (k). after openning the shakespeare word list file, and loading it
// into an array of linked list. the program sorts the lists at each index of the array based on frequency and lexographically
// using the INPUT_FILE arguments. (Open while running usage command), the program finds the K most repeated word of length l.
// the program keeps running until the end of the input file is read.
// 
// Only the print operations generate output, which is the list printed in order in a single line.
// The output file contains the output of all print commands.
// 
// 
// 
// Ali Eshghi Oct 10, 2022
#include "bard_header.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, char **argv){

  /*********************************************
    Error message
    source: Linkedlist section test codio box
    Author: C. Seshadhri, Jan 2020
  **********************************************/
  if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./bard <INPUT FILE> <OUTPUT FILE>"); // throw error
    }

  //creating an empty list to add the words to it
  LinkedList word_list;

  //openning the shakespeare work to add to create a linkedlist
  ifstream sfile;
  sfile.open("shakespeare-cleaned5.txt");

  //string object to store the word read from the file
  string r_word;

  //if the file is open (seccessfully), loops over the lines(words) and adds them to the list until the end of the file
  if(sfile.is_open()){
    while(getline(sfile,r_word)){
      //TEST
      word_list.insert(r_word); //insert the read word in the list
    }
  }
  else{
    cout << "Error: could not open the word file" << endl;
    return 1;
  }

  //function to sort words alphabetically to used for ranks (needs to implement)
  word_list.sort_words_by_frequency();

  //Open the testinput file to execute the program using the length and rank from the input file
  ifstream ifile;
  ifile.open(argv[1]);

  //open the output file to write the result to them
  ofstream ofile;
  ofile.open(argv[2]);

  string command;
  char *com, *len_s, *rank_s, *dummy;
  int length, rank;

  while(getline(ifile,command)){

    if(command.length() == 0){
      continue;
    }

    com = strdup(command.c_str());  //converting command into c string

    len_s = strtok(com, " \t");
    length = strtol(len_s, &dummy, 10);

    rank_s = strtok(NULL," \t");
    rank = strtol(rank_s, &dummy, 10);

    Node *found = word_list.most_frequent_by_length_and_rank(length, rank);

    word_list.print_word(found,ofile);
  }



  sfile.close();
  ifile.close();
  ofile.close();

  return 0;
}