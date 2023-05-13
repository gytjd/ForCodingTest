import sys

n=int(sys.stdin.readline())
dp=[0 for i in range(100001)]
dp[1]=1
dp[2]=2
dp[3]=3

for i in range(4,100001):
    if i%3==0:
        dp[i] = dp[i - 1] + dp[i - 2] - dp[i - 3]+1
    else:
        dp[i]=dp[i-1]+dp[i-2]-dp[i-3]

for _ in range(n):
    idx=int(sys.stdin.readline())
    print(dp[idx])