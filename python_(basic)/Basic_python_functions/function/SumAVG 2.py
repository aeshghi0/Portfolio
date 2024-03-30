def load ( ) -> (str,int,int,int):

    name = input("Enter a name : ")

    num1 = int(input("Enter first number : "))

    num2 = int(input("Enter second number : "))

    num3 = int (input ("Enter third number : "))

    return name, num1, num2, num3

 

def calc (num1:int, num2:int, num3:int)->(int,float):

    sum = num1 + num2 + num3

    avg = sum / 3

    return sum, avg

 

def output (name:str, num1:int, num2:int, num3:int, sum:int, avg:float)-> None:

    print("your name is : ", name)

    print("The 3 numbers are : ", num1, num2, num3)

    print("The sum is : ", sum)

    print("The average is : ",avg)

 

def main ():

    name, num1, num2, num3=load ()

    sum,avg= calc(num1,num2,num3)

    output (name, num1, num2, num3, sum, avg)

if __name__ =="__main__":
    main()


