CC = g++ # macros
FLAGS = -std=c++14 -Wall
OBJS = LinkedList.o Node.o DNode.o DLinkedList.o

all: hw14

hw13: hw14.cpp LinkedList.o Node.o DNode.o DLinkedList.o # step2 build program
	$(CC) $(FLAGS) hw14.cpp -o hw14 $(OBJS)

LinkedList.o: LinkedList.h # step1 build deck object file
	$(CC) $(FLAGS) -c hw14.cpp -o LinkedList.o

Node.o: node.h # step1 build deck object file
	$(CC) $(FLAGS) -c hw14.cpp -o Node.o

DNode.o: Dnode.h# step1 build deck object file
	$(CC) $(FLAGS) -c hw14.cpp -o DNode.o

DLinkedList.o: DLinkedList.h
	$(CC) $(FLAGS) -c hw14.cpp -o DLinkedList.o

clean:
	rm *.o hw14.scr hw14.tar

tar:
	tar cf hw14.tar hw14.scr makefile hw14.cpp 