n = int(input())

array = list()

count=0

def hanoi_tower(n, from_pos, to_pos, temp):

    global count

    if n == 1:
        array.append(f"{from_pos} {to_pos}")
        count += 1
    else:
        hanoi_tower(n - 1, from_pos, temp, to_pos)
        array.append(f"{from_pos} {to_pos}")
        count += 1
        hanoi_tower(n - 1, temp, to_pos, from_pos)


hanoi_tower(n, 1, 3, 2)

print(count)
for i in range(len(array)):
    print(array[i])
