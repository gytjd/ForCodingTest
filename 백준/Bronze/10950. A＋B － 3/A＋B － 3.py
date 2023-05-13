n=int(input())
array=list()

for _ in range(n):
    a,b=map(int,input().split())
    array.append(a+b)

for i in range(n):
    print(array[i])