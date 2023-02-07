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

a0 = None
a1 = None
a2 = None

if all(a == 0 for a in A):
    a0 = N*(N-1)//2
    a1 = 0
    a2 = 0
if all(a == 1 for a in A):
    a0 = 0
    a1 = N*(N-1)//2
    a2 = 0
if all(a == 2 for a in A):
    a0 = 0
    a1 = 0
    a2 = 0
if 0 not in A:
    a0 = 0
if 1 not in A:
    a1 = 0
if 2 not in A:
    a2 = 0

ans0 = N*(N-1)//2
ans1 = 0
ans2 = 0
for i, a in enumerate(A):
    if a != 0 and a0 is None:
        for j in range(i+1, N):
            if A[j] == 0:
                break
            ans0 -= 1
    if a == 1 and a1 is None:
        for j in range(i+1, N):
            if A[j] != 1:
                break
            ans1 += 1
    elif a == 2 and a2 is None:
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

if a0 is not None:
    ans0 = a0
if a1 is not None:
    ans1 = a1
if a2 is not None:
    ans2 = a2
print(ans0, ans1, ans2)