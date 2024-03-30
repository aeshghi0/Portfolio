def main():
    indexEntries = {}
    infile = open("tea.txt","r")
    fields = extractRecord(infile)

    while len(fields) > 0:
        indexEntries = addWord(indexEntries, fields[1], fields[2], fields[3], fields[0])
        
        fields = extractRecord(infile)

    infile.close()
    printIndex(indexEntries)
    

def extractRecord(infile):
    line = infile.readline()
    if line != "":
        fields = line.split(":")
        tea = fields[0].rstrip()
        sale1 = float(fields[1])
        sale2 = float(fields[2])
        sale3 = float(fields[3])
        return [tea, sale1, sale2, sale3]
    else:
        return []

def addWord(entries, sale1, sale2, sale3, tea):
    pageSet = [sale1, sale2, sale3, (sale1+sale2+sale3)]
    entries[tea] = pageSet
        
    return entries

def printIndex(entries):
    for key in sorted(entries):
        print(key,end="\t")
        pageSet = entries[key]
        first = True
        for tea in pageSet:
            if first:
                print(tea, end="")
                first = False
            else:
                print(" ", tea, end="")
        print()
    n1=0
    n2=0
    n3=0
    for key in sorted(entries):
        keyn = entries[key]
        for x in keyn:
            n1=n1+keyn[0]
            n2=n2+keyn[1]
            n3=n2+keyn[2]
    print("\t\t",n1,", ",n2,", ",n3)
        
main()
