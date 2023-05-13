import sys

n=int(sys.stdin.readline())
array=list(map(int,sys.stdin.readline().split()))

dp=[1 for i in range(n)]

for i in range(1,n):
    for j in range(i):
        if array[i]<array[j]:
            dp[i]=max(dp[j]+1,dp[i])

print(max(dp))