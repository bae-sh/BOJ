n = int(input())
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
v = []
count = 1
check = [[0]*n for i in range(n)]
ans = [[0]*n for i in range(n)]

for i in range(n):
    li = list(map(int, input().split()))
    v.append(li)


def bfs(sx, sy, c):
    check[sx][sy] = True
    q = [[sx, sy]]
    while q:
        x, y = q.pop(0)
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0 <= nx < n and 0 <= ny < n and not check[nx][ny] and v[nx][ny] != 0:
                q.append[[nx, ny]]
                check[nx][ny] = True
                v[nx][ny] = c


def dfs(x, y, depth):
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]


for i in range(n):
    for j in range(n):
        ans[i][j] = bfs(i, j, count)
