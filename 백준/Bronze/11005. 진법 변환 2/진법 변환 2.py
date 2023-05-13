import sys

n,b=map(int,sys.stdin.readline().split())

def to_bin(a):
    if a<=0:
        return
    else:
        to_bin(a//b)

        if a%b>=10:
            print(chr(55+(a%b)),end="")
        else:
            print(a % b,end="")

to_bin(n)