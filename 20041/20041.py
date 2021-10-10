import sys
input = sys.stdin.readline

N = int(input())
input_list = []
ans = False
left = right = up = down = 0
for i in range(N+1):
    input_temp = input().split()
    input_list.append([int(input_temp[0]), int(input_temp[1])])

for i in range(N):
    x = input_list[N][0]-input_list[i][0]
    y = input_list[N][1]-input_list[i][1]
    if x > 0 and x >= abs(y):
        left += 1
    if x < 0 and abs(x) >= abs(y):
        right += 1
    if y > 0 and y >= abs(x):
        down += 1
    if y < 0 and abs(y) >= abs(x):
        up += 1

if left == 0 or right == 0 or up == 0 or down == 0:
    ans = True
if ans:
    print("YES")
else:
    print("NO")
