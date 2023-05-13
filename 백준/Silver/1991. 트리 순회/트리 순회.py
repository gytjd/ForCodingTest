import sys


class treeNode:
    def __init__(self,data,left,right):
        self.data=data
        self.left=left
        self.right=right


def inorder(root):
    if root.left != '.':
        inorder(tree[root.left])

    print(root.data, end="")

    if root.right != '.':
        inorder(tree[root.right])

def preorder(root):
    print(root.data, end="")

    if root.left != '.':
        preorder(tree[root.left])
    if root.right!= '.':
        preorder(tree[root.right])

def postorder(root):
    if root.left !='.':
        postorder(tree[root.left])

    if root.right!='.':
        postorder(tree[root.right])

    print(root.data, end="")

n=int(input())
tree={}


for _ in range(n):
    x,y,z=map(str,sys.stdin.readline().split())
    tree[x]=treeNode(data=x,left=y,right=z)

preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])
print()