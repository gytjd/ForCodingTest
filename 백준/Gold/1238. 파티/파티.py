import sys
INF=int(1e9)

n,m,x=map(int,sys.stdin.readline().split())

graph=[list() for i in range(n+1)]

for _ in range(m):
    start,end,weight=map(int,sys.stdin.readline().split())
    graph[start].append((end,weight))

def get_min_pos():
    min_value=INF
    minpos=-1

    for i in range(1,n+1):
        if visited[i]==0 and distance[i]<min_value:
            min_value=distance[i]
            minpos=i

    return minpos


def Dijkstra(start):
    distance[start]=0
    visited[start]=1

    for i in graph[start]:
        distance[i[0]]=i[1]


    for _ in range(n-1):

        w=get_min_pos()
        visited[w]=1

        for i in graph[w]:
            if visited[i[0]]==0:
                if distance[w] + i[1] < distance[i[0]]:
                    distance[i[0]] = distance[w] + i[1]


result=[0 for i in range(n+1)]
temp=[0 for i in range(n+1)]


for i in range(1,n+1):
    distance = [INF for i in range(n + 1)]
    visited = [0 for i in range(n + 1)]

    if i==x:

        Dijkstra(i)

        for i in range(1,n+1):
            temp[i]=distance[i]

    Dijkstra(i)

    result[i]=distance[x]

for i in range(1,n+1):
    result[i]=temp[i]+result[i]

print(max(result))



