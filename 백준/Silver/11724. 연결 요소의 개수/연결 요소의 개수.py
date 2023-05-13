import sys

n,m=map(int,sys.stdin.readline().split())
graph=[[]for i in range(n+1)]
graph[0].append(0)

visited=[0 for i in range(n+1)]

for _ in range(m):
    start,end=map(int,sys.stdin.readline().split())
    graph[start].append(end)
    graph[end].append(start)

def DFS_recur(first):
    visited[first]=1

    for i in graph[first]:
        if visited[i]==0:
            DFS_recur(i)


count=0
for i in range(1,n+1):
    if visited[i]==0:
        DFS_recur(i)
        count+=1

print(count)