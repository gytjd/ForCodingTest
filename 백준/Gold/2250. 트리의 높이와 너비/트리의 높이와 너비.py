import sys
from collections import deque

result=[0 for i in range(10001)]

class treeNode():
    def __init__(self,data,left,right):
        self.data=data
        self.left=left
        self.right=right
        self.num=0
        self.depth=0

count_1=0
def inorder(root):
    global count_1
    if root.left!=-1:
        inorder(tree[root.left])

    count_1+=1
    result[count_1]=root.depth

    if root.right!=-1:
        inorder(tree[root.right])


def check_depth(root):
    queue=deque()

    root.depth=1
    queue.append(root)

    while queue:
        v=queue.popleft()

        if v.left != -1:
            tree[v.left].depth=v.depth+1
            queue.append(tree[v.left])

        if v.right != -1:
            tree[v.right].depth=v.depth+1
            queue.append(tree[v.right])

count=0
def max_node(root):
    global count

    count+=1

    if root.left!=-1:
        max_node(tree[root.left])
    if root.right!=-1:
        max_node(tree[root.right])

    return count

n=int(input())
tree={}
temp=list()
root=1

for i in range(n):
    x,y,z=map(int,sys.stdin.readline().split())
    temp.append((x,y,z))
    tree[x]=treeNode(x,y,z)


max_value=0
for i in range(len(temp)):
    temp_result=max_node(tree[temp[i][0]])
    count=0

    if temp_result>max_value:
        max_value=temp_result
        root=temp[i][0]


check_depth(tree[root])
inorder(tree[root])

result_len=max(result)
result_last=[0 for i in range(result_len+1)]

for i in range(1,result_len+1):
    for j in range(1, n + 1):
        if result[j]==i:
            break

    for k in range(n,0,-1):
        if result[k]==i:
            break

    result_ab=abs(j-k)
    result_last[i]=result_ab+1

print(result_last.index(max(result_last)),max(result_last))
