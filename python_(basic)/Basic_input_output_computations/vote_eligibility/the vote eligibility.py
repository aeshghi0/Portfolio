#input

age=int(input("Enter the age : "))

#calc

agecheck=age-18

#output

if agecheck<0:
    print("You have to wait",-agecheck,"years to cast your vote")
else:
    print("you are eligible to vote")

    
    
##>>> 
##== RESTART: /Users/alieshghi/Desktop/cs10/Lab 2.Ali/the vote eligibility.py ==
##Enter the age : 43
##you are eligible to vote
##>>> 
##== RESTART: /Users/alieshghi/Desktop/cs10/Lab 2.Ali/the vote eligibility.py ==
##Enter the age : 17
##You have to wait 1 years to cast your vote
##>>> 
