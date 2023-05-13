import sys

sound=list(map(int,sys.stdin.readline().split()))
ascCount = 0
desCount = 0

for i in range(8):

    if sound[i]==i+1:
        ascCount+=1
    if sound[i]==8-i:
        desCount+=1


if ascCount==8:
    print("ascending")
elif desCount==8:
    print("descending")
else:
    print("mixed")
