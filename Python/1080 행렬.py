import sys

n,m=map(int,sys.stdin.readline().split())
graphA=[list(map(int,sys.stdin.readline().rstrip()))for i in range(n)]
graphB=[list(map(int,sys.stdin.readline().rstrip()))for i in range(n)]


def display_graph():
    for i in graphA:
        print(i)
    print()

def change_graph(tempGraph,tempN,tempM):
    for i in range(tempN,tempN+3):
        for j in range(tempM,tempM+3):
            if tempGraph[i][j]==0:
                tempGraph[i][j]=1
            else:
                tempGraph[i][j]=0

def is_eqaul_graph(tempN,tempM):
    for i in range(tempN,tempN+3):
        for j in range(tempM,tempM+3):
            if graphA[i][j]!=graphB[i][j]:
                return 0
    return 1

def is_total_eqaul():
    for i in range(n):
        for j in range(m):
            if graphA[i][j]!=graphB[i][j]:
                return 0
    return 1

count=0
for i in range(n-2):
    for j in range(m-2):
        if graphA[i][j]!=graphB[i][j]:
            change_graph(graphA,i,j)
            count+=1

if is_total_eqaul()==1:
    print(count)
else:
    print(-1)



