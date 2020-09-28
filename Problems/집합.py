list=set([])
copy=['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20']
re=[]
n=int(input())
for i in range(n):
    z=input()
    z=z.split(' ')
    if(len(z)==2):
        x=z[0]
        y=z[1]
    else:
        x=z[0]
    if(x=="add"):
        list.add(y)
    elif(x=="remove"):
        list.discard(y)
    elif(x=="check"):
        if y in list:
            re.append("1")
        else:
            re.append("0")
    elif(x=="toggle"):
        if y in list:
            list.discard(y)
        else:
            list.add(y)
    elif(x=="all"):
        list.clear()
        list=set(copy)
    elif(x=="empty"):
        list.clear()
for i in range(len(re)):
    print(re[i])
        
