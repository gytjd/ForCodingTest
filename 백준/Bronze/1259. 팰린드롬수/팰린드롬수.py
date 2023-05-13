import sys

while True:
    temp=int(input())

    if temp==0:
        break

    temp=str(temp)
    temp_len=len(temp)
    for i in range(temp_len):
        if temp[i]!=temp[temp_len-i-1]:
            print("no")
            break
    else:
        print("yes")