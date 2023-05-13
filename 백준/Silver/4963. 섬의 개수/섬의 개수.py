import sys
sys.setrecursionlimit(10**6)

dir=[[1,1],[1,0],[1,-1],[0,-1],[-1,-1],[-1,0],[-1,1],[0,1]]


def DFS_recur(x,y):
    if x<0 or x>=h or y<0 or y>=w:
        return 0

    if mapGraph[x][y]==1:
        mapGraph[x][y]=0

        for i in range(8):
            dx=x+dir[i][0]
            dy=y+dir[i][1]
            DFS_recur(dx,dy)
        return 1
    return 0

while True:
    w,h=map(int,sys.stdin.readline().split())

    if w==0 and h==0:
        break

    mapGraph=list()
    for _ in range(h):
        mapGraph.append(list(map(int,input().split())))

    num=0
    for i in range(h):
        for j in range(w):
            if DFS_recur(i,j)==1:
                num+=1
    print(num)
