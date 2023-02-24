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

int MX = 1000000;
int SML = 30;


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

bool valid(int x, int y, int z) {
    return MX >= x && x > y && y > z && z >= 1;
}

int mxrnd() {
    random_device rnd;
    return abs((int)rnd())%MX+1;
}
int smlrnd() {
    random_device rnd;
    return abs((int)rnd())%SML+1;
}

void generateRndTestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    while(1){
        int x = mxrnd();
        int y = mxrnd();
        int z = mxrnd();
        if(valid(x,y,z)){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

void generateMMMTestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    while(1){
        int x = mxrnd();
        int y = x - smlrnd();
        int z = y - smlrnd();
        if(valid(x,y,z)){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

void generateMMSTestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    while(1){
        int x = mxrnd();
        int y = x - smlrnd();
        int z = smlrnd();
        if(valid(x,y,z)){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

void generateMSSTestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    while(1){
        int x = mxrnd();
        int y = smlrnd();
        int z = smlrnd();
        if(valid(x,y,z)){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

void generateSSSTestCase(vector<int>&A, vector<int>&B, vector<int>&C) {
    while(1){
        int x = smlrnd();
        int y = smlrnd();
        int z = smlrnd();
        if(valid(x,y,z)){
            A.push_back(x);
            B.push_back(y);
            C.push_back(z);
            return;
        }
    }
}

Input generateMultiTestCase() {
    std::random_device rnd;
    int T = 200000;
    vector<int> A,B,C;
    rep(t,T/5){
       generateRndTestCase(A, B, C);
       generateMMMTestCase(A, B, C);
       generateMMSTestCase(A, B, C);
       generateMSSTestCase(A, B, C);
       generateSSSTestCase(A, B, C);
    }
    return Input(T, A, B, C);
}

Input generateSample() {
    std::random_device rnd;
    int T = 2;
    vector<int> A,B,C;
    A = {3,5};
    B = {2,3};
    C = {1,2};
    return Input(T, A, B, C);
}


int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateMultiTestCase, 2, "rnd");
    generateTestCase(generateSample, 1, "sample");
}