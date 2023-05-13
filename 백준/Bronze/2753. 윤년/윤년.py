a=int(input())

def is_leaf(a):
    if a%4==0:
        if a%100==0:
            if a%400==0:
                return 1
            return 0
        return 1
    return 0


print(is_leaf(a))
