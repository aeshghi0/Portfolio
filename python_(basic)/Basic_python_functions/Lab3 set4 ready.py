#Lab3 set4

def get_sales()->float:
    sales = float(input("Enter the monthly sales: "))
    return sales

def get_advanced_pay()->float:
    advanced_pay = float(input("Enter the amount of advanced pay,\n or enter 0 if no advanced pay was given: "))
    return advanced_pay

def determine_comm_rate(sales)->float:
    comm_rate = 0.12
    return comm_rate

def main():
    sales = get_sales()
    advanced_pay = get_advanced_pay()
    comm_rate = determine_comm_rate(sales)
    pay = (sales*comm_rate)-advanced_pay
    print("Advanced pay: $",format(advanced_pay,',.2f'),sep='')
    print("The pay is: $",format(pay,',.2f'),sep='')

    if pay<0:
        print("The sales person must reimburse")
        print("The company")




if __name__=="__main__":
    main()


##
##>>> 
##========= RESTART: /Users/alieshghi/Desktop/lab 3/Lab3 set4 ready.py =========
##Enter the monthly sales: 1000.00
##Enter the amount of advanced pay,
## or enter 0 if no advanced pay was given: 0
##Advanced pay: $0.00
##The pay is: $120.00
##>>> 
##========= RESTART: /Users/alieshghi/Desktop/lab 3/Lab3 set4 ready.py =========
##Enter the monthly sales: 10000
##Enter the amount of advanced pay,
## or enter 0 if no advanced pay was given: 340
##Advanced pay: $340.00
##The pay is: $860.00
##>>> 
##========= RESTART: /Users/alieshghi/Desktop/lab 3/Lab3 set4 ready.py =========
##Enter the monthly sales: 500
##Enter the amount of advanced pay,
## or enter 0 if no advanced pay was given: 450
##Advanced pay: $450.00
##The pay is: $-390.00
##the sales person must reimburse
##the company
##>>> 
##========= RESTART: /Users/alieshghi/Desktop/lab 3/Lab3 set4 ready.py =========
##Enter the monthly sales: 2000
##Enter the amount of advanced pay,
## or enter 0 if no advanced pay was given: 870
##Advanced pay: $870.00
##The pay is: $-630.00
##the sales person must reimburse
##the company
##>>> 
##========= RESTART: /Users/alieshghi/Desktop/lab 3/Lab3 set4 ready.py =========
##Enter the monthly sales: 690
##Enter the amount of advanced pay,
## or enter 0 if no advanced pay was given: 0
##Advanced pay: $0.00
##The pay is: $82.80
##>>> 
