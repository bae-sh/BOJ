def cal(s):
    dp = [[False for i in range(len(s))] for i in range(len(s))]  # [시작][끝]

    ans = 1
    for i in range(1, len(s)+1):  # 길이
        for j in range(len(s)):  # index
            if(j+i-1 >= len(s)):
                break

            if(i == 1):
                dp[j][j+i-1] = True
            elif(i == 2):
                if(s[j] == s[j+1]):
                    dp[j][j+i-1] = True
                    ans = max(ans, 2)
            else:
                if(dp[j+1][j+i-2] and s[j] == s[j+i-1]):
                    dp[j][j+i-1] = True
                    ans = max(ans, i)
    return ans


s = input()

print(cal(s))
