from collections import Counter

while True:
    try:
        lowerCount = 0
        upperCount = 0
        digitCount = 0
        blankCount = 0

        context = input()
        result = Counter(context)

        for i in result:
            if 65 <= ord(i) < 92:
                upperCount += result[i]
            elif 97 <= ord(i) <= 123:
                lowerCount += result[i]
            elif i == ' ':
                blankCount += result[i]
            else:
                digitCount += result[i]

        print(lowerCount, upperCount, digitCount, blankCount)



    except:
        break
