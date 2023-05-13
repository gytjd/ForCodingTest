import sys

result=list(map(int,sys.stdin.readline().split()))

result.sort()

print(result[1])