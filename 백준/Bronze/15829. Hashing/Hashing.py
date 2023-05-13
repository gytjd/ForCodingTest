n=int(input())
context=input()

sum=0
for i in range(n):
    sum+=(ord(context[i])-96)*pow(31,i)

print(sum)