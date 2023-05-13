import sys

n=int(input())
context=""

for i in range(n):
    context+="IO"
context+="I"

m=int(input())
result_str=sys.stdin.readline().rstrip()

context_len=len(context)
result_len=len(result_str)

count=0
for i in range(result_len-context_len+1):
    if result_str[i]=="I":
        if context==result_str[i:i+context_len]:
            count+=1

print(count)




