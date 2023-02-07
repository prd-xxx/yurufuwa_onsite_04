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
A012 = list(map(int, readline().split()))
ans0 = N*(N-1)//2
ans1 = 0
ans2 = 0
for a12 in comp(A012, 0):
    la12 = len(a12)
    ans0 -= la12*(la12-1)//2
    pla1 = None
    for a1 in comp(a12, 2):
        la1 = len(a1)
        ans1 += la1*(la1-1)//2
        if pla1 is not None:
            ans2 += (pla1+1)*(la1+1)-1
        pla1 = la1
print(ans0, ans1, ans2)