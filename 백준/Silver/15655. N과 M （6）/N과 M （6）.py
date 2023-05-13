import sys

from itertools import combinations

n,m=map(int,sys.stdin.readline().split())
array=list(map(int,sys.stdin.readline().split()))
array.sort()

array=list(combinations(array,m))

for i in array:
    print(*i)