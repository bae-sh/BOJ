n = int(input())
dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

for i in range(n):
    m = int(input())
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())

    if x1 == x2 and y1 == y2:
        print(0)
        continue

    v = [[0]*m for i in range(m)]
    q = [[x1, y1]]
    while q:
        x, y = q.pop(0)
        for i in range(8):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0 <= nx < m and 0 <= ny < m and v[nx][ny] == 0:
                v[nx][ny] = v[x][y]+1
                q.append([nx, ny])
        if v[x2][y2] != 0:
            print(v[x2][y2])
            break
