n=input()

stack=list()
tempStack=list()
for i in n:
    if i=="(":
        stack.append(i)
    else:
        if len(stack)==0:
            stack.append(i)
        else:
            if stack[-1]=="(":
                stack.pop()
            else:
                stack.append(i)

count=0
while stack:
    stack.pop()
    count+=1

print(count)
