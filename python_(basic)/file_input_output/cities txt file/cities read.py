#read datat into a list
def main():
    infile=open('cities.txt','r')
    cities=infile.readlines()

    infile.close()
    print(cities)
    index=0
    while index<len(cities):
        cities[index]=cities[index].rstrip('\n')
        index+=1
    print(cities)

if __name__=='__main__':
    main()
