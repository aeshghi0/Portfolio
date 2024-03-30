Program Name : Shakespeare

for creating executables run:
      make

 After running make, the usage is:
     ./bard <INPUT_FILE> <OUTPUT_FILE>

 The program's purpose is to find the k most element of length l in Shakespeare using Linked lists.
 
 The input file must contains a list of length (l)  following with a space and rank (k).

 The shakespeare-cleaned5.txt contains all the words more than 5 characters. each index of the array represents the 
 list of the words with the same number of characters as that index. Therefore for index it is calculated as:
 index = length_of_the_word - 5;

 NOTE: Because of combination of words and mix of words, the size of the array has been (approximately) allocated twice
       as big as the longest word in Shakespeare itself (again: indexes represents the number of characters in a word)
 
 after opening the Shakespeare word list file, and loading it into an array of linked list. the program sorts the lists 
 at each index of the array based on frequency(1) and lexicographically(2).
 using the INPUT_FILE arguments in a loop until the end of the file. (Open while running usage command),
 the program finds the K most repeated word of length l.
 the program keeps running until the end of the input file is read.
 
 Only the print operations generate output, which is the list printed in order in a single line.
 The output file contains the output of all the k most repeated word of length l, as well as printing on the screen
 for the user to see
 

Ali Eshghi Oct 10, 2022