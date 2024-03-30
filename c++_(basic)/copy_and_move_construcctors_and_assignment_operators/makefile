CC = g++ # macros
FLAGS = -std=c++14 -Wall
OBJS = inventoryManagement.o

all: hw10

hw07: hw10.cpp vector.o # step2 build program
	$(CC) $(FLAGS) hw10.cpp -o hw10 $(OBJS)

vector.o: # step1 build deck object file
	$(CC) $(FLAGS) -c hw10.cpp -o vector.o

clean:
	rm *.o hw10.scr hw10.tar

tar:
	tar cf hw10.tar hw10.scr makefile hw10.cpp 