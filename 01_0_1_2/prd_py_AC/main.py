N = int(input())
A = list(map(int,input().split()))

whole = N*(N-1)//2

tmp = 0
seq = 0
for a in A:
    if a > 0:
        seq += 1
    else:
        tmp += seq*(seq-1)//2
        seq = 0
tmp += seq*(seq-1)//2
ans0 = whole - tmp

ans1 = 0
seq = 0
for a in A:
    if a==1:
        seq += 1
    else:
        ans1 += seq*(seq-1)//2
        seq = 0
ans1 += seq*(seq-1)//2

ans2 = 0
for i,a in enumerate(A):
    if a!=2: continue
    j = i
    left = 1
    while j-1 >= 0 and A[j-1]==1:
        j -= 1
        left += 1
    j = i
    right = 1
    while j+1 < N and A[j+1]==1:
        j += 1
        right += 1
    ans2 += left * right - 1

print(ans0, ans1, ans2)