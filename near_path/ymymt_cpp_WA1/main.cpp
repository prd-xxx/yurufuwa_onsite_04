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
//#include<atcoder/all>
//using namespace atcoder;


#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e17;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll pmd(ll a, ll b) {
	return a * b % 998244353;
}


ll smd(ll a, ll b) {
	return (a + b) % 998244353;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

/////////////////////////////////////

ll mod = 998244353;

int main() {
	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> C(N, vector<ll>(M, 0));
	rep(i, N)rep(j, M) {
		char x;
		cin >> x;
		if (x == '.')C[i][j] = 1;
	}

	vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(M + 1, vector<ll>(2)));
	dp[0][1][0] = 1;

	repn(i, N)repn(j, M) {
		if (C[i - 1][j - 1] == 0)continue;
		dp[i][j][0] = dp[i][j - 1][0];
		if (i == 1 || C[i - 2][j - 1] == 0)dp[i][j][0] += dp[i][j-1][1];
        dp[i][j][0] %= mod;

		dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j][1];
		dp[i][j][1] %= mod;

		//cout << i << j << dp[i][j][0] << dp[i][j][1] << endl;
	}
	ll ans = (dp[N][M][0] + dp[N][M][1]); //最後のmodを入れるのを忘れる(generateAnsLargeで落ちてほしい)
	cout << ans << endl;
}