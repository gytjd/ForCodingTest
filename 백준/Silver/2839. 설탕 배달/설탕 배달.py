n=int(input())
dp=[-1 for i in range(5001)]

dp[3]=1
dp[5]=1

for i in range(6,5001):
    if dp[i-3]!=-1:
        tempA=dp[i-3]+1
    else:
        tempA=5001
    if dp[i-5]!=-1:
        tempB=dp[i-5]+1
    else:
        tempB=5001

    if tempA!=5001 or tempB!=5001:
        dp[i]=min(tempA,tempB)


print(dp[n])