import sys

n=int(sys.stdin.readline())
graph=[list(map(int,sys.stdin.readline().split()))for i in range(n)]

temp=[list() for i in range(n+1)]

for i in range(n):
    for j in range(n):
        if graph[i][j]==1:
            temp[i].append(j)

def DFS_recur(first):

    for i in temp[first]:
        if visited[i]==0:
            visited[i] = 1
            DFS_recur(i)

for i in range(n):
    visited=[0 for i in range(n)]
    DFS_recur(i)
    print(*visited)
