CC = g++ # macros
FLAGS = -std=c++14 -Wall
OBJS = inventoryManagement.o

all: hw11

hw07: hw11.cpp Base.o D1.0 D2.0 D3.0 # step2 build program
	$(CC) $(FLAGS) hw11.cpp -o hw11 $(OBJS)

Base.o: # step1 build deck object file
	$(CC) $(FLAGS) -c hw11.cpp -o vector.o

D1.o: # step1 build deck object file
	$(CC) $(FLAGS) -c hw11.cpp -o vector.o

D2.o: # step1 build deck object file
	$(CC) $(FLAGS) -c hw11.cpp -o vector.o

D3.o: # step1 build deck object file
	$(CC) $(FLAGS) -c hw11.cpp -o vector.o


clean:
	rm *.o hw11.scr hw11.tar

tar:
	tar cf hw11.tar hw11.scr makefile hw11.cpp 