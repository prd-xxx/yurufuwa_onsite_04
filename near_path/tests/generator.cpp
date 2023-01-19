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
        ensure(S[0][0]=='.' && S[H - 1][W - 1]=='.');
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

const int minH = 2;
const int maxH = 2000;
const int minW = 2;
const int maxW = 2000;
// 最初にgridを全て#で作り、その中からランダムで道を作る関数
void setRndOneWay(vector<vector<char>> &mp){
    int H = mp.size(); int W = mp[0].size();
    int nowh = 0,noww = 0;
    while(nowh<H - 1 || noww<W - 1){
        mp[nowh][noww] = '.';
        int r = rnd.next(0,1);
        if(r==0){
            if(nowh<H - 1) nowh++;
            else noww++;
        }else{
            if(noww<W - 1) noww++;
            else nowh++;
        }
    }
    mp[nowh][noww] = '.';
}

//randomかつsmall
Input generateMinRnd(){
    const int mxH = 50;
    const int mxW = 50;
    int H = rnd.next(minH,mxH);
    int W = rnd.next(minW,mxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '#';
    }
    setRndOneWay(mp);
    int x = rnd.next(0,H*W - (H + W - 1));
    for(int i=0;i<x;i++){
        int x = rnd.next(0,H - 1);
        int y = rnd.next(0,W - 1);
        mp[x][y] = '.';
    }
    return Input(H,W,mp);
}

//random
Input generateRnd(){
    int H = rnd.next(minH,maxW);
    int W = rnd.next(minH,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '#';
    }
    setRndOneWay(mp);
    int x = rnd.next(0,H*W - (H + W - 1));
    for(int i=0;i<x;i++){
        int x = rnd.next(0,H - 1);
        int y = rnd.next(0,W - 1);
        mp[x][y] = '.';
    }
    return Input(H,W,mp);
}

//randomかつlarge
Input generateLargeRnd(){
    const int mnH = 1900;
    const int mnW = 1900;
    int H = rnd.next(mnH,maxH);
    int W = rnd.next(mnW,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '#';
    }
    setRndOneWay(mp);
    int x = rnd.next(0,H*W - (H + W - 1));
    for(int i=0;i<x;i++){
        int x = rnd.next(0,H - 1);
        int y = rnd.next(0,W - 1);
        mp[x][y] = '.';
    }
    return Input(H,W,mp);
}

//gridがlargeで#が少ない
Input generateSparceRnd(){
    const int mnH = 1900;
    const int mnW = 1900;
    int H = rnd.next(mnH,maxH);
    int W = rnd.next(mnW,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '#';
    }
    setRndOneWay(mp);
    int x = rnd.next(0,H*W - 100);
    for(int i=0;i<x;i++){
        int x = rnd.next(0,H - 1);
        int y = rnd.next(0,W - 1);
        mp[x][y] = '.';
    }
    return Input(H,W,mp);
}

//一本道
Input generateOnlyWay(){
    int H = rnd.next(minH,maxH);
    int W = rnd.next(minW,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '#';
    }
    setRndOneWay(mp);
    return Input(H,W,mp);
}

// [...][.#.][...]をたくさん置いてansを大きくしてみる？
Input generateAnsLarge(){
    const int mnH = 1900;
    const int mnW = 1900;
    int H = rnd.next(mnH,maxH);
    int W = rnd.next(mnW,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '.';
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i%3==1 && j%3==1) mp[i][j] = '#';
        }
    }
    mp[0][0] = mp[H - 1][W - 1] = '.';
    return Input(H,W,mp);
}

// [...][.#.][...]をたくさん置いてansを大きくしてみる？ + random
Input generateAnsLargeRnd(){
    const int mnH = 1900;
    const int mnW = 1900;
    int H = rnd.next(mnH,maxH);
    int W = rnd.next(mnW,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '.';
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i%3==1 && j%3==1) mp[i][j] = '#';
        }
    }
    //ここからrandomで#を減らす
    int num = 1000;
    for(int i=0;i<num;i++){
        int x = rnd.next(0,H - 1);
        int y = rnd.next(0,W - 1);
        mp[x][y] = '.';
    }
    mp[0][0] = mp[H - 1][W - 1] = '.';
    return Input(H,W,mp);
}

// 左下から右上へ
Input handmade1(){
    int H = rnd.next(1500,maxH),W = rnd.next(1500,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '.';
    }
    for(int i=1;i<W - 1 && (H - 1 - i)>0;i++){
        mp[H - 1 - i][i] = '#';
    }
    return Input(H,W,mp);
}

// 左上から右下へ
Input handmade2(){
    int H = rnd.next(1500,maxH),W = rnd.next(1500,maxW);
    vector<vector<char>> mp(H);
    for(int i=0;i<H;i++) mp[i].resize(W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) mp[i][j] = '.';
    }
    for(int i=1;i<H - 1 && i<W - 1;i++){
        mp[i][i] = '#';
    }
    return Input(H,W,mp);
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  generateTestCase(generateMinRnd, 5, "01_rnd");
  generateTestCase(generateRnd,5,"02_rnd");
  generateTestCase(generateLargeRnd,10,"03_rnd");
  generateTestCase(generateAnsLarge,5,"04_rnd");
  generateTestCase(generateAnsLargeRnd,10,"05_rnd");
  generateTestCase(generateSparceRnd,10,"06_rnd");
  generateTestCase(generateOnlyWay,2,"01_special");
  generateTestCase(handmade1,2,"01_hnd");
  generateTestCase(handmade2,2,"02_hnd");
}
