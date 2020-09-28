def power(number, expo, mod):
    value = 1

    number= number % mod

    while expo > 0:
        if expo&1:
            value = (value*number) % mod

        expo = expo >> 1
        number = (number**2) % mod

    return value

def inverse(N, mod):
    return power(N, mod-2, mod)

def combinations(N, R, mod, factorials):
    if R == 0:
        return 1

    return (factorials[N] * inverse(factorials[R], mod) % mod * inverse(factorials[N - R], mod) % mod) % mod

def solve(N, frequency_of_card, mod):
    remaining = N - frequency_of_card[max_value]
    result_combinations = power(2, remaining, mod)

    min_req = frequency_of_card[max_value] // 2 + 1
    combinations_cards = 0

    factorials = [0]*(N+1)
    factorials[0] = 1

    for i in range(1, N+1):
        factorials[i] = (factorials[i - 1] * i) % mod

    for i in range(min_req, frequency_of_card[max_value]+1):
        combi = combinations(frequency_of_card[max_value], i, mod, factorials)
        combinations_cards = (combinations_cards + combi) % mod

    result_combinations = (result_combinations * combinations_cards) % mod
    result_combinations = (result_combinations * 2) % mod

    print(result_combinations)


t = int(input())
mod = 1000000007

for test in range(t):
    N = int(input())

    max_value = -1000000000000
    frequency_of_card = {}

    card_numbers= [int(temp) for temp in input().split()]

    for i in range(N):
        frequency_of_card[card_numbers[i]] = 0

    for i in range(N):
        frequency_of_card[card_numbers[i]] += 1
        max_value = max(max_value, card_numbers[i])

    solve(N, frequency_of_card, mod)
