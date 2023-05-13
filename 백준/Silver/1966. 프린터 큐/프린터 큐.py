import sys
from collections import deque
n=int(input())

for _ in range(n):
    queue=deque()
    n,m=map(int,sys.stdin.readline().split())
    temp=list(map(int,sys.stdin.readline().split()))

    for i in range(len(temp)):
        queue.append((temp[i],i))


    count=1
    while queue:
        x,y=queue.popleft()


        for i in queue:
            if x<i[0]:
                queue.append((x,y))
                break
        else:
            count+=1

            if y == m:
                print(count-1)
                break






