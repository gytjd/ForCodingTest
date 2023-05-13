import sys

n=int(sys.stdin.readline())

graph=[list(map(int,sys.stdin.readline().split())) for i in range(n)]

dp=[[0 for i in range(j+1)]for j in range(n)]
dp[0][0]=graph[0][0]

for i in range(1,n):
    for j in range(i+1):
        if j==0:
            dp[i][j]=dp[i-1][j]+graph[i][j]
        elif j==i:
            dp[i][j] =dp[i-1][j-1]+graph[i][j]
        else:
            dp[i][j] =max(dp[i-1][j-1]+graph[i][j],dp[i-1][j]+graph[i][j])


print(max(dp[n-1]))