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

int MX = 10000000;
int SML = 20;


struct Input {
    int T;
    vector<int> A, B, C;
    Input(int T, vector<int> A, vector<int> B, vector<int> C)
        : T(T), A(A), B(B), C(C) {
    }
    void print(const string fileName) {
        ofstream fout(fileName);
        fout << T << "\n";
        rep(t,T) {
            fout << A[t] << " " << B[t] << " " << C[t] << "\n";
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

void generateRndTestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    int mx = MX;
    while(1){
        std::random_device rnd;
        int x = abs((int)rnd())%mx+1;
        int y = abs((int)rnd())%mx+1;
        int z = abs((int)rnd())%mx+1;
        if(x>y && y>z){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

void generateC1TestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    int mx = SML;
    while(1){
        std::random_device rnd;
        int x = abs((int)rnd())%mx+1;
        int y = abs((int)rnd())%mx+1;
        int z = 1;
        if(x>y && y>z){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

Input generateMultiTestCase() {
    std::random_device rnd;
    int T = 20000;
    vector<int> A,B,C;
    rep(t,T){
       generateRndTestCase(A, B, C);
    }
    return Input(T, A, B, C);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateMultiTestCase, 2, "rnd");
}