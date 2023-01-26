#!/usr/bin/env python3

N = int(input())
A = list(map(int,input().split()))

assert 2 <= N <= 200000
assert all(0<=a<=2 for a in A)