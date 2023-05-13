import sys

from itertools import permutations

n, m = map(int, sys.stdin.readline().split())
array = list(map(int, sys.stdin.readline().split()))

array = list(permutations(array, m))

array=sorted(list(set(array)))

for i in array:
    print(*i)
