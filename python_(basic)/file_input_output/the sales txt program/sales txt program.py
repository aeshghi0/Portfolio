#using loops for printing an statement in a txt files


def main():
    num_days=int(input("for how many days did you have sales"))
    sales_file=open('sales.txt','w')

    for count in range(1,num_days+1):
        sales=float(input("enter the sales for the day #"+str(count)+':'))
        sales_file.write(str(sales)+'\n')
    sales_file.close()
    print('data written on the sales.txt')

if __name__=='__main__':
    main()
