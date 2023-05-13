import sys

n,m=map(int,sys.stdin.readline().split())
array=list(map(int,sys.stdin.readline().split()))

for i in array:
    print(i-(n*m),end=" ")