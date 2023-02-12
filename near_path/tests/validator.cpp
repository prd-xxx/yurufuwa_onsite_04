#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_H = 2, MAX_H = 2000;
const int MIN_W = 2, MAX_W = 2000;
string s[2010];
bool dp[2010][2010];
int main() {
    registerValidation();
    vector<int> inp = inf.readIntegers(2,2000);
    ensure(inp.size()==2);
    ensure(MIN_H<=inp[0] && inp[0]<=MAX_H);
    ensure(MIN_W<=inp[1] && inp[1]<=MAX_W);
    inf.readEoln();
    int H = inp[0],W = inp[1];
    for(int i=0;i<H;i++){
        string ss = inf.readToken();
        inf.readEoln();
        if(ss.size()!=W) exit(1);
        for(int j=0;j<W;j++) ensure(ss[j]=='.' || ss[j]=='#');
        s[i] = ss;
    }
    inf.readEof();
    ensure(s[0][0]=='.' && s[H - 1][W - 1]=='.');
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) dp[i][j] = false;
    }
    dp[0][0] = true;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j]=='#') continue;
            if(i) dp[i][j] |= dp[i - 1][j];
            if(j) dp[i][j] |= dp[i][j - 1];
        }
    }
    ensure(dp[H - 1][W - 1]);
}