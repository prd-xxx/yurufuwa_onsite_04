#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
#include<cassert>
#include<random>
#include<list>
using namespace std;

#include <fstream> 
#include<random>
#include "testlib.h"

using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)


struct Input {
    int T;
    vector<int> A;
    vector<int> B;
    Input(int T, vector<int> A, vector<int> B)
        : T(T), A(A), B(B) {
    }
    void print(const string fileName) {
        ofstream fout(fileName);
        fout << T << "\n";
        rep(t,T) {
            fout << A[t] << " " << B[t] << "\n";
        }
        fout.close();
    }
};

void incrementId(string& s) {
    if (s[1] == '9') {
        s[0]++;
        s[1] = '0';
    }
    else
        s[1]++;
}

template <class GenerateRule>
void generateTestCase(const GenerateRule& g, const int NumOfCases, const string caseName) {
    string id = "00";
    for (int i = 0; i < NumOfCases; i++) {
        Input input = g();
        string filename = caseName + "_" + id + ".in";
        input.print(filename);
        incrementId(id);
    }
}

Input generateRndomTestCase() {
    std::random_device rnd;
    int T = 20000;
    vector<int> A,B;
    int mx = 10000000;
    rep(t,T){
        while(1){
            int x = abs((int)rnd())%mx+1;
            int y = abs((int)rnd())%mx+1;
             if(x>y){
                A.push_back(x);
                B.push_back(y);
                break;
            }
        }
    }
    return Input(T, A, B);
}

Input generateSmallDiffTestCase() {
    std::random_device rnd;
    int T = 20000;
    vector<int> A,B;
    int mx = 10000000;
    int dif = 100;
    rep(t,T){
        while(1){
            int x = abs((int)rnd())%mx+1;
            int y = x - abs((int)rnd())%dif - 1;
             if(y > 0){
                A.push_back(x);
                B.push_back(y);
                break;
            }
        }
    }
    return Input(T, A, B);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateRndomTestCase, 2, "rnd");
    generateTestCase(generateSmallDiffTestCase, 2, "difsml");
}