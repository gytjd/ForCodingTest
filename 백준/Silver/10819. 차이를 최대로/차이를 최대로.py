import sys
from itertools import permutations
n=int(sys.stdin.readline())
array=list(map(int,sys.stdin.readline().split()))

def calculate_num(temp):
    sum=0

    for i in range(n-1):
        sum+=abs(temp[i]-temp[i+1])
    return sum

max_value=0
for i in permutations(array,n):
    max_value=max(max_value,calculate_num(i))

print(max_value)