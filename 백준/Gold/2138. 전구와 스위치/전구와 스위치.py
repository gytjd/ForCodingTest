import sys

n=int(sys.stdin.readline())
lightA=list(map(int,sys.stdin.readline().rstrip()))
lightB=list(map(int,sys.stdin.readline().rstrip()))

templight=list()
for i in lightA:
    templight.append(i)

def change_light(lightA,start):
    if start==0:
        for i in range(start+2):
            if lightA[i]==0:
                lightA[i]=1
            else:
                lightA[i]=0
    elif start==n-1:
        for i in range(start-1,start+1):
            if lightA[i]==0:
                lightA[i]=1
            else:
                lightA[i]=0
    else:
        for i in range(start-1,start+2):
            if lightA[i]==0:
                lightA[i]=1
            else:
                lightA[i]=0


count=0

for i in range(1,n):
    if lightA[i-1]!=lightB[i-1]:
        change_light(lightA,i)
        count+=1

if lightA==lightB:
    print(count)
else:
    count=0
    change_light(templight,0)
    count+=1

    for i in range(1,n):
        if templight[i-1]!=lightB[i-1]:
            change_light(templight,i)
            count+=1

    if templight==lightB:
        print(count)
    else:
        print(-1)


