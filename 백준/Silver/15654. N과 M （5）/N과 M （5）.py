import sys

from itertools import permutations

n,m=map(int,sys.stdin.readline().split())
array=list(map(int,sys.stdin.readline().split()))
array.sort()

array=list(permutations(array,m))

for i in array:
    print(*i)