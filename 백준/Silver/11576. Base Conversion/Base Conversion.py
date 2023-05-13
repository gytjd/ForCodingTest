import sys

a,b=map(int,sys.stdin.readline().split())
n=int(input())
array=list(map(int,sys.stdin.readline().split()))

result=0
exp=len(array)-1
for i in array:
    result+=(a**exp)*i
    exp-=1

def to_exp(q):
    if q<=0:
        return
    else:
        to_exp(q//b)
        print(q%b,end=" ")

to_exp(result)