n = int(input())

array = list()
temp=list()

for _ in range(n):
    array.append(input())

array.sort(key=lambda x: (len(x), x))

for i in array:
    if i in temp:
        continue
    else:
        temp.append(i)

for i in temp:
    print(i)