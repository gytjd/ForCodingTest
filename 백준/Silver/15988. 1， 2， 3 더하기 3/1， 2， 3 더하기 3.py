dp=[0]*1000001

dp[0]=1
dp[1]=1
dp[2]=2


for i in range(3,1000001):
    dp[i]=dp[i-3]%1000000009+dp[i-2]%1000000009+dp[i-1]%1000000009

n=int(input())
for _ in range(n):
    num=int(input())
    print(dp[num]%1000000009)