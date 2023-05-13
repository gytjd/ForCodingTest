import sys

n=int(sys.stdin.readline())

house=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]

result=list()

dp = [[0 for i in range(3)] for i in range(n)]
dp[0][0] = house[0][0]
dp[0][1] = house[0][1]
dp[0][2] = house[0][2]

for j in range(1, n):
    dp[j][0] = min(dp[j-1][1],dp[j-1][2])+house[j][0]
    dp[j][1] = min(dp[j-1][0],dp[j-1][2])+house[j][1]
    dp[j][2] = min(dp[j-1][0],dp[j-1][1])+house[j][2]

print(min(dp[n-1][0],dp[n-1][1],dp[n-1][2]))