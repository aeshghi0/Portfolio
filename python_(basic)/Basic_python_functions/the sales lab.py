def get_sales()->float:
    sales=float(input("Enter the monthly sales: "))

def get_advanced_pay()->float:
    advanced_pay=float(input("Enter the amount of advanced pay,\n or enter 0 if no advanced pay was given"))

def determine_comm_rate(sales)->float:
    comm_rate=0.12

def main():
    sales=get_sales()
    advanced_pay=get_advanced_pay()
    comm_rate=determine_comm_rate(sales)

    pay=sales*comm_rate-advanced_pay

    if pay<0:
        print("the sales person must reimburse")
        print("the company")



if __name__=="__main__":
    main()
