import sys

n=int(sys.stdin.readline())
array=list(map(int,sys.stdin.readline().split()))

dp=[1 for i in range(n)]

for i in range(1,n):
    for j in range(i):
        max_dp=dp[i]
        if array[j]<array[i]:
            if dp[j]+1>max_dp:
                max_dp=dp[j]+1
        dp[i]=max_dp
print(max(dp))