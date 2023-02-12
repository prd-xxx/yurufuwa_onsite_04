#!/usr/bin/env python3

from math import gcd

mod = 998244353


def lcm(a, b):
    return a * b // gcd(a, b)


def test(A, B, C):
    operation_1 = [A - 1 - i for i in range(A)] + [A + B - 1 - i for i in range(B)] + \
                  [A + B + C - 1 - i for i in range(C)]
    operation_2 = [i + (A + B) for i in range(C)] + [i + A for i in range(C, B)] + [i for i in range(B, A + C)] + \
                  [i - A for i in range(A + C, A + B)] + [i - (A + B) for i in range(A + B, A + B + C)]
    operation = [operation_2[operation_1[i]] for i in range(A + B + C)]

    res = 1
    period = [0] * (A + B + C)
    for i in range(A + B + C):
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
    A, B, C = map(int, input().split())
    ans = test(A, B, C)
    print(ans)
