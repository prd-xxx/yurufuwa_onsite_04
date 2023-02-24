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

bool valid(int x, int y) {
    int mx=1000000;
    return mx>=x&&x>y&&y>=1;
}

Input generateRndomTestCase() {
    std::random_device rnd;
    int T = 200000;
    vector<int> A,B;
    int mx = 1000000;
    rep(t,T){
        while(1){
            int x = abs((int)rnd())%mx+1;
            int y = abs((int)rnd())%mx+1;
             if(valid(x,y)){
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
    int T = 200000;
    vector<int> A,B;
    int mx = 1000000;
    int dif = 20;
    rep(t,T){
        while(1){
            int x = abs((int)rnd())%mx+1;
            int y = x - abs((int)rnd())%dif - 1;
             if(valid(x,y)){
                A.push_back(x);
                B.push_back(y);
                break;
            }
        }
    }
    return Input(T, A, B);
}

Input generateBaisuTestCase() {
    std::random_device rnd;
    int T = 200000;
    vector<int> A,B;
    int mx= 1000;
    rep(t,T){
        while(1){
            int a = abs((int)rnd())%mx+1;
            int b = (abs((int)rnd())%mx+1);
            int x = a * b;
            int y = x - a;
             if(valid(x,y)){
                A.push_back(x);
                B.push_back(y);
                break;
            }
        }
    }
    return Input(T, A, B);
}

Input generateSample() {
    vector<int> A,B;
    A.push_back(2);
    B.push_back(1);
    
    A.push_back(5);
    B.push_back(4);
    return Input(2, A, B); 
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateSample, 1, "sample");
    generateTestCase(generateRndomTestCase, 1, "rnd");
    generateTestCase(generateSmallDiffTestCase, 1, "difsml");
    generateTestCase(generateBaisuTestCase, 1, "baisu");
}