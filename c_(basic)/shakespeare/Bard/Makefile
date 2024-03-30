CXX = g++
CXXFLAGS = -Wall

OBJECTS = bard.o bard_funcs.o

bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o bard bard_funcs.o bard.o

bard_funcs.o: bard_funcs.cpp bard_header.h
	$(CXX) -g $(CXXFLAGS) -c bard_funcs.cpp
	
bard.o: bard_funcs.cpp bard_header.h bard.cpp
	$(CXX) -g $(CXXFLAGS) -c bard.cpp

clean: 
	rm -f *.o
	rm bard