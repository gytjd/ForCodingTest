import sys
import heapq

n=int(sys.stdin.readline())
heap=[]

for _ in range(n):
    temp=int(sys.stdin.readline())

    if temp==0:
        if heap:
            value=heapq.heappop(heap)
            if value[1]==-1:
                print(-value[0])
            else:
                print(value[0])
        else:
            print(0)

    else:
        if temp<0:
            heapq.heappush(heap, (-temp, -1))
        else:
            heapq.heappush(heap, (temp,0))