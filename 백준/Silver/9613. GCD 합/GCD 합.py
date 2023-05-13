import sys
from itertools import combinations
from math import gcd
n=int(input())

for _ in range(n):
    count=0
    array=list(map(int,sys.stdin.readline().split()))
    array.remove(array[0])
    result=list(combinations(array,2))
    for i in range(len(result)):
        count+=gcd(result[i][0],result[i][1])

    print(count)

