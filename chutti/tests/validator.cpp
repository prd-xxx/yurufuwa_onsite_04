#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 2, MAX_N = 200000;
const char MIN_C = '1', MAX_C = '9';

int main() {
    registerValidation();
    int n = inf.readInt(MIN_N,MAX_N);
    inf.readEoln();
    string s = inf.readString();
    //inf.readEoln(); readStringで読んだときはいらないっぽい
    inf.readEof();
    assert(s.size()==n);
    for(int i=0;i<n;i++) {
        assert(MIN_C <= s[i] && s[i] <= MAX_C);
    }
}