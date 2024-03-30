#include "Actor_movie_header.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <vector>
#include <bool>
#include <fstream>

using namespace std;

/***********************
* movie_node functions
************************/
movie_node::movie_node(string name, int weight){
  name = name;
  weight = weight;
}

/***********************
* actor_node functions
************************/
actor_node::actor_node(string name){
  name = name;
  years = -1;
  visited = false;
  previous = {NULL, NULL}
}

bool actor_node::operator<(const actor_node& other){
  if(this->years > other.years){
    return true;
  }
  else if(this->years < other.years){
    return false;
  }

  return (this->name < other.name);  // to preioratize alphabetical order
}

/***********************
* actor_graph functions
************************/
actor_graph::actor_graph(void){}

actor_graph_load_file(ifstram &in_file, bool edged){
  bool header = false;

  while(in_file){ //read until the end of the file is reached
    
  }
}