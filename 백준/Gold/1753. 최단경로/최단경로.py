import sys
INF=sys.maxsize

n,m=map(int,sys.stdin.readline().split())
startVertex=int(sys.stdin.readline())

distance=[INF]*(n+1)
visited=[False]*(n+1)

graph=[[] for _ in range(n+1)]

for _ in range(m):
    start,end,weight=map(int,sys.stdin.readline().split())
    graph[start].append((end,weight))

def get_min_pos():
    min_value=INF
    minpos=-1

    for i in range(1,n+1):
        if visited[i]==0 and distance[i]<=min_value:
            min_value=distance[i]
            minpos=i

    return minpos

def Dijkstra(start):

    for i in graph[start]:
        if distance[i[0]]>=i[1]:
            distance[i[0]]=i[1]

    distance[start]=0
    visited[start]=True

    for _ in range(n-1):
        w=get_min_pos()
        visited[w]=True

        for i in graph[w]:
            if distance[w]+i[1] < distance[i[0]]:
                distance[i[0]]= distance[w]+i[1]

Dijkstra(startVertex)

for i in range(1,n+1):
    if distance[i]==INF:
        print('INF')
    else:
        print(distance[i])

