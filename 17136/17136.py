li = []
count = [5, 5, 5, 5, 5]
ans = 0
isPossible = True


def changePaper(x, y, k):
    global ans
    global isPossible
    if k < 0:
        return
    if count[k] < 0:
        isPossible = False
    else:
        for i in range(k+1):
            nx = x+i
            for j in range(k+1):
                ny = y+j
                li[nx][ny] = '0'
        count[k] -= 1
        ans += 1


def check(x, y):
    for k in range(5):
        for i in range(k+1):
            nx = x+i
            for j in range(k+1):
                ny = y+j
                if nx > 9 or ny > 9:
                    return k
                if li[nx][ny] == '0':
                    return k
    return 4


for i in range(10):
    li.append(input().split())
for i in range(10):
    for j in range(10):
        k = check(i, j)
        changePaper(i, j, k-1)
if isPossible:
    print(ans)
else:
    print(-1)
