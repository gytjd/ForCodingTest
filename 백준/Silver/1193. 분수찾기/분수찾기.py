n=int(input())

i=1
sum=0

for i in range(1,100000):

    sum += i

    if sum>=n:
        if i==1:
            print("1/1")
            break
        else:
            if i%2==0:
                num=sum-(i-1)
                start=1
                end=i

                while num!=n:
                    num+=1
                    start+=1
                    end-=1

                print(f"{start}/{end}")
                break


            else:
                num=sum-(i-1)
                start=i
                end=1

                while num!=n:
                    num+=1
                    start-=1
                    end+=1

                print(f"{start}/{end}")
                break
