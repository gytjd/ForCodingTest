import sys

n=int(sys.stdin.readline())
m=int(sys.stdin.readline())

result=0
for _ in range(m):
    a,b=map(int,sys.stdin.readline().split())
    result+=a*b


if result==n:
    print("Yes")
else:
    print("No")