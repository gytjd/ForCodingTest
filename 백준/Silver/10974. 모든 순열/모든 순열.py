n=int(input())

from itertools import permutations

array=[i for i in range(1,n+1)]
array=list(permutations(array,n))

for i in array:
    print(*i)