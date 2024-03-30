def get_scores()->list:
    scores=[]
    again='y'
    while again=='y':
        value=float(input("enter a test score:  "))
        scores.append(value)
        print('Do you want to add another score')
        again=input('y=Yes, n=No')
    return scores

def get_total(scores)->float:
    all_scores.sort()
    all_scores.remove(scores[0])

    count=0
    summ=o
    for n in all_scores:
        summ=summ+n
        count=count+1


    avg=summ/count
    return avg

def main():
    scores=get_scores()
    total=get_total(scores)

    print("the average with lowest score dropped is ",avg)


if __name__=='__main__':
    main()

