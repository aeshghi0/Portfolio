#Ali Eshghi
#1112261
#write a program to calculate sales

#input
per=float(input("Inter the amount of perchase amount:"))
sttax=per*0.04
cttax=per*0.02
tltax=sttax+cttax
ts=per+tltax

#output
print("the perchace is $",format(per,'.2f'),sep='')
print("the state tax is $",format(sttax,'.2f'),sep='')
print("the country tax is $",format(cttax,'.2f'),sep='')
print("the total tax is $",format(tltax,'.2f'),sep='')
print("the total sale is $",format(ts,'.2f'),sep='')

##================== RESTART: C:/Users/aeshghi0/Desktop/aa.py ==================
##Inter the amount of perchase amount:100
##the perchace is $100.00
##the state tax is $4.00
##the country tax is $2.00
##the total tax is $6.00
##the total sale is $106.00
##>>> 
