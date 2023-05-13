import sys

n=int(input())

graph=[[]for i in range(n+1)]

for i in range(n):
    temp=list(map(int,sys.stdin.readline().split()))

    start=temp[0]

    for i in range(1,len(temp)-1,+2):
        graph[start].append((temp[i],temp[i+1]))

visited=[0 for i in range(n+1)]
result=[0 for i in range(n+1)]

def dfs(start):
    visited[start]=1

    for i in graph[start]:
        if visited[i[0]]==0:
            result[i[0]]=result[start]+i[1]
            dfs(i[0])

dfs(1)
temp1=max(result)
next_node=result.index(max(result))
visited=[0 for i in range(n+1)]
result=[0 for i in range(n+1)]
dfs(next_node)
temp2=max(result)

print(max(temp1,temp2))
