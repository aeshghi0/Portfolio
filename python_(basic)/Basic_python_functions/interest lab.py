
def show_interest(rate=0.01,periods=10,principal=10000.00):
    interest=principal*rate*periods
    print("the simple interest will be: $",format(interest,',.2f'),sep='')


def main():
    show_interest()


if __name__=="__main__":
    main()


    
