import sys
from math import lcm
n=int(input())

for _ in range(n):
    a,b=map(int,sys.stdin.readline().split())
    print(lcm(a,b))