import sys
from collections import deque

dir=[[0,0,1],[0,1,0],[0,0,-1],[0,-1,0],[1,0,0],[-1,0,0]]

x,y,z=map(int,sys.stdin.readline().split())
graph=[[list(map(int,sys.stdin.readline().split()))for i in range(y)]for i in range(z)]
visited=[[[0 for i in range(x)]for i in range(y)]for i in range(z)]


tomato=deque()

for i in range(z):
    for j in range(y):
        for k in range(x):
            if graph[i][j][k]==1:
                tomato.append((i,j,k))
                visited[i][j][k]=1

def check_toma():
    for i in range(z):
        for j in range(y):
            for k in range(x):
                if graph[i][j][k]==0:
                    return 0
    return 1


value=1
def BFS_tomato():
    global value

    while tomato:
        tempZ,tempX,tempY=tomato.popleft()

        for i in range(6):
            dz=tempZ+dir[i][0]
            dx=tempX+dir[i][1]
            dy=tempY+dir[i][2]

            if dz<0 or dz>=z or dx<0 or dx>=y or dy<0 or dy>=x:
                continue

            if graph[dz][dx][dy]==0:
                if visited[dz][dx][dy]==0:
                    visited[dz][dx][dy]=1
                    tomato.append((dz,dx,dy))
                    graph[dz][dx][dy]=graph[tempZ][tempX][tempY]+1
                    value=graph[tempZ][tempX][tempY]+1


BFS_tomato()

if check_toma()==0:
    print(-1)
else:
    print(value-1)