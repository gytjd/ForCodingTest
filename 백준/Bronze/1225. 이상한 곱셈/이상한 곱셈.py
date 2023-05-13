import sys

n,m=map(int,sys.stdin.readline().split())

result=0

for i in str(n):
    for j in str(m):
        result+=int(i)*int(j)
print(result)