import sys

e,s,m=map(int,sys.stdin.readline().split())

tempE = 1
tempS = 1
tempM = 1
count=1

while True:

    if tempE==e and tempS==s and tempM==m:
        print(count)
        break
    else:
        tempE=(tempE+1)%16
        if tempE==0:
            tempE=1
        tempS=(tempS+1)%29
        if tempS==0:
            tempS=1
        tempM=(tempM+1)%20
        if tempM==0:
            tempM=1

        count+=1