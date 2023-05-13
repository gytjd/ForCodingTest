import sys

from itertools import product

n,m=map(int,sys.stdin.readline().split())
array=list(map(int,sys.stdin.readline().split()))
array.sort()

array=list(product(array,repeat=m))

for i in array:
    print(*i)