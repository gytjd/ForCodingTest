import sys
from collections import deque

dir=[[0,1],[1,0],[0,-1],[-1,0]]

n,m=map(int,sys.stdin.readline().split())
graph=[list(map(int,sys.stdin.readline().rstrip()))for i in range(m)]
visited=[[0 for i in range(n)]for i in range(m)]

def BFS_algo(x,y):
    queue = deque()
    queue.append((x,y))
    visited[x][y]=1

    while queue:
        x,y=queue.popleft()

        if x==m-1 and y==n-1:
            print(graph[x][y])
            break

        for i in range(4):
            dx=x+dir[i][0]
            dy=y+dir[i][1]

            if dx<0 or dx>=m or dy<0 or dy>=n:
                continue

            if visited[dx][dy]==0 and graph[dx][dy]==0:
                visited[dx][dy]=1
                queue.appendleft((dx,dy))
                graph[dx][dy]=graph[x][y]

            if visited[dx][dy]==0 and graph[dx][dy]==1:
                visited[dx][dy]=1
                queue.append((dx,dy))
                graph[dx][dy] = graph[x][y]+1


BFS_algo(0,0)