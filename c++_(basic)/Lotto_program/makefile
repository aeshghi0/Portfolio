CC = g++ # macros
FLAGS = -std=c++14 -Wall -g
#OBJS = hw05.o

all: hw05

hw05: hw05.cpp # step2 build program
	$(CC) $(FLAGS) lotto.cpp hw05.cpp -o hw05

#hw05.o: hw05.cpp hw05.h # step1 build deck object file
#	$(CC) $(FLAGS) -c cardDeckClass.cpp -o cardDeckClass.o

clean:
	rm *.o hw05.scr hw05.tar

tar:
	tar cf hw05.tar hw05.scr makefile hw05.cpp hw05.h lotto.cpp hw05QA.txt