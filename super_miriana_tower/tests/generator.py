#!/usr/bin/env python3

import random
MAX = 679_891_637_638_612_258
testcases = [3, 4, 13, MAX, 1] #samples 

#small cases
for n in range(2,22):
    if n not in testcases:
        testcases.append(n)

fib = [1,2]
while 1:
    f = fib[-2] + fib[-1]
    if f >= MAX: break
    fib.append(f)
assert f == MAX

#fibonacci cases
for f in random.sample(fib, 10):
    if f not in testcases:
        testcases.append(f)

#near fibonacci cases
for f in random.sample(fib, 10):
    n = f + random.choice([-2, -1, 1, 2])
    if n not in testcases:
        testcases.append(n)

#random cases
for _ in range(10):
    n = random.randint(22,MAX)
    if n not in testcases:
        testcases.append(n)

for i,n in enumerate(testcases):
    with open('input_{:02d}.in'.format(i), 'w') as fout:
        fout.write(str(n) + '\n')
