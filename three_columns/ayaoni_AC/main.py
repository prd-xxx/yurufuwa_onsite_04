#!/usr/bin/python3

from math import gcd


def lcm(x, y):
    return x * y // gcd(x, y)


mod = 998244353


def two_columns(A, B):
    d = A - B
    q, r = divmod(B, d)
    if d == 1:
        res = A + B
    elif d == 2:
        if A % 2 == 0:
            res = A + B
        else:
            res = A * B
    else:
        res = 2 * (2 * q + 1)
        if r != 0:
            res *= 2 * q + 3
    return res % mod


def three_columns(A, B, C):
    if B < 2 * C:
        d = A - C
        q, r = divmod(C, d)
        if r <= A - B:
            res = 2
            if A - B - r > B - C:
                res *= 2 * q + 1
            if A - B - r > 0:
                res *= 2 * q + 2
            if r > 0 or (B - C) > A - B - r:
                res *= 2 * q + 3
        else:
            res = 2 * (2 * q + 3) * (2 * q + 4)
            if A - B < r - (A - B):
                res *= 2 * q + 5
    elif C >= A - B:
        res = 2 if C >= 2 else 1
        if A - B > C - (A - B):
            res *= 3
        if C - (A - B) > 0:
            res *= 4
        if A - B < C - (A - B):
            res *= 5
        res = lcm(res, two_columns(B - 2 * (C - (A - B)), A - 2 * C))
    else:
        d = A - B
        q, r = divmod(B - C, d)
        if r == 0:
            res = (1 if (d == 2 and A % 2 == 1) else 2) * (2 * q + 1)
        else:
            s = (A - 1 - (r - 1)) % d
            t = (A - 1) % d
            res = 2
            if s <= t < d - 1 or r < s:
                res *= 2 * q + 1
            if s != 0:
                res *= 2 * q + 2
            if s < r or t < s:
                res *= 2 * q + 3
        res = lcm(res, 6 if C >= 2 else 3)
    return res % mod


T = int(input())
for _ in range(T):
    A, B, C = map(int, input().split())
    ans = three_columns(A, B, C)
    print(ans)
