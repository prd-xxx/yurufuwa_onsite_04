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
struct Input {
    int N;
    string S;
    Input(int N, string S)
        : N(N), S(S) {
    }
    void print(const string fileName) {
        ofstream fout(fileName);
        fout << N << "\n";
        fout << S << "\n";
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
    int N = 200000;
    string S;
    std::random_device rnd;
    for (int i = 0; i < N; ++i) {
        int rndm = rnd()%(N*2);
        if(rndm==0){S.push_back('0');}
        else {
            S.push_back(abs(rndm)%8+'2');
        }
    }
    return Input(N, S);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateRndomTestCase, 30, "rnd");
}