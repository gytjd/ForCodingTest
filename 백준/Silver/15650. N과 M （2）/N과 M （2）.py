import sys

from itertools import combinations

n,m=map(int,sys.stdin.readline().split())
array=list()
for i in range(1,n+1):
    array.append(i)

array=list(combinations(array,m))

for i in array:
    print(*i)