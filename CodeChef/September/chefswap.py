t = input()
t = int(t)

def solve(sum, n):
    required = sum // 2
    left = 1
    right = n

    half_sum_exist = 0

    # binary search
    while left < right:
        mid = left + (right - left) // 2
        currentSum = mid * (mid+1) // 2

        if currentSum == required:
            half_sum_exist = 1

        if currentSum > required:
            right = mid

        else:
            left = mid + 1

    result = n - left + 1

    if half_sum_exist == 1:
        left_pair = result
        right_pair = n - result

        result = result + (left_pair * (left_pair-1))//2
        result = result + (right_pair * (right_pair-1))//2

    print(result)


for i in range(t):
    n = input()
    n = int(n)

    sum = n * (n+1) // 2

    if sum%2 != 0:
        print(0)

    else:
        solve(sum, n)
        