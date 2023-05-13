
n = input()
array = list()

res=0
for i in range(len(n)):
    array.append(n[i])
    res+=int(n[i])

if '0' not in array:
    print('-1')
else:
    if res%3==0:
        array.sort(reverse=True)
        for i in range(len(array)):
            print(array[i],end="")
    else:
        print('-1')




