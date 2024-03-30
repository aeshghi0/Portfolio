#ifndef ACTOR_MOVIE_HEADER_H
#define ACTOR_MOVIE_HEADER_H

#include <iostream>
#include <fstream>
#include <bool.h>
#include <string>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <unordered_map>

using namespace std;

#define MAX_GRAPH_SIZE 400000

class Graph{
  private:
    int vertices;
    int **matrix;
  public:
    Graph_create(); //defult constructor, not to be used normally
    Graph_create(int vertices); //constructor with the number of vertices
};

typedef struct{
  int steps;
  int vertices_visited[MAX_GRAPH_SIZE];
}Path;

typedef struct LLpath{
  Path val;
  LLpath *next;
}LLpath;




/**************************
class move_node{
  private:
    string name;
    movie_node *next;
  public:
    vector<string> actors;  //list of the actors

    movie_node(string name);  //constructor
};

class actor_node{
  public:
    string name;
    bool visited;
    vector<movie_node<actor_node>*> movies;
    pair<movie_node<actor_node>*,actor_node*> previous;
    
    actor_node(string name);  //constructor
    bool operator<(const actor_node& other);
    

};


class actor_graph{
  public:
    unordered_map<string,movie_node<actor_node> movie_map;  //unordered map of movie names with movie node pointers
    unordered_map<string,actor_node<movie_node> actor_map;  //unordered map of actor names with actor node pointers

    actor_graph(void);  //constructor
    ~actor_grapg();     //destructor

    bool load_file(ifstream &);
};
***************************/
#endif