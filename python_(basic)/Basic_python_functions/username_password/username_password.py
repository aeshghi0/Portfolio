#chack password program
#password must have at least 7 chars long
#must contain one upper case
#at least one lowercase
#at least one numeric value

def main():
    first_name=input("Enter your first name: ")
    last_name=input("enter your last name: ")
    idnum=input("enter your ID: ")

    print("your system login name is: ")
    print(get_login_name(first_name,last_name,idnum))

    password=input("Enter password: ")
    while not valid_password(password):
        print("Password not valid")
        password=input("Enter the password: ")
    print("Valid Password")
        

def get_login_name(first_name:str,last_name:str,idnum:str):
    set1=first_name[:3]
    set2=last_name[:3]
    set3=idnum[-3:]

    get_login_name=set1+set2+set3
    return get_login_name


def valid_password(password:str):
    '''validiate password fulfill criteria'''
    #set boolean to false
    correct_length=False
    has_uppercase=False
    has_lowercase=False
    has_digit=False
    #test for lenght
    if len(password)>7:
        correct_lenght=True
        for ch in password:
            if ch.isupper():
                has_uppercase=True
            if ch.islower():
                has_lowercase=True
            if ch.isdigit():
                has_digit=True
    if correct_lenght and has_uppercase and has_lowercase and has_digit:
        is_valid=True
    else:
        is_valid=False
    return is_valid



if __name__=="__main__":
    main()
