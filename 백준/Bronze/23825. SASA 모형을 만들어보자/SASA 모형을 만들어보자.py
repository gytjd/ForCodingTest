import sys

n,m=map(int,sys.stdin.readline().split())

if n<2 or m<2:
    print(0)
else:
    temp=min(n,m)
    print(temp//2)
    