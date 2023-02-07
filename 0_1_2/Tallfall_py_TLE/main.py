#!/usr/bin/env python3

import sys
readline = sys.stdin.readline
def comp(A, x):
    res = []
    cnt = []
    for a in A:
        if a == x:
            res.append(cnt)
            cnt = []
        else:
            cnt.append(a)
    return res + [cnt]
N = int(readline())
A = list(map(int, readline().split()))
ans0 = N*(N-1)//2
ans1 = 0
ans2 = 0
for i, a in enumerate(A):
    if a != 0:
        for j in range(i+1, N):
            if A[j] == 0:
                break
            ans0 -= 1
    if a == 1:
        for j in range(i+1, N):
            if A[j] != 1:
                break
            ans1 += 1
    elif a == 2:
        for left in range(i-1, -1, -1):
            if A[left] != 1:
                break
            ans2 += 1
            for right in range(i+1, N):
                if A[right] != 1:
                    break
                ans2 += 1
        for right in range(i+1, N):
            if A[right] != 1:
                break
            ans2 += 1


print(ans0, ans1, ans2)