import  sys

n = int(input())

array = []
score = []

for i in range(n):
    weight,height=map(int,sys.stdin.readline().split())
    array.append((weight,height))

for i in range(n):
    count = 0
    for j in range(n):
        if array[i][0] < array[j][0] and array[i][1] < array[j][1]:
            count += 1

    score.append(count+1)

for i in score:
    print(i,end=" ")
