#Lab3 set6


def string_total(number_string:str)->int:
    total = 0
    for ch in number_string:
        total = total + int(ch)
    return total
def main():
    number_string=input("enter a sequence of numbers without space: ")
    total=string_total(number_string)
    print("the total of digits in the string you entered is ",total)

if __name__=='__main__':
    main()

##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/the sum of sequence.py =======
##enter a sequence of numbers without space: 456
##the total of digits in the string you entered is  15
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/the sum of sequence.py =======
##enter a sequence of numbers without space: 1234
##the total of digits in the string you entered is  10
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/the sum of sequence.py =======
##enter a sequence of numbers without space: 896
##the total of digits in the string you entered is  23
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/the sum of sequence.py =======
##enter a sequence of numbers without space: 7654
##the total of digits in the string you entered is  22
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/the sum of sequence.py =======
##enter a sequence of numbers without space: 6789
##the total of digits in the string you entered is  30
##>>> 







