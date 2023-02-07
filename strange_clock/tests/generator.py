#!/usr/bin/env python3

from random import sample
from math import floor
testcases = []
#1は最後に追加する
testcases.append([2, 3]) # sample 1
testcases.append([60, 3600]) # sample 2


SMALL_A = 5000
LARGE_A = 200000
RANDOM_CASE_NUM = 2
for a in (SMALL_A, LARGE_A):
    for s in (1, 103, 5040):
        allA = list(range(s, a+1, s))
        if s == 1:
            allA.remove(1)
        L = len(allA)
        if L > 5:
            testcases.append(sample(allA, L-5))
        if L > 10:
            testcases.append(sample(allA, L-10))
        for d in (0.0001, 0.001, 0.1, 0.3, 0.5, 0.8):
            l = floor(L*d)
            for _ in range(RANDOM_CASE_NUM):
                testcases.append(sample(allA, l))
testcases = [[1]+t for t in testcases if t] + [[1]]

for i,arr in enumerate(testcases):
    with open('input_{:02d}.in'.format(i), 'w') as fout:
        fout.write(str(len(arr)) + '\n')
        fout.write(' '.join(map(str, arr)) + '\n')