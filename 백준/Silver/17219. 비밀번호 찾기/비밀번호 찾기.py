import sys

n,m=map(int,sys.stdin.readline().split())

temp={}

for i in range(n):
    website,password=sys.stdin.readline().split()
    temp[website]=password

for _ in range(m):
    print(temp[sys.stdin.readline().rstrip()])