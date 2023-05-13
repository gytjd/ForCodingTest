import sys
from math import sqrt
dp=[0 for i in range(50001)]
dp[1]=1
dp[2]=2
dp[3]=3
sqrt_value=1

def is_sqrt(value):
    return sqrt(value)%1==0

for i in range(4,50001):

    if is_sqrt(i):
        dp[i]=1
        sqrt_value=i
    else:
        temp=list()
        temp_value=int(sqrt(sqrt_value))
        for j in range(1,temp_value+1):
            temp.append(dp[i-(j*j)])

        dp[i]=min(temp)+1

n = int(sys.stdin.readline())
print(dp[n])