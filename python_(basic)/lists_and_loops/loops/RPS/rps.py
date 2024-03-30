import random

#input
count=0
while count<2 and count>-2:
    pcchoice=random.randint(1,3)
    user=int(input(" 1 - scessiors \n 2 - rock \n 3 - paper \n Choose: "))
    if pcchoice==1:
        if user==1 :
            print("it's a draw")
        elif user==2:
            print("you won")
            count=count+1
        else:
            print("you lose")
            count=count-1
    elif pcchoice==2:
        if user==1 :
            print("you lose")
            count=count-1
        elif user==2:
            print("it's a draw")
        else:
            print("you won")
            count=count+1
    elif pcchoice==3:
        if user==1 :
            print("you won")
            count=count+1
        elif user==2:
            print("you lose")
            count=count-1
        else:
            print("it's a draw")
    print("your score is : ",count,"\n")
if count>=2:
    print(" you have won more than two times more than the computer")
elif count<=-2:
    print("you lose sucker, the computer have won more")
