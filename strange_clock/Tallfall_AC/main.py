#!/home/forcia/.pyenv/shims/python

import sys
readline = sys.stdin.readline

#https://judge.yosupo.jp/submission/35230
MOD = 998244353
def frac(limit):
    frac = [1]*limit
    for i in range(2,limit):
        frac[i] = i * frac[i-1]%MOD
    fraci = [None]*limit
    fraci[-1] = pow(frac[-1], MOD -2, MOD)
    for i in range(-2, -limit-1, -1):
        fraci[i] = fraci[i+1] * (limit + i + 1) % MOD
    return frac, fraci
frac, fraci = frac(1341398)
MOD = 998244353
pr = 3
LS = 20
class NTT:
    def __init__(self):
        self.N0 = 1<<LS
        omega = pow(pr, (MOD-1)//self.N0, MOD)
        omegainv = pow(omega, MOD-2, MOD)
        self.w = [0]*(self.N0//2)
        self.winv = [0]*(self.N0//2)
        self.w[0] = 1
        self.winv[0] = 1
        for i in range(1, self.N0//2):
            self.w[i] = (self.w[i-1]*omega)%MOD
            self.winv[i] = (self.winv[i-1]*omegainv)%MOD
        used = set()
        for i in range(self.N0//2):
            if i in used:
                continue
            j = 0
            for k in range(LS-1):
                j |= (i>>k&1) << (LS-2-k)
            used.add(j)
            self.w[i], self.w[j] = self.w[j], self.w[i]
            self.winv[i], self.winv[j] = self.winv[j], self.winv[i]
        
    def _fft(self, A):
        M = len(A)
        bn = 1
        hbs = M>>1
        while hbs:
            for j in range(hbs):
                A[j], A[j+hbs] = A[j] + A[j+hbs], A[j] - A[j+hbs]
                if A[j] > MOD:
                    A[j] -= MOD
                if A[j+hbs] < 0:
                    A[j+hbs] += MOD
            for bi in range(1, bn):
                wi = self.w[bi]
                for j in range(bi*hbs*2, bi*hbs*2+hbs):
                    A[j], A[j+hbs] = (A[j] + wi*A[j+hbs])%MOD, (A[j] - wi*A[j+hbs])%MOD
            bn <<= 1
            hbs >>= 1

    def _ifft(self, A):
        M = len(A)
        bn = M>>1
        hbs = 1
        while bn:
            for j in range(hbs):
                A[j], A[j+hbs] = A[j] + A[j+hbs], A[j] - A[j+hbs]
                if A[j] > MOD:
                    A[j] -= MOD
                if A[j+hbs] < 0:
                    A[j+hbs] += MOD
            for bi in range(1, bn):
                winvi = self.winv[bi]
                for j in range(bi*hbs*2, bi*hbs*2+hbs):
                    A[j], A[j+hbs] = (A[j] + A[j+hbs])%MOD, winvi*(A[j] - A[j+hbs])%MOD
            bn >>= 1
            hbs <<= 1
    
    def convolve(self, A, B):
        LA = len(A)
        LB = len(B)
        LC = LA+LB-1
        M = 1<<(LC-1).bit_length()
        A += [0]*(M-LA)
        B += [0]*(M-LB)
        self._fft(A)
        self._fft(B)
        C = [0]*M
        for i in range(M):
            C[i] = A[i]*B[i]%MOD
        self._ifft(C)
        minv = pow(M, MOD-2, MOD)
        for i in range(LC):
            C[i] = C[i]*minv%MOD
        return C[:LC]
        
    
    def inverse(self, A):
        LA = len(A)
        dep = (LA-1).bit_length()
        M = 1<<dep
        A += [0]*(M-LA)
        
        g = [pow(A[0], MOD-2, MOD)]
        for n in range(dep):
            dl = 1<<(n+1)
            f = A[:dl]
            fg = self.convolve(f, g[:])[:dl]
            fgg = self.convolve(fg, g[:])[:dl]
            ng = [None]*dl
            for i in range(dl//2):
                ng[i] = (2*g[i]-fgg[i])%MOD
            for i in range(dl//2, dl):
                ng[i] = MOD-fgg[i]
            g = ng[:]
        return g[:LA]
    
    def integral(self, A):
        A = [1] + [A[i]*fraci[i+2]%MOD for i in range(len(A))]


def t1(T):
    M = len(T) - 1
    prime = [1]*(M+1)
    prime[0] = None
    prime[1] = None
    for p in range(2, M+1):
        if prime[p]:
            for np in range(2*p, M+1, p):
                prime[np] = 0
            for t in range(M//p*p, 0, -p):
                T[t//p] += T[t]
    return T

def t2(T):
    M = len(T) - 1
    prime = [1]*(M+1)
    prime[0] = None
    prime[1] = None
    for p in range(2, M+1):
        if prime[p]:
            for np in range(2*p, M+1, p):
                prime[np] = 0
            for t in range(0, M+1, p):
                T[t//p] -= T[t]
    return T


def calc(table):
    table = [1 if t else 0 for t in t1(table)]
    table = [i*t for i, t in enumerate(t2(table))]
    return sum(table)

N = int(input())
A = list(map(int, input().split()))
mA = max(A)+1
table = [0]*mA
for a in A:
    table[a] = 1

T = NTT()
print(calc(T.convolve(table, table[::-1])[mA-1:]))
