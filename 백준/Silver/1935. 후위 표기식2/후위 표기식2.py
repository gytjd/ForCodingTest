n = int(input())
context = input()

put = [0]*n
for i in range(n):
    put[i] = int(input())

stack = list()
for i in range(len(context)):

    if context[i] == '*' or context[i] == '+' or context[i] == '/' or context[i] == '-':
        op2 = stack.pop()
        op1 = stack.pop()

        if context[i] == '*':
            stack.append(op1 * op2)
        elif context[i] == '+':
            stack.append(op1 + op2)
        elif context[i] == '/':
            stack.append(op1 / op2)
        else:
            stack.append(op1 - op2)
    else:
        stack.append(put[ord(context[i]) - ord('A')])

print('%.2f' % stack.pop())
