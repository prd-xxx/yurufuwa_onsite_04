import random

testcases = []

testcases.append([0,1,1,2,2]) # sample 1

SMALL_SIZE = 100
random_small_case = []
for i in range(SMALL_SIZE):
    random_small_case.append(random.randint(0,2))
testcases.append(random_small_case)

for i,arr in enumerate(testcases):
    with open('input_{:02d}.in'.format(i), 'w') as fout:
        fout.write(str(len(arr)) + '\n')
        fout.write(' '.join(map(str, arr)) + '\n')