import  sys

n=int(input())

for i in range(1,n+1):
    a,b=map(int,sys.stdin.readline().split())
    result=f'Case #{i}: {a} + {b} = {a+b}'
    print(result)