import sys

n,k=map(int,sys.stdin.readline().split())
money=list()

for _ in range(n):
    money.append(int(sys.stdin.readline()))

money.sort()

count=0
for i in range(n-1,-1,-1):
    if money[i]<=k:
        count+=k//money[i]
        k=k%money[i]
print(count)
