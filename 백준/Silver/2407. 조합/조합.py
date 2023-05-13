import sys

n,m=map(int,sys.stdin.readline().split())

def factorial(n):
    sum=1
    for i in range(1,n+1):
        sum*=i
    return sum

def combination(n,m):
    print(factorial(n)//(factorial(n-m)*factorial(m)))

combination(n,m)