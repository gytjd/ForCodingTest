import sys

n=int(sys.stdin.readline())
array=list(map(int,sys.stdin.readline().split()))

def is_prime(temp):
    for i in range(2,temp):
        if temp%i==0:
            return 1
    return 0

count=0
for i in array:
    if i==1:
        continue
    else:
        if is_prime(i) == 0:
            count += 1

print(count)
