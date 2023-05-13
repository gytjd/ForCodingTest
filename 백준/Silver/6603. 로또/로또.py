import sys
from itertools import combinations

while True:
    array = list(map(int, sys.stdin.readline().split()))

    if array[0]==0:
        break
        
    array = list(combinations(array[1:], 6))

    for i in array:
        print(*i)
    print()
