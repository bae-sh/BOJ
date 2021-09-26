def go(s, ma):
    v = list(0 for i in range(ma+1))
    t = 0
    for i in range(len(s)):
        if(i+1 < len(s) and s[i] == '(' and s[i+1] == ')'):
            v[t] += 1
        elif (s[i] == '('):
            t += 1
        elif (s[i-1] != '('):
            t -= 1
    for i in range(ma):
        v[i+1] += v[i]//2
        v[i] %= 2
    v.reverse()
    return v


T = int(input())
for i in range(T):
    A = input()
    B = input()
    ma = max(len(A), len(B))
    ansA = go(A, ma)
    ansB = go(B, ma)
    if(ansA > ansB):
        print(">")
    elif(ansA == ansB):
        print("=")
    else:
        print("<")
