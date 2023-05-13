import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())
graph=[list(sys.stdin.readline().rstrip())for i in range(m)]
lazer_cost=[[n*m-1 for i in range(n)]for i in range(m)]

dir=[[0,1],[1,0],[0,-1],[-1,0]]

lazer_queue=deque()

for i in range(m):
    for j in range(n):
        if graph[i][j]=="C":
            lazer_queue.append((i,j))

startX,startY=lazer_queue.popleft()
endX,endY=lazer_queue.popleft()

def BFS_iter(x,y):
    lazer_queue.append((x,y,-1,0))
    lazer_cost[x][y]=0

    while lazer_queue:
        tempX,tempY,direction,mirr_cnt=lazer_queue.popleft()

        if tempX==endX and tempY==endY:
            print(mirr_cnt)
            break

        if lazer_cost[tempX][tempY]<mirr_cnt:
            continue

        lazer_cost[tempX][tempY]=mirr_cnt

        for i in range(4):
            dx=tempX+dir[i][0]
            dy=tempY+dir[i][1]

            if dx<0 or dx>=m or dy<0 or dy>=n:
                continue

            if graph[dx][dy]!="*":
                if i == direction or direction == -1:
                    lazer_queue.appendleft((dx, dy, i, mirr_cnt))
                else:
                    lazer_queue.append((dx, dy, i, mirr_cnt + 1))


BFS_iter(startX,startY)




