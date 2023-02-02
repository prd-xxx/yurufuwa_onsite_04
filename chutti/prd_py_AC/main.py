#!/usr/bin/env python3

N = int(input())
S = input()

if '1' in S:
    print(-1)
    exit()

ans = S.count('4') + S.count('9')
S = S.replace('4','2').replace('9','3')

#22...5
five = False
for c in S[::-1]:
    if c=='5':
        five = True
    elif five and c=='2':
        ans += 1
    else:
        five = False

#33...6
six = False
for c in S[::-1]:
    if c=='6':
        six = True
    elif six and c=='3':
        ans += 1
    else:
        six = False

print(ans)