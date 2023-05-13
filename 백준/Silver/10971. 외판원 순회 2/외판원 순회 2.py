import sys
from itertools import permutations
INF=sys.maxsize

n=int(sys.stdin.readline())
graph=[list(map(int,sys.stdin.readline().split())) for i in range(n)]
array=[i for i in range(n)]

def calculate_num(temp):
    sum=0
    for i in range(n-1):

        if graph[temp[i]][temp[i+1]]==0:
            return 0
        else:
            sum += graph[temp[i]][temp[i + 1]]

    if graph[temp[-1]][temp[0]]==0:
        return 0
    else:
        sum += graph[temp[-1]][temp[0]]

    return sum

min_value=INF
for i in permutations(array,n):
    temp_result=calculate_num(i)

    if temp_result!=0:
        min_value = min(min_value,temp_result)

print(min_value)