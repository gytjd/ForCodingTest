import sys

n=int(sys.stdin.readline())

for _ in range(n):
    m=int(sys.stdin.readline())

    tempA = list(map(int, sys.stdin.readline().split()))
    tempB = list(map(int, sys.stdin.readline().split()))

    if m==1:
        print(max(tempA[0],tempB[0]))
    else:
        dp = [[0 for i in range(m)] for i in range(2)]

        dp[0][0] = tempA[0]
        dp[1][0] = tempB[0]

        dp[0][1] = tempA[1] + tempB[0]
        dp[1][1] = tempA[0] + tempB[1]

        for i in range(2, m):
            dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + tempA[i]
            dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + tempB[i]

        print(max(dp[0][m - 1], dp[1][m - 1]))