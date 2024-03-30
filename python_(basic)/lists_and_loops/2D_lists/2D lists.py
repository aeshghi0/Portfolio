
def main():
    rows=int(input("enter the rows number: "))
    cols=int(input("enter the columns number: "))
    values=[]
    for r in range(rows):
        values.append([])
        for c in range(cols):
            values[r].append(0)

    print(values)


if __name__=='__main__':
    main()
