#read data from philo.txt

def main():
    infile=open('philo.txt','r')
    file_contents=infile.read()
    infile.close()
    print(file_contents)

if __name__=='__main()__':
    main()
