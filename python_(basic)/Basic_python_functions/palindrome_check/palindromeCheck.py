#Ali Eshghi 
#1125317
#HW3_PS2

def isPalindrome(chck_strt:str):
    num=len(chck_strt)
    for x in range (0, num//2):
        if chck_strt[x] != chck_strt[num-x-1]:
            return False
        else:
            return True
    #THIS FUNCTION CHECKS IF THE STRING ENTERD IS PALINDROME OR NOT !

def main():
    chck_strt = input("Enter a String to See IF it is Palindrome: ")
    chckd = isPalindrome(chck_strt)

    #ASK USER FOR STING

    while chck_strt != "-1":
    #WHILE LOOP TO QUITE THE PROGRAM
        if chckd == True :
            print(chck_strt, "is Palindrome.")
        elif chckd == False :
            print(chck_strt, "is not a Palindrome.")
        chck_strt = input("Enter a String to See IF it is Palindrome (-1 to quite): ")
        chckd = isPalindrome(chck_strt)

if __name__=="__main__":
    main()

##>>> 
##====== RESTART: /Users/siavash/Desktop/HW3/PS2_Valipour_Amirarsalan.py ======
##Enter a String to See IF it is Palindrome: NOON
##NOON is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): noon
##noon is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): print
##print is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): racecar
##racecar is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): speed
##speed is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): -1
##>>> 

##>>> 
##====== RESTART: /Users/siavash/Desktop/HW3/PS2_Valipour_Amirarsalan.py ======
##Enter a String to See IF it is Palindrome: KOON
##KOON is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): ZOOD
##ZOOD is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): MIKH
##MIKH is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): NOON
##NOON is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): MOON
##MOON is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): -1
##>>> 

##>>> 
##====== RESTART: /Users/siavash/Desktop/HW3/PS2_Valipour_Amirarsalan.py ======
##Enter a String to See IF it is Palindrome: abc
##abc is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): aaa
##aaa is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): mmm
##mmm is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): ZAZAZ
##ZAZAZ is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): ZZZZA
##ZZZZA is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): -1
##>>> 

##>>> 
##====== RESTART: /Users/siavash/Desktop/HW3/PS2_Valipour_Amirarsalan.py ======
##Enter a String to See IF it is Palindrome: mkmkm
##mkmkm is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): aaaaa
##aaaaa is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): aaav
##aaav is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): aaa
##aaa is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): a
##Enter a String to See IF it is Palindrome (-1 to quite): -1
##>>>


##>>> 
##====== RESTART: /Users/siavash/Desktop/HW3/PS2_Valipour_Amirarsalan.py ======
##Enter a String to See IF it is Palindrome: BBB
##BBB is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): AAA
##AAA is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): AAa
##AAa is not a Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): aAa
##aAa is Palindrome.
##Enter a String to See IF it is Palindrome (-1 to quite): -1
##>>> 
