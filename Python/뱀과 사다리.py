import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())

mapGraph=[[0 for i in range(10)]for j in range(10)]

visited=[[0 for i in range(10)]for i in range(10)]
queue=deque()

ladder=list()
snake=list()

for _ in range(n):
    start,end=map(int,sys.stdin.readline().split())
    ladder.append((start,end))

    start=start-1
    mapGraph[start//10][start%10]=1

for _ in range(m):
    start,end=map(int,sys.stdin.readline().split())
    snake.append((start,end))

    start=start-1
    mapGraph[start//10][start%10]=2




def ladder_snake(current):
    queue.append(current)

    while queue:
        current=queue.popleft()

        if current==100:
            print(mapGraph[(current-1)//10][(current-1)%10])
            break

        for i in range(1,7):
            tempCurrent=current+i

            if tempCurrent>100:
                continue

            if mapGraph[(tempCurrent-1)//10][(tempCurrent-1)%10]==1:
                for i in ladder:
                    if i[0]==tempCurrent and visited[(tempCurrent-1)//10][(tempCurrent-1)%10]==0:
                        visited[(tempCurrent - 1) // 10][(tempCurrent - 1) % 10] == 1
                        mapGraph[(tempCurrent - 1) // 10][(tempCurrent - 1) % 10] = mapGraph[(current - 1) // 10][(current - 1) % 10] + 1
                        queue.append(i[1])

            elif mapGraph[(tempCurrent-1)//10][(tempCurrent-1)%10]==2:
                for i in snake:
                    if i[0]==tempCurrent and visited[(tempCurrent-1)//10][(tempCurrent-1)%10]==0:
                        visited[(tempCurrent - 1) // 10][(tempCurrent - 1) % 10] == 1
                        mapGraph[(tempCurrent - 1) // 10][(tempCurrent - 1) % 10] = mapGraph[(current - 1) // 10][(current - 1) % 10] + 1
                        queue.append(i[1])

            else:
                if visited[(tempCurrent-1)//10][(tempCurrent-1)%10]==0:
                    visited[(tempCurrent - 1) // 10][(tempCurrent - 1) % 10] == 1
                    mapGraph[(tempCurrent - 1) // 10][(tempCurrent - 1) % 10] = mapGraph[(current-1)//10][(current-1)%10]+1
                    queue.append(tempCurrent)


ladder_snake(1)

for i in mapGraph:
    print(i)