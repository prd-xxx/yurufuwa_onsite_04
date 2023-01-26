#!/usr/bin/env python3

import random

testcases = []

testcases.append([0,1,1,2,2]) # sample 1

#minimum N=2
for i in range(3):
    for j in range(3):
        testcases.append([i,j])

SMALL_N = 100
LARGE_N = 200000
RANDOM_CASE_NUM = 5
for n in (SMALL_N, LARGE_N):
    all_0_case = [0] * n
    all_1_case = [1] * n
    all_2_case = [2] * n
    max_2_case = [1] * n; max_2_case[n//2] = 2
    testcases.extend([all_0_case, all_1_case, all_2_case, max_2_case])

    random_01_case = [random.randint(0,1) for _ in range(n)]
    random_12_case = [random.randint(1,2) for _ in range(n)]
    random_02_case = [random.randint(0,1)*2 for _ in range(n)]
    testcases.extend([random_01_case, random_12_case, random_02_case])

    for _ in range(RANDOM_CASE_NUM):
        random_012_case = [random.randint(0,2) for _ in range(n)]
        testcases.append(random_012_case)

for i,arr in enumerate(testcases):
    with open('input_{:02d}.in'.format(i), 'w') as fout:
        fout.write(str(len(arr)) + '\n')
        fout.write(' '.join(map(str, arr)) + '\n')