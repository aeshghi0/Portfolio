#Ali Eshghi
#1112261
#this program will tell you the recipe of the number of cookies you want to cook

#input
cookies_amnt=int(input("please enter the amount of cookies you want to cook: "))

#calculation formulas
sugar_amnt=float(cookies_amnt*1.5)
butter_amnt=int(cookies_amnt*1)
flour_amnt=float(cookies_amnt*2.75)

#output
print("for",cookies_amnt, "cookies you will need:")
print("the total cups of sugar you need is",format(sugar_amnt,'.1f'))
print("the total cups of butter you need is",format(butter_amnt,'.1f'))
print("the total cups of flour you need is",format(flour_amnt,'.2f'))

##===== RESTART: /Users/alieshghi/Desktop/homework1/set1/cookie recipe.py =====
##please enter the amount of cookies you want to cook: 3
##for 3 cookies you will need:
##the total cups of sugar you need is 4.5
##the total cups of butter you need is 3.0
##the total cups of flour you need is 8.25
##>>> 
