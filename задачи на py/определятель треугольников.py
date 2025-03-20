while True: 
    sid,tr='abc',[] 

    for i in sid: 
        try:
            tr +=[int(input(i+'='))] 
        except ValueError:
            print('Введен символ')
            exit(0)
    tr.sort()

    if tr[0]<=0: 
        print('Одна из сторон меньше или равна 0') 
        break 
    elif tr[0]+tr[1]<=tr[2]: 
        print('две стороны короче третьей')
        break
    
    if tr[0]==tr[2]: 
        frm='равносторонний ' 
    elif tr.count(tr[1])>1: 
        frm='равнбедренный ' 
    if tr[0]**2+tr[1]**2 == tr[2]**2: 
        frm ='прямоугольный ' 
    elif tr[0]**2+tr[1]**2 < tr[2]**2: 
        frm +=' тупоугольный' 
    else: frm +=' остроугольный ' 
    p=sum(tr)/2
    S=p 
    for c in tr: 
        S *=(p-c) 
    print(frm+'\nплощадь=',S**0.5)