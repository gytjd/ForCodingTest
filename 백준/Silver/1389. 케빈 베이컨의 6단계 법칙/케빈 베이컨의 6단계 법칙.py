import sys
from math import inf

n,m=map(int,sys.stdin.readline().split())

cost=[[inf] * n for _ in range(n)]

for _ in range(m):
    start,end=map(int,sys.stdin.readline().split())
    cost[start-1][end-1]=1
    cost[end-1][start-1]=1

for i in range(n):
    for j in range(n):
        if i==j:
            cost[i][j]=0

for k in range(n):
    for i in range(n):
        for j in range(n):
            cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j])

result=list()
for i in cost:
    result.append(sum(i))

print(result.index(min(result))+1)
