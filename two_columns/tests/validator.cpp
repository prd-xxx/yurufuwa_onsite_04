#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_T = 1, MAX_T = 200000;
const int MIN_A = 1, MAX_A = 1000000;

int main() {
    registerValidation();
    int T = inf.readInt(MIN_T,MAX_T);
    inf.readEoln();

    for (int i = 0; i < T; i++) {
        setTestCase(i + 1);
        vector<int> A = inf.readInts(2,MIN_A,MAX_A);
        inf.readEoln();
        assert(A[0] > A[1]);
    }

    inf.readEof();
}
