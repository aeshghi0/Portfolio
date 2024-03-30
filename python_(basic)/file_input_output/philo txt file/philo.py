#write data file

def main():
    outfile=open('philo.txt','w')

    #write data to file
    outfile.write('John locke \n')
    outfile.write('Amir joghd \n')
    outfile.write('Sia chaghalian \n')

    #close file
    outfile.close()

if __name__=='__main__':
    main()
    
