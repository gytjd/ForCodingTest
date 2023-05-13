import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())
graph=[[0 for i in range(10)]for j in range(10)]
visited=[[0 for i in range(10)]for j in range(10)]

for _ in range(n):
    start,end=map(int,sys.stdin.readline().split())
    graph[(start-1)//10][(start-1)%10]=end

for _ in range(m):
    start, end = map(int, sys.stdin.readline().split())
    graph[(start-1) // 10][(start-1) % 10] = end


def Snake_Ladder(current):
    queue=deque()
    queue.append(current)

    visited[(current-1)//10][(current-1)%10]=1

    while queue:
        current=queue.popleft()

        if current==100:
            print(graph[(current-1)//10][(current-1)%10])
            break

        for i in range(1,7):
            tempCurreunt=current+i
            dx=(tempCurreunt-1)//10
            dy=(tempCurreunt-1)%10

            if tempCurreunt<1 or tempCurreunt>100:
                continue

            if visited[dx][dy]==0:
                if graph[dx][dy]!=0:
                    tempCurreunt=graph[dx][dy]

                    visited[dx][dy]=1
                    graph[dx][dy]=graph[(current-1)//10][(current-1)%10]+1

                    if visited[(tempCurreunt-1)//10][(tempCurreunt-1)%10]==0:
                        visited[(tempCurreunt - 1) // 10][(tempCurreunt - 1) % 10] = 1
                        graph[(tempCurreunt - 1) // 10][(tempCurreunt - 1) % 10] = graph[(current - 1) // 10][(current - 1) % 10] + 1
                        queue.append(tempCurreunt)
                else:
                    visited[dx][dy] = 1
                    graph[dx][dy] = graph[(current - 1) // 10][(current - 1) % 10] + 1
                    queue.append(tempCurreunt)



Snake_Ladder(1)
