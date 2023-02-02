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
    int A;
    int B;
    Input(int A, int B)
        : A(A), B(B) {
    }
    void print(const string fileName) {
        ofstream fout(fileName);
        fout << A << "\n";
        fout << B << "\n";
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
    int mx = 1000; ///////////////////後でなおす！
    while(1){
    int A = abs((int)rnd())%mx+1;
    int B = abs((int)rnd())%mx+1;
    if(A<B){swap(A,B);}
    if(A>B){
        return Input(A, B);
    }
    }
}

Input generateDif1TestCase() {
    std::random_device rnd;
    int mx = 1000;
    int A = abs((int)rnd())%(mx-1)+2;
    return Input(A, A-1);
}

Input generateDif2TestCase() {
    std::random_device rnd;
    int mx = 1000;
    int A = abs((int)rnd())%(mx-2)+3;
    return Input(A, A-2);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    generateTestCase(generateRndomTestCase, 15, "rnd");
    generateTestCase(generateDif1TestCase, 15, "dif1");
    generateTestCase(generateDif2TestCase, 15, "dif2");
}