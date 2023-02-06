#!/usr/bin/python3

from math import gcd

mod = 998244353


def lcm(a, b):
    return a * b // gcd(a, b)


def test(A, B):
    operation_1 = [A - 1 - i for i in range(A)] + [A + B - 1 - i for i in range(B)]
    operation_2 = [i + A for i in range(B)] + [i for i in range(B, A)] + [i - A for i in range(A, A + B)]
    operation = [operation_2[operation_1[i]] for i in range(A + B)]

    res = 1
    period = [0] * (A + B)
    for i in range(A + B):
        if period[i]:
            continue
        loop = [i]
        cur = operation[i]
        while cur != loop[0]:
            loop.append(cur)
            cur = operation[cur]
        len_loop = len(loop)
        for l in loop:
            period[l] = len_loop
        res = lcm(res, len_loop)
    return res % mod


T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    ans = test(A, B)
    print(ans)
