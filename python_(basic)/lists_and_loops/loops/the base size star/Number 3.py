base=int(input("Enter the base size : "))
x=base

while x>=1:
    spc=base-x
    print(" "*spc,x*'*')
    x=x-1
