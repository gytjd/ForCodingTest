import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())

array=[0 for i in range(100001)]
visited=[0 for i in range(100001)]

def BFS_subin(first):
    queue = deque()
    queue.append(first)
    visited[first]=1

    while queue:
        current=queue.popleft()

        if current==m:
            print(array[current])
            break

        for i in range(3):
            if i==0 or i==1:
                if i==0:
                    dx=current+1

                    if dx<0 or dx>=100001:
                        continue

                    if visited[dx] == 0:
                        visited[dx] = 1

                        if current+1==current*2:
                            array[dx]=array[current]
                            queue.appendleft(dx)
                        else:
                            array[dx] = array[current] + 1
                            queue.append(dx)

                else:
                    dx=current-1

                    if dx<0 or dx>=100001:
                        continue

                    if visited[dx] == 0:
                        visited[dx] = 1
                        array[dx] = array[current]+1
                        queue.append(dx)
            else:
                dx=current*2

                if dx<0 or dx>=100001:
                    continue

                if visited[dx] == 0:
                    visited[dx] = 1
                    array[dx] = array[current]
                    queue.appendleft(dx)

BFS_subin(n)
