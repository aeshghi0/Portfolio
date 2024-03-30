#save a list of the cities
def main():
    cities=['New York','Boston','Atlanta']
    outfile=open('cities.txt','w')

    for item in cities:
        outfile.write(item+'\n')

    outfile.close()

if __name__=='__main__':
    main()
