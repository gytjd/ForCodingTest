import sys

n,m=map(int,sys.stdin.readline().split())
first=set()
second=set()

for _ in range(n):
    first.update(input().split())
for _ in range(m):
    second.update(input().split())

result=set(first&second)
result=list(result)
result.sort()

print(len(result))
for i in result:
    print(i)