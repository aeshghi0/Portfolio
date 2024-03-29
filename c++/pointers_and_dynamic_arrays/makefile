CC = g++ # macros
FLAGS = -std=c++14 -Wall -g
OBJS = inventoryManagement.o

all: hw07

hw07: hw07.cpp inventoryManagement.o # step2 build program
	$(CC) $(FLAGS) hw07.cpp -o hw07 $(OBJS)

inventoryManagement.o: inventoryManagement.cpp inventoryManagement.h # step1 build deck object file
	$(CC) $(FLAGS) -c inventoryManagement.cpp -o inventoryManagement.o

clean:
	rm *.o hw07.scr hw07.tar

tar:
	tar cf hw07.tar hw07.scr makefile hw07.cpp inventoryManagement.cpp inventoryManagement.h