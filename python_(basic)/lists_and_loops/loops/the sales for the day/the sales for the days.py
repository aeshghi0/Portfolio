#create a list
day_sales=5


def main():
    sales=[0]*day_sales
    day=0
    print('enter sales for each days')

    while day_sales<len(sales):
        print('Day #', index+1,': ',sep='', end='')
        sales[index]=float(input())
        index+=1

#display
    print("here are the numbers you entered")
    for value in sales:
        print(value)
