import sys

n,m,k=map(int,sys.stdin.readline().split())

if n//2<m:
    temp=n//2
    temp_result=m-(n//2)

    if temp_result>=k:
        print(temp)
    else:
        temp_k=k-temp_result
        print(temp-(((temp_k-1)//3)+1))
else:
    temp=m
    temp_result=n-(m*2)

    if temp_result>=k:
        print(temp)
    else:
        temp_k = k - temp_result
        print(temp - (((temp_k - 1) // 3) + 1))




