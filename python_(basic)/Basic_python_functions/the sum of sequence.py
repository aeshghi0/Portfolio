
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









