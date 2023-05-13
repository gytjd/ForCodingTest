import sys

from itertools import product

n,m=map(int,sys.stdin.readline().split())
array=list()
for i in range(1,n+1):
    array.append(i)

array=list(product(array,repeat=m))

for i in array:
    print(*i)