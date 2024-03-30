#Ali Eshghi
#1112261
#Guess my number game

import random

#create a random number
my_num=random.randint(1,100)
tries=1
#user input a guess
guess=int(input("take a guess"))

while guess!=my_num:
    if guess<my_num:
        print("Higher...")
    else:
        print("Lower...")
    tries=tries+1
    guess=int(input("take a guess..."))

print("you guessed it! the number is",my_num)
print("you took",tries,"tries!")
