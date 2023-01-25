#!/usr/bin/env python3

N = int(input())
a,b = 1,2
x = 0
d = -1
while 1:
    if a <= N < b:
        print(x + (N-a)*d)
        exit()
    x += (b-a)*d
    a,b = b,a+b
    d *= -1