#Ali Eshghi
#input

quantity=float(input("enter the quantity sold : "))
value=float(input("enter the value of item : "))
discount=float(input("enter the discount percentage : "))
tax=float(input("enter the tax : "))

#calculation formulas
amount=quantity*value
discount_amount=amount*discount/100
subtotal=amount-discount_amount
tax_amount=subtotal*tax/100
total_amount=subtotal+tax_amount

#output
print("quantity sold:  ",quantity)
print("price per item:  $",format(value,'.2f'),sep='')
print("amount:  $",format(amount,'.2f'),sep='')
print("discount:  $",format(discount_amount,'.2f'),sep='')
print("discounted total:  $",format(subtotal,'.2f'),sep='')
print("tax:  $",format(tax_amount,'.2f'),sep='')
print("total amount to be paid :  $",format(total_amount,'.2f'),sep='')


##====== RESTART: /Users/alieshghi/Desktop/homework1/set 4/bill amount.py ======
##enter the quantity sold : 20
##enter the value of item : 30
##enter the discount percentage : 10
##enter the tax : 7.78
##quantity sold:   20.0
##price per item:  $30.00
##amount:  $600.00
##discount:  $60.00
##discounted total:  $540.00
##tax:  $42.01
##total amount to be paid :  $582.01
##>>> 
