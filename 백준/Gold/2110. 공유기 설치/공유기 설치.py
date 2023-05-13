import sys

n,m=map(int,sys.stdin.readline().split())
array=list()

for _ in range(n):
    array.append(int(sys.stdin.readline()))
array.sort()

start=1
end=array[-1]-array[0]

result=0

while start<=end:
    mid=(start+end)//2
    count=1
    startPos = array[0]

    for i in array:
        if i>=startPos+mid:
            count+=1
            startPos=i

    if count<m:
        end = mid - 1
    elif count>=m:
        result = mid
        start = mid + 1

print(result)


