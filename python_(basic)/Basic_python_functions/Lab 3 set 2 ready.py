#Lab3 set2

def show_intrest(rate=0.01,principal=10000.00,periods=10):
    intrest= principal*rate*periods
    print("The simple intrest will be $",format(intrest,'.2f'))
    
def main():
    show_intrest()
    
if __name__=="__main__":
    main()


##>>> 
##======= RESTART: /Users/alieshghi/Desktop/lab 3/Lab 3 program set 2.py =======
##The simple intrest will be $ 1000.00
##>>> 
