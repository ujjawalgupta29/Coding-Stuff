t = input()
t = (int)t

for i in range(t):
    n = input()
    n = (int)n
    dict = {}

    for j in range(n):
        number = (int)input()
        if number != 0:
            dict[number] = 1

    print(len(dict))
