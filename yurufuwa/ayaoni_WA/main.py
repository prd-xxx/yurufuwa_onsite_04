#!/usr/bin/python3

from collections import defaultdict

S = input()
count = defaultdict(int)
for s in S:
    count[s] += 1

if count['u'] >= 3 and count['a'] >= 1:
    print('Yes')
else:
    print('No')
