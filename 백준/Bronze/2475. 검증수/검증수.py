import sys

temp=list(map(int,sys.stdin.readline().split()))
result=list()
for i in temp:
    result.append(i*i)

print(sum(result)%10)