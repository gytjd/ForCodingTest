n=int(input())

def factorial(a):
    if a==0:
        return 1
    else:
        return a*factorial(a-1)

result=factorial(n)

count=0
div=10
for i in range(len(str(result))):
    if result%div!=0:
        break
    count+=1
    div*=10
print(count)