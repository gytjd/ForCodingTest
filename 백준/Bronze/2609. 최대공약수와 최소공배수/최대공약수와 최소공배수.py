import sys
from math import gcd
from math import lcm

A,B=map(int,sys.stdin.readline().split())

print(gcd(A,B))
print(lcm(A,B))