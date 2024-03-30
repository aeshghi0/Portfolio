CXX = g++
CXXFLAGS = -Wall

OBJECTS = node.o list.o nqueens.o

nqueens: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o nqueens node.o list.o nqueens.o

nqueens.o: list.h node.h list.cpp node.cpp nqueens.cpp
	$(CXX) -g $(CXXFLAGS) -c nqueens.cpp

list.o: list.h list.cpp node.h node.cpp
	$(CXX) -g $(CXXFLAGS) -c list.cpp

node.o: node.h node.cpp
	$(CXX) -g $(CXXFLAGS) -c node.cpp

clean: 
	rm -f *.o nqueens

