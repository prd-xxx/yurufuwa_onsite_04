#!/usr/bin/python3

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
            res = (A * B) % mod
    else:
        res = 2 * (2 * q + 1)
        if r != 0:
            res *= 2 * q + 3
        res %= mod
    return res


T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    ans = two_columns(A, B)
    print(ans)
