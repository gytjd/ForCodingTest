import sys

n = int(input())

p = list(map(int, sys.stdin.readline().split()))
p.insert(0, 0)

dp = [0] * (n + 1)

dp[1] = p[1]

for i in range(2, n + 1):
    result=10000
    for j in range(1, i):
        if result>min(dp[j]+p[i-j],p[i]):
            result=min(dp[j]+p[i-j],p[i])
    dp[i]=result
print(dp[n])
