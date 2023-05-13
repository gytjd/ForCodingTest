import sys
from itertools import combinations

n = int(input())
array = [i for i in range(1, n + 1)]

result = list()

for _ in range(n):
    result.append(list(map(int, sys.stdin.readline().split())))

sum = 1000

for i in range(1, n // 2 + 1):
    tempA = list(combinations(array, i))
    tempB = list(combinations(array, n - i))
    tempB.sort(reverse=True)

    for j in range(len(tempA)):

        startSum = 0
        linkSum = 0

        for startTempA in tempA[j]:
            for startTempB in tempA[j]:
                if startTempA != startTempB:
                    startSum += result[startTempA - 1][startTempB - 1]

        for linkTempA in tempB[j]:
            for linkTempB in tempB[j]:
                if linkTempA != linkTempB:
                    linkSum += result[linkTempA - 1][linkTempB - 1]

        if sum > abs(startSum - linkSum):
            sum = abs(startSum - linkSum)

print(sum)
