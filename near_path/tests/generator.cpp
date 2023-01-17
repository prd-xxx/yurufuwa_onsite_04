#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
struct Input {
    int H, W;
    vector<vector<char>> S;
    Input(int H, int W, vector<vector<char>> &S)
        : H(H), W(W), S(S) {
    }
    void print(const string fileName) {
        ofstream fout(fileName);
        fout << H << " " << W << "\n";
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++) {
                fout << S[i][j] << (j != W - 1 ? "" : "\n");
                ensure(S[i][j] == '.' || S[i][j] == '#');
            }
        }
        fout.close();
    }
};

void incrementId(string &s) {
    if (s[1] == '9') {
        s[0]++;
        s[1] = '0';
    } else
        s[1]++;
}

template <class GenerateRule>
void generateTestCase(const GenerateRule &g, const int NumOfCases, const string caseName) {
    string id = "00";
    for (int i = 0; i < NumOfCases; i++) {
        Input input = g();
        string filename = caseName + "_" + id + ".in";
        input.print(filename);
        incrementId(id);
    }
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
}
