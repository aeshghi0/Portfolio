#Lab3 set5

def get_in()->str:
    name=input("Enter your full name(including middle name): ")
    init=name.split(" ")
    frst=init[0]
    mddl=init[1]
    lst=init[2]
    fn=frst[:1]
    mn=mddl[:1]
    ln=lst[:1]
    initial=fn+'.'+mn+'.'+ln
    return initial

def main():
    initial=get_in()
    print(initial)

if __name__=="__main__":
    main()

##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 5.py =======
##Enter your full name(including middle name): Ali Sikim Eshghi
##A.S.E
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 5.py =======
##Enter your full name(including middle name): Amir Joghd Valipour
##A.J.V
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 5.py =======
##Enter your full name(including middle name): Siavash Chaghalian Baghalianzade
##S.C.B
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 5.py =======
##Enter your full name(including middle name): Vala Heshmat Saadat
##V.H.S
##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 5.py =======
##Enter your full name(including middle name): George W Bush
##G.W.B
##>>> 
