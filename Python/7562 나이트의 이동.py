import sys
from collections import deque
dir=[[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2],[-2,-1]]
n=int(input())

for _ in range(n):
    num=int(input())
    graph=[[0 for i in range(num)]for i in range(num)]
    visited=[[0 for i in range(num)]for i in range(num)]

    queue=deque()

    startX,startY=map(int,sys.stdin.readline().split())
    queue.append((startX,startY))
    visited[startX][startY]=1

    endX,endY=map(int,sys.stdin.readline().split())

    while queue:

        x,y=queue.popleft()

        if x==endX and y==endY:
            print(graph[x][y])
            break

        for i in range(8):
            dx=x+dir[i][0]
            dy=y+dir[i][1]

            if dx<0 or dx>=num or dy<0 or dy>=num:
                continue

            if visited[dx][dy]==0:
                visited[dx][dy]=1
                graph[dx][dy]=graph[x][y]+1
                queue.append((dx,dy))



