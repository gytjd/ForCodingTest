context=input().split("-")

sum=0
temp=context[0].split("+")
for i in temp:
    sum+=int(i)

for i in range(1,len(context)):
    temp_sum=0
    for j in context[i].split("+"):
        temp_sum+=int(j)
    sum-=temp_sum
print(sum)