import sys

n=int(sys.stdin.readline())

consult=list()

for _ in range(n):
    a,b=map(int,sys.stdin.readline().split())
    consult.append((a,b))

dp=[0 for i in range(n)]
for i in range(n):
    if (consult[i][0]+(i+1))<=n+1:
        dp[i]=consult[i][1]


for i in range(n):
    for j in range(i+consult[i][0],n):
        if consult[j][0]+(j+1)<=n+1:
            dp[j]=max(dp[i]+consult[j][1],dp[j])

print(max(dp))