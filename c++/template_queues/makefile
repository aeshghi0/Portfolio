CC = g++ # macros
FLAGS = -std=c++14 -Wall
OBJS = Queue.o

all: hw12

hw07: hw12.cpp Queue.o # step2 build program
	$(CC) $(FLAGS) hw12.cpp -o hw12 $(OBJS)

Queue.o: # step1 build deck object file
	$(CC) $(FLAGS) -c hw12.cpp -o Queue.o

clean:
	rm *.o hw12.scr hw12.tar

tar:
	tar cf hw12.tar hw12.scr makefile hw12.cpp 