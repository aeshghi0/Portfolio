#Lab3 set3

def get_data()->(float,float):
    lngth=float(input("Enter the length of trianagle: "))
    hght=float(input("Enter the prependicular height of trianagle: "))
    return lngth,hght

def trig_S(lngth:float,hght:float)->float:
    S=(hght*lngth)/2
    return S

def display_data(lngth:float,hght:float,S:float) -> None:
    print("The length of trianagle is ",lngth)
    print("The prependicular height of trianagle: ",hght)
    print("The area of trianagle: ",S)

def main():
    lngth,hght=get_data()
    S=trig_S(lngth,hght)
    display_data(lngth,hght,S)

if __name__=="__main__":
    main()



##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 3.py =======
##Enter the length of trianagle: 3
##Enter the prependicular height of trianagle: 5
##The length of trianagle is  3.0
##The prependicular height of trianagle:  5.0
##The area of trianagle:  7.5
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 3.py =======
##Enter the length of trianagle: 5
##Enter the prependicular height of trianagle: 6
##The length of trianagle is  5.0
##The prependicular height of trianagle:  6.0
##The area of trianagle:  15.0
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 3.py =======
##Enter the length of trianagle: 4
##Enter the prependicular height of trianagle: 9
##The length of trianagle is  4.0
##The prependicular height of trianagle:  9.0
##The area of trianagle:  18.0
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 3.py =======
##Enter the length of trianagle: 1
##Enter the prependicular height of trianagle: 10
##The length of trianagle is  1.0
##The prependicular height of trianagle:  10.0
##The area of trianagle:  5.0
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 3.py =======
##Enter the length of trianagle: 6
##Enter the prependicular height of trianagle: 9
##The length of trianagle is  6.0
##The prependicular height of trianagle:  9.0
##The area of trianagle:  27.0
##>>> 
