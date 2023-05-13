context=input()
array=list()

for i in range(len(context)):
    array.append(context[i:len(context)])

array.sort()

for i in array:
    print(i)