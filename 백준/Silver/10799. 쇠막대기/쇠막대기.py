
array=list(input().replace("()","*"))

count=0

stack=list()

for i in range(len(array)):
    if array[i]=="(" :
        stack.append(array[i])
    elif array[i]==")":
        count+=1

        open_ch=stack.pop()

        while open_ch!='(':
            open_ch=stack.pop()

    elif array[i]=="*":
        count+=len(stack)

print(count)