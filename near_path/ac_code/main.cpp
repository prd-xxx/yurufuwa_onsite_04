#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
ll dp[2010][2010][2],mod = 998244353;
string s[2010];
int main(){
    int i,j,k,h,w;
    cin >> h >> w;
    for(i=0;i<h;i++) cin >> s[i];
    dp[0][0][0] = 1; //最初は右に進んでいた扱い
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]=='#') continue;
            if(i){
                for(k=0;k<2;k++) (dp[i][j][1] += dp[i - 1][j][k]) %= mod;
            }
            if(j){
                (dp[i][j][0] += dp[i][j - 1][0]) %= mod;
                if(i && s[i - 1][j]=='#') (dp[i][j][0] += dp[i][j - 1][1]) %= mod;
            }
        }
    }
    ll ans = (dp[h - 1][w - 1][0] + dp[h - 1][w - 1][1])%mod;
    cout << ans << "\n";
}