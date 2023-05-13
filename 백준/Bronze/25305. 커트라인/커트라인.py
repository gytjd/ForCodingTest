import sys

n,m=map(int,sys.stdin.readline().split())
array=list(map(int,sys.stdin.readline().split()))

array.sort(reverse=True)
print(array[m-1])