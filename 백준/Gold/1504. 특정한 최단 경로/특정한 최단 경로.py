import sys
INF=int(1e9)

n,m=map(int,sys.stdin.readline().split())

graph=[list() for i in range(n+1)]

distance=[INF for i in range(n+1)]
visited=[0 for i in range(n+1)]

for _ in range(m):
    start,end,weight=map(int,sys.stdin.readline().split())
    graph[start].append((end,weight))
    graph[end].append((start,weight))

vertex=list(map(int,sys.stdin.readline().split()))

def get_min_pos():
    min_value=INF
    minpos=-1

    for i in range(1,n+1):
        if visited[i]==0 and distance[i]<min_value:
            min_value=distance[i]
            minpos=i

    return minpos

def Dijkstra(start):

    for i in graph[start]:
        distance[i[0]]=i[1]

    distance[start] = 0
    visited[start]=1

    for _ in range(n-1):
        w=get_min_pos()
        visited[w]=1

        for j in graph[w]:
            if visited[j[0]]==0:
                if distance[w]+j[1]<distance[j[0]]:
                    distance[j[0]]=distance[w]+j[1]


Dijkstra(1)

tempA=distance[vertex[0]]
tempB=distance[vertex[1]]


for i in range(2):
    distance = [INF for i in range(n + 1)]
    visited = [0 for i in range(n + 1)]

    Dijkstra(vertex[i])

    if i==0:
        tempA += distance[vertex[1]]

        distance = [INF for i in range(n + 1)]
        visited = [0 for i in range(n + 1)]

        Dijkstra(vertex[1])

        tempA+=distance[n]
    else:
        tempB += distance[vertex[0]]

        distance = [INF for i in range(n + 1)]
        visited = [0 for i in range(n + 1)]

        Dijkstra(vertex[0])

        tempB += distance[n]

if tempA>=INF and tempB>=INF:
    print(-1)
else:
    print(min(tempA, tempB))





