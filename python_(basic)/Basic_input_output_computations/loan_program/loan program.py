#Ali Eshghi
#1112261
#a program to compute the loan amount, it’s monthly payment and total payment.


#input
number_of_years=int(input("please enter the number of years: "))
annual_interest_rate=float(input("please enter the annual interest rate: "))
loan_amount=float(input("please enter the loan amount: "))

#calculation formulas
monthly_interest_rate=float(annual_interest_rate/1200)
monthly_payment=int(loan_amount*monthly_interest_rate/(1-1/(1+monthly_interest_rate)**(number_of_years*12)))
total_payment=int(monthly_payment*number_of_years*12)

#output
print("the monthly payment is $",format(monthly_payment,',.2f'),sep='')
print("the total payment is $",format(total_payment,',.2f'),sep='')


##====== RESTART: /Users/alieshghi/Desktop/homework1/set2/loan program.py ======
##please enter the number of years: 3
##please enter the annual interest rate: 8
##please enter the loan amount: 3000
##the monthly payment is $94.00
##the total payment is $3,384.00
##>>> 
