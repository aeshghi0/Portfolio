#Ali Eshghi
#Ali Eshghi
#1112261
# A stock transaction program


#input
name=input("please enter the name of the company:  ")
number_of_shares=float(input("Please enter the number of shares:  "))
purchase_price=float(input("please enter the purchace price:  "))
commision_rate=float(input("please enter the commision rate:  "))
sell_price=float(input("please enter the price of sell:  "))

#calculation formulas
paid_amount=number_of_shares*purchase_price
commision=paid_amount*commision_rate/100
sell_purchase=number_of_shares*sell_price
commision_sell=sell_purchase*commision_rate/100
profit_loss=(sell_purchase-commision_sell)-(paid_amount+commision)


#output
print("the stock name is:  ",name)
print("the amount paid for the stock:  $",format(paid_amount,'.2f'),sep='')
print("Commision paid on purchase:  $",format(commision,'.2f'),sep='')
print("Amount the stock sold for:  $",format(sell_purchase,'.2f'),sep='')
print("commision paid on sale:  $",format(commision_sell,'.2f'),sep='')
print("profit(or loss if negative:  $",format(profit_loss,'.2f'),sep='')


##===== RESTART: /Users/alieshghi/Desktop/homework1/set3/stock exchange.py =====
##please enter the name of the company:  Sikim co.
##Please enter the number of shares:  20
##please enter the purchace price:  10
##please enter the commision rate:  8
##please enter the price of sell:  11
##the stock name is:   Sikim co.
##the amount paid for the stock:  $200.00
##Commision paid on purchase:  $16.00
##Amount the stock sold for:  $220.00
##commision paid on sale:  $17.60
##profit(or loss if negative:  $-13.60
##>>> 
