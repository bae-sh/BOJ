N = int(input())
N_list = list(map(int, input().split()))
M = int(input())
M_list = list(map(int, input().split()))
dp = [False for i in range(40001)]
dp[0] = True
for cur in N_list:
    ans = list()
    for j in range(40000, 0, -1):
        if dp[j] and cur-j >= 0:
            ans.append(cur-j)
        if dp[j] and j-cur >= 0:
            ans.append(j-cur)
        if j-cur >= 0 and dp[j-cur]:
            ans.append(j)

    for j in ans:
        dp[j] = True


for i in M_list:
    if dp[i]:
        print("Y", end=" ")
    else:
        print("N", end=" ")
