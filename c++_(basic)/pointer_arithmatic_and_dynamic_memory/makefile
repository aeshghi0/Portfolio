CC = g++ # macros
FLAGS = -std=c++14 -Wall -g
#OBJS = inventoryManagement.o

all: hw08

hw07: hw08.cpp  # step2 build program
	$(CC) $(FLAGS) hw08.cpp -o hw08 $(OBJS)

#inventoryManagement.o: inventoryManagement.cpp inventoryManagement.h # step1 build deck #object file
#	$(CC) $(FLAGS) -c inventoryManagement.cpp -o inventoryManagement.o

clean:
	rm *.o hw08.scr hw08.tar

tar:
	tar cf hw08.tar hw08.scr makefile hw08.cpp