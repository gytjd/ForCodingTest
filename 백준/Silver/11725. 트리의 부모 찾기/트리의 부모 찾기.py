import sys
from collections import deque

n=int(input())
mapGraph=[[]for i in range(n+1)]
visited=[0 for i in range(n+1)]
result=[0 for i in range(n+1)]

queue=deque()

for _ in range(n-1):
    start,end=map(int,sys.stdin.readline().split())
    mapGraph[start].append(end)
    mapGraph[end].append(start)

queue.append(1)
visited[1]=1

while queue:
    v=queue.popleft()

    for i in mapGraph[v]:
        if visited[i]==0:
            result[i] = v
            visited[i] = 1
            queue.append(i)

for i in range(2,n+1):
    print(result[i])