import sys

n,m=map(int,sys.stdin.readline().split())

def factorial(num):
    result=1
    for i in range(1,num+1):
        result*=i
    return result

print((factorial(n+m-1)//(factorial(m-1)*factorial(n)))%1000000000)
