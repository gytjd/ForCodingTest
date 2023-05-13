import heapq
import sys

n=int(sys.stdin.readline())

min_heap=[]

for _ in range(n):
    temp=int(sys.stdin.readline())

    if temp==0:
        if min_heap:
            print(heapq.heappop(min_heap))
        else:
            print(0)
    else:
        heapq.heappush(min_heap,temp)
