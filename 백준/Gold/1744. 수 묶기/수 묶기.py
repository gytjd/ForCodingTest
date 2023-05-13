import sys

n=int(sys.stdin.readline())
tempMin=list()
tempPlu=list()

for _ in range(n):
    num=int(sys.stdin.readline())
    if num<=0:
        tempMin.append(num)
    else:
        tempPlu.append(num)


tempMin.sort()
tempPlu.sort(reverse=True)

tempMin_len=len(tempMin)
tempPlu_len=len(tempPlu)

tempMin_result=0
tempPlu_result=0

if tempMin_len%2==0: #짝수
    if tempMin_len==0:
        tempMin_result=0
    else:
        for i in range(0,tempMin_len,+2):
            tempMin_result+=tempMin[i]*tempMin[i+1]
else: #홀수
    if tempMin_len==1:
        tempMin_result+=tempMin[tempMin_len-1]
    else:
        for i in range(0, tempMin_len - 1, +2):
            tempMin_result += tempMin[i] * tempMin[i + 1]

        tempMin_result += tempMin[tempMin_len - 1]

if tempPlu_len%2==0: # 짝수
    if tempPlu_len==0:
        tempPlu_result=0
    else:
        for i in range(0,tempPlu_len,+2):
            if tempPlu[i]==1:
                tempPlu_result+=tempPlu[i]+tempPlu[i+1]
            else:
                if tempPlu[i+1]==1:
                    tempPlu_result+=tempPlu[i]+tempPlu[i+1]
                else:
                    tempPlu_result += tempPlu[i] * tempPlu[i + 1]

else: # 홀수

    if tempPlu_len==1:
        tempPlu_result+=tempPlu[tempPlu_len-1]
    else:
        for i in range(0, tempPlu_len - 1, +2):
            if tempPlu[i]==1:
                tempPlu_result+=tempPlu[i]+tempPlu[i+1]
            else:
                if tempPlu[i+1]==1:
                    tempPlu_result+=tempPlu[i]+tempPlu[i+1]
                else:
                    tempPlu_result += tempPlu[i] * tempPlu[i + 1]

        tempPlu_result += tempPlu[tempPlu_len - 1]


print(tempMin_result+tempPlu_result)