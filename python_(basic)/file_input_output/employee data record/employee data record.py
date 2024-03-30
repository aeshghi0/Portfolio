def main ():
    num_emps = int (input ("How many employee records do you want?"))
    emp_file = open ('employees.txt', 'w')
    for count in range (1, num_emps+1):
        print ('Enter data for employee#', count, sep='')
        name = input ('name: ')
        id_num = input ('ID number : ')
        dept = input ('Dept amount : ')
        emp_file.write(name + '\n')
        emp_file.write(id_num + '\n')
        emp_file.write(dept + '\n')

    emp_file.close()
    print("Employess data written to file")

if __name__ == "__main__":
    main()
