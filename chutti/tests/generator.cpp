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
void generateTestCase(const GenerateRule& g, vector<int> bunpu, const int NumOfCases, const string caseName) {
    string id = "00";
    for (int i = 0; i < NumOfCases; i++) {
        Input input = g(bunpu);
        string filename = caseName + "_" + id + ".in";
        input.print(filename);
        incrementId(id);
    }
}

Input generateRndomTestCase(vector<int> bunpu) {
    vector<int> rbunpu(10);
    rbunpu[0]=0;
    for (int i = 0; i < 9; i++) {
        rbunpu[i+1] = rbunpu[i] + bunpu[i];
    }
    int N = 200000;
    string S;
    std::random_device rnd;
    for (int i = 0; i < N; ++i) {
        int rndm = rnd()%(rbunpu.back());
        for (int j = 1; j < 10; j++) {
            if (rndm < rbunpu[j]) {
                S.push_back('0'+j);
                break;
            }
        }
    }
    return Input(N, S);
}

Input sample1(vector<int> bunpu) {
    return Input(3, "364");
}
Input sample2(vector<int> bunpu) {
    return Input(2, "81");
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateRndomTestCase, {0, 1, 1, 1, 1, 1, 1, 1, 1}, 10, "rnd");
    generateTestCase(generateRndomTestCase, {1, 100, 100, 100, 100, 100, 100, 100, 100}, 10, "rnd1");
    generateTestCase(generateRndomTestCase, {0, 1, 100, 1, 1, 5, 1, 1, 100}, 5, "rnd369");
    generateTestCase(generateRndomTestCase, {0, 100, 1, 100, 5, 1, 1, 1, 1}, 5, "rnd245");
    generateTestCase(generateRndomTestCase, {0, 0, 1, 1, 1, 1, 100, 100, 1}, 5, "rnd78");
    generateTestCase(sample1, {}, 1, "sample1");
    generateTestCase(sample2, {}, 1, "sample2");
}