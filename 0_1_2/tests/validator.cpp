#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 2, MAX_N = 200000;
const int MIN_A = 0, MAX_A = 2;

int main() {
    registerValidation();
    int n = inf.readInt(MIN_N,MAX_N);
    inf.readEoln();
    vector<int> a = inf.readInts(n,MIN_A,MAX_A);
    inf.readEoln();
    inf.readEof();
}