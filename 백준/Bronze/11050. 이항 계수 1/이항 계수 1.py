import sys
from itertools import combinations
n,m=map(int,sys.stdin.readline().split())
array=[i for i in range(1,n+1)]
result=list(combinations(array,m))
print(len(result))
