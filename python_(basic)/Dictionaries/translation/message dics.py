#set 1

def message():
    message_dic={'r':'are', 'y':'why', 'u':'you', 'ttyl':'talk to you later', 'l8':'late', 'brb':'be right back', 'lol':'laughing out loud', 'bbl':'be back later', 'tldr':'too long; didn\'t read'
,'rofl':'rolling on floor laughing', 'gtg':'got to go','cya':'see you','cuzz':'because','bff':'best friend forever','idk':'I don\'t know','sup':'what\'s up?','omg':'oh my gosh','nbd':'no big deal','tisnf':'this is not fair',
'nw':'no way!','rus':'are you serious?','myob':'mind your own business','njoy':'enjoy','nter':'enter','1ce':'once','aka':'also known as','afk':'away from keyboard','jk':'just kidding',
'asap':'as soon as possible','app':'application','atm':'at the moment','b4':'before','fyi':'for your information','bday':'birthday','k':'okay','msg':'message','np':'no problem','pic':'picture',
'plz':'please','sry':'sorry','dunno':'don\'t know','wut':'what','wuts':'what\'s'}

    message=input("what message do you want to translate?  ")
    message_splitted= message.split(" ")
    message_translated=[]
    dic_key=message_dic.keys()
    for i in message_splitted:
        if i in dic_key:
            message_translated.append(message_dic[str(i)])
        elif i not in dic_key:
            message_translated.append(i)

    str_1=''
    for i in message_translated:
        str_1=str_1+i+" "
    print(str_1)

    
    

def main():
    message()


if __name__=="__main__":
    main()
##        
##>>> 
##====== RESTART: /Users/alieshghi/Desktop/homework five/message dics.py ======
##what message do you want to translate?  r u ready
##are you ready 
##>>> 
##====== RESTART: /Users/alieshghi/Desktop/homework five/message dics.py ======
##what message do you want to translate?  ttyl
##talk to you later 
##>>> 
##====== RESTART: /Users/alieshghi/Desktop/homework five/message dics.py ======
##what message do you want to translate?  gtg
##got to go 
##>>> 
