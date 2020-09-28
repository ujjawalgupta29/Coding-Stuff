def calculate_sum(n, k):
    if(k == 1):
        return (int)(n * (n + 1) / 2)

    if(k == 2)
        return (int)(((n*(n+1) / 2) * (2*n+1)) / 3)

    else 
        return (int)(pow(n * (n + 1) / 2, 2))

def findTwoGroups(n, k):
    sum = calculate_sum(n, k)
    taken = [0] * n

    gropu1sum = sum//2
    sum1=0
    sum2=0

    for i in range(n, 0, -1):

        if gropu1sum - i >=  0:
            taken[i] = 1
            gropu1sum -= pow(i,k)
            sum1 += pow(i, k)

        else:
            sum2 += pow(i, k)

    print(abs(sum1 - sum2))

    print(''.join(str(i) for i in taken))


k = input()
k = (int)k

t = input()
t = (int)t

for i in range(t):
    n = input()
    n = (int)n

    findTwoGroups(n, k)
