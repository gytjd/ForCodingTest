import sys

from itertools import combinations_with_replacement

n, m = map(int, sys.stdin.readline().split())
array = list(map(int, sys.stdin.readline().split()))
array.sort()

array = list(combinations_with_replacement(array, m))
array=sorted(list(set(array)))

for i in array:
    print(*i)