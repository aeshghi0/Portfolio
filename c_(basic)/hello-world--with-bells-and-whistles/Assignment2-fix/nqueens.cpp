
#include "list.h"
#include "node.h"
#include <stack>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

//int cb_size; //global variable to be used as the size of the chess board;

class Pair{
  public:
    int col;
    int row;
};

//Function that removes all the elements of a stack
void clear_stack(stack<class Pair> &stack){
  while(!stack.empty()){
    stack.pop();
  }
}

//Function that initializes a 2d vector for a size passed onto it
vector<vector<int>> vector_initializer(int size){
  vector<vector<int>> vec(
    size,
    vector<int>(size));
  
  return vec;
}

//Utility function to check if the square with colomn and row is safe or not
bool is_safe(vector<vector<int>> &board, int col, int row, int cb_size){

  if(board[row][col] == 1){ //checking if the square itself has a queen placed in it
    return false;
  }

  for(int i = 0; i < cb_size; i++){ //check if it is safe in the colomn
    if(board[i][col] == 1){
      return false;
    }
  }

  for(int i = 0; i < cb_size; i++){ //checking if it is safe in the row
    if(board[row][i] == 1){
      return false;
    }
  }

  for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){  //checking diagonal (to left up) if it's safe
    if(board[i][j] == 1){
      return false;
    }
  }

  for(int i = row, j = col; i >= 0 && j < cb_size; i--, j++){  //checking diagonal (to right up) if it's safe
    if(board[i][j] == 1){
      return false;
    }
  }

  for(int i = row, j = col; i < cb_size && j < cb_size; i++,j++){  //checking diagonal (to right down) if it's safe
    if(board[i][j] == 1){
      return false;
    }
  }

  for(int i = row, j = col; i < cb_size && j >= 0; i++, j--){  //checking diagonal (to left down) if it's safe
    if(board[i][j] == 1){
      return false;
    }
  } 
  //Test
  //cout << "Square is safe" << endl;
  return true;
}

//Function to Place the remaining of the queens in the chess board of size cb_size based on the placement of the queens on the board
//Input, cb_size: chess board size; chess_stack: stack of initial queens in the chess board; init_queens: number of initial queens in the stack
//Output, final_output: list of all the colomns and rows that rest of the queens are gonna be placed
List  place_queens(int cb_size, stack<class Pair> &chess_stack, int init_queens){

  int rem_queens = cb_size - init_queens; //The remaining queens to be placed on the board
  List final_output;
  //List checked_sqrs;
  List no_output;
  Pair stack_top, init, first;

  vector<vector<int>> init_board = vector_initializer(cb_size);

  while(!chess_stack.empty()){  //traversing the stack to place the initial queens in the board
      stack_top = chess_stack.top();
      chess_stack.pop();
      if(is_safe(init_board, stack_top.col, stack_top.row, cb_size)){
          init_board[stack_top.row][stack_top.col] = 1;  //setting up the position of initial queen from the stack to false
      }
      else{
          return no_output;
      }
  }

  init.col = 0; //starting from first col
  init.row = 0; //and first row (the first square in the board)
  first.col = 0;
  first.row = 0;

  chess_stack.push(init); //pushing the initial item into the stack

  vector<vector<int>> board(
          cb_size,
          vector<int>(cb_size));

  for(int i = 0; i < cb_size; i++){ //copying - to reserve the initial board
      for(int j = 0; j < cb_size; j++){
          board[i][j] = init_board[i][j];
      }
  }

  RECUR:
  while(!chess_stack.empty()){
    stack_top = chess_stack.top();
    chess_stack.pop();

    Pair to_push;

    //Test
    //cout << "Checking square: " << stack_top.col+1 << " " << stack_top.row+1 << endl;

    if(final_output.find(stack_top.col, stack_top.row) == NULL){
      if(is_safe(board, stack_top.col, stack_top.row, cb_size)){
        //Test
        //cout << "Square is safe: " << stack_top.col+1 << " " << stack_top.row+1 << endl;
        final_output.insert(stack_top.col, stack_top.row);
        board[stack_top.row][stack_top.col] = 1;

        if(final_output.list_length() == rem_queens){
          return final_output;
        }

        to_push.col = stack_top.col;
        to_push.row = stack_top.row;

        chess_stack.push(to_push);
        if(stack_top.col + 1 < cb_size){
          
          to_push.row = 0;
          to_push.col = stack_top.col + 1;
          chess_stack.push(to_push);
        }
        continue;
      }
    }else{  //backtracking to the previous placed queen and undo the placing
      board[stack_top.row][stack_top.col] = 0;
      final_output.delete_node(stack_top.col, stack_top.row);
    }
    //if(checked_sqrs.find(stack_top.col, stack_top.row) == NULL){
    //checked_sqrs.insert(stack_top.col, stack_top.row);
    //Pair to_push;
    if(stack_top.row + 1 < cb_size){  //recursive to the next row
      to_push.col = stack_top.col;
      to_push.row =  stack_top.row + 1;
      chess_stack.push(to_push);
    }
    else if(stack_top.col + 1 < cb_size){ //or the next colomn
      to_push.row = 0;
      to_push.col = stack_top.col + 1;
      chess_stack.push(to_push);
    }
    //}
  }

  //check if the number of queens places is equal to the number of queens remained
  if(rem_queens != final_output.list_length()){
    final_output.clear_list();  //clearing the solution list to store new list
    //checked_sqrs.clear_list(); //clearing the list of checked squares
    for(int i = 0; i < cb_size; i++){ //restarting the board
      for(int j = 0; j < cb_size; j++){
        board[i][j] = init_board[i][j];
      }
    }
    if(init.row + 1 < cb_size){ //restart from next row
      //Test
      //cout << "starting from next row" << endl;
      chess_stack.push(first);
      init.row = init.row + 1;
      chess_stack.push(init);
      goto RECUR;
    }
    else{
      if(init.col + 1 < cb_size ){ //restarting from the next square on the same row
        //Test
        //cout << "starting from next square" << endl;
        chess_stack.push(first);
        init.col = init.col + 1;
        init.row = 0;
        chess_stack.push(init);
        goto RECUR;
      }
    }
  }

  return no_output;


}



int main(int argc, char **argv){
  
  if (argc < 3) // must provide two arguments as input
  {
    throw std::invalid_argument("Usage: ./nqueens <INPUT FILE> <OUTPUT FILE>"); // throw error
  }

  stack<class Pair> chess_stack;  //to be used for solving the puzzle
  stack<class Pair> init_queens_stack;  //stack to store the position of initial queens, to be added to the solution

  ifstream input_file; //file pointer to open the input file
  ofstream output_file;  //file pointer to open the output file

  input_file.open(argv[1]);  //openning the input file to read the input
  output_file.open(argv[2]); //openning the output file to print the output

  string chess_set_up;  //used to read the line for the chess board set up
  char *csu, *size, *dummy, *s_col, *s_row; //for using with strtok, strtol
  int cb_size;  //chessboard size;
  int init_queens;  //number of initial queens in the list
  //int all_queens; //number of all the queens to be set on the board(this is as big as the chess board size - here for simplification)
  int r_col;  //used to read variable of the colomn from the input file
  int r_row;  //used to read variable of the row from the input file

  while(getline(input_file,chess_set_up)){

    if(chess_set_up.length() == 0){ //in case there was an empty line in input file
      continue;
    }

    init_queens = 0;
    
    csu = strdup(chess_set_up.c_str()); //coppying into c-style string
    size = strtok(csu," \t");
    if(size != NULL){
      cb_size = strtol(size,&dummy,10); //sets up the size of the chess board
      //all_queens = cb_size; //sets up all the queens desired to be placed on chess board
    }

    while((s_col = strtok(NULL," \t"))){  //until it reaches the end of the line (gets the colomn as the first token to make sure there is a colomn)
      s_row = strtok(NULL, " \t"); //gets the next token as the row

      if(s_col != NULL && s_row != NULL){ //if there are both colomn and row to convert to int
        r_col = strtol(s_col,&dummy,10);  //convert colomn to int
        r_row = strtol(s_row,&dummy,10);  //convert row to int
        
        Pair to_push; //stack object to push to the stack

        to_push.col = r_col - 1;  //setting up the object colomn (-1 because of indexing)
        to_push.row = r_row - 1;  //setting up the object row (-1 because of indexing)
        chess_stack.push(to_push);  //pushing the item into the stack
        init_queens_stack.push(to_push);
        init_queens++;  //increase the number of initial queens in the
        
      }
    }

    List output = place_queens(cb_size, chess_stack, init_queens);  //using the stack based function to place the queens
    while(!init_queens_stack.empty()){
      Pair stack_top = init_queens_stack.top();
      init_queens_stack.pop();
      if(!output.is_empty()){
        output.insert(stack_top.col, stack_top.row);
      }
    }
    output.sort();  //sorting the places of queens based on ascending of the colomns
    output.print(output_file);  //printing the list of places of the queens
    clear_stack(chess_stack); //clearing the stack of any entries to make it ready for the next set up
    clear_stack(init_queens_stack); //clearing stack of initial queens stack to make it ready for the next input
    output.delete_list();  //freeing the memory of the list
  }

  return 0;
}