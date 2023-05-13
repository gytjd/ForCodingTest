n, b = input().split()

count=0
exp=len(n)-1
for i in n:
    if ord(i)>=65:
        count += ((int(b) ** exp) * (ord(i) - 55))
    else:
        count += ((int(b) ** exp) * (int(i)))
    exp-=1

print(count)