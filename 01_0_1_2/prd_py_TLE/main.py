N = int(input())
A = list(map(int,input().split()))

ans = [0] * 3
for i in range(N-1):
    for j in range(i+1, N):
        arr = A[i:j+1]
        if 0 in arr:
            ans[0] += 1
        elif all(a==1 for a in arr):
            ans[1] += 1
        elif arr.count(2) == 1:
            ans[2] += 1
print(*ans)