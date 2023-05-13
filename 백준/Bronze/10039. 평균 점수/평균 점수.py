result=list()

for _ in range(5):
    temp=int(input())
    if temp<40:
        temp=40
    result.append(temp)


print(sum(result)//5)
