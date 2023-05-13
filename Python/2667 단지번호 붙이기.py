import sys
from collections import deque

dir=[[0,1],[1,0],[0,-1],[-1,0]]

n=int(input())
array=[list(map(int,sys.stdin.readline().rstrip())) for i in range(n)]
visited=[[0 for i in range(n)]for i in range(n)]

def BFS_iter(x,y):
    global count

    queue = deque()
    queue.append((x,y))
    visited[x][y]=1

    while queue:
        x,y=queue.popleft()

        for i in range(4):
            dx=x+dir[i][0]
            dy=y+dir[i][1]

            if dx<0 or dx>=n or dy<0 or dy>=n:
                continue

            if array[dx][dy]==1 and visited[dx][dy]==0:
                visited[dx][dy]=1
                count+=1
                queue.append((dx,dy))


count=1
result=list()

temp_count=0

for i in range(n):
    for j in range(n):
        if array[i][j]==1 and visited[i][j]==0:
            temp_count+=1
            BFS_iter(i,j)
            result.append(count)
            count=1
print(temp_count)
for i in sorted(result):
    print(i)
