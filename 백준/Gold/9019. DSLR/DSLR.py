import sys
from collections import deque
n=int(input())

def BFS_DSLR():

    while dslr_queue:
        value,command=dslr_queue.popleft()

        if value==end:
            print(command)
            break

        add_value=value*2%10000
        if visited[add_value]==0:
            dslr_queue.append((add_value, command + "D"))
            visited[add_value]=1

        if value==0:
            sub_value = 9999
        else:
            sub_value = value - 1

        if visited[sub_value]==0:
            dslr_queue.append((sub_value, command + "S"))
            visited[sub_value]=1

        leftValue=0
        if value>=1000:
            leftValue=((value%1000)*10)+(value//1000)
        elif value>=100:
            leftValue = ((value % 100) * 10) + ((value // 100)*1000)
        elif value>=10:
            leftValue = ((value % 10) * 10) + ((value // 10)*100)
        elif value>=1:
            leftValue=value*10


        if visited[leftValue]==0:
            dslr_queue.append((leftValue, command + "L"))
            visited[leftValue]=1

        rightValue=0
        if value>=1000:
            rightValue=((value//10)+((value%10)*1000))
        elif value>=100:
            rightValue = ((value // 10) + ((value % 10) * 1000))
        elif value>=10:
            rightValue = ((value // 10) + ((value % 10) * 1000))
        elif value>=1:
            rightValue = value*1000

        if visited[rightValue]==0:
            dslr_queue.append((rightValue, command + "R"))
            visited[rightValue]=1

for _ in range(n):
    start,end=map(int,sys.stdin.readline().split())
    visited=[0 for i in range(10001)]
    dslr_queue = deque()
    dslr_queue.append((start,""))

    BFS_DSLR()


