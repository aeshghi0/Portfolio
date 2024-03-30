base=int(input("Enter the base size : "))
x=1

while x<=base:
    spc=base-x
    print(" "*spc,x*'*')
    x=x+1
