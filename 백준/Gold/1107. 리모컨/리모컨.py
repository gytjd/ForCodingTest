import sys

channel=int(sys.stdin.readline())
n=int(sys.stdin.readline())
brokenChannel=list()

if n!=0:
    brokenChannel=list(map(int,sys.stdin.readline().split()))


def is_check(temp):
    for i in str(temp):
        if int(i) in brokenChannel:
            return 0
    return 1

result=abs(channel-100)


for i in range(0,1000001):
    if is_check(i)==1:
        result=min((len(str(i))+abs(channel-i),result))


print(result)

