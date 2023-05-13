import sys

from itertools import combinations

n, m = map(int, sys.stdin.readline().split())
array = list(map(int, sys.stdin.readline().split()))
array.sort()
array = list(combinations(array, m))
array=list(set(array))
array.sort()

for i in array:
    print(*i)