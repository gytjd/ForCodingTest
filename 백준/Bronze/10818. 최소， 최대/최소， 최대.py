import sys

n=int(input())
array=list(map(int,sys.stdin.readline().split()))

print(min(array),max(array))