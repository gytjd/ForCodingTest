n=int(input())
n=str(n)

array=list()

for i in range(len(n)):
    array.append(n[i])

array.sort(reverse=True)

for i in range(len(n)):
    print(array[i],end="")