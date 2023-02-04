#!/usr/bin/env python3

N = int(input())
S = input()

if '1' in S:
    print(-1)
    exit()

S = list(S)
ans = 0
for i in reversed(range(N)):
    if S[i] == '4':
        ans += 1
        S[i] = '2'
    if S[i] == '9':
        ans += 1
        S[i] = '3'
    if i+1 < N:
        for s,t in (('25','5'),('36','6'),('49','7'),('64','8')):
            if ''.join(S[i:i+2]) == s:
                ans += 1
                S[i] = t
                break
print(ans)