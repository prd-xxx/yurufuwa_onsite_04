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

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll id;
	ll fr;
	ll to;
	ll d;
};

/*
using mint = modint;

typedef vector<ll> vll;
typedef vector <vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

vmint f, finv, inv;

void cominit(ll N) {
	ll MOD = modint::mod();//デフォルトが998244353に注意

	f.assign(N + 1, 1);
	finv.assign(N + 1, 1);
	inv.assign(N + 1, 1);
	inv[1] = 1;

	repn(i, N) {
		f[i] = f[i - 1] * i;
		if (i > 1)inv[i] = -inv[MOD % i] * (MOD / i);
		finv[i] = finv[i - 1] * inv[i];
	}
}

mint com(ll a, ll b) {
	if (a < 0 || b < 0 || a < b) { return 0; }
	return f[a] * finv[b] * finv[a - b];
}

ll lower_bound_index(vll v, ll x) {
	auto itr = lower_bound(v.begin(), v.end(), x);
	return distance(v.begin(), itr);
}
*/


/////////////////////////////////////

int main() {
	int N;
	string S;
	cin >> N >> S;
	rep(i, N) {
		if (S[i] == '1') {
			cout << -1 << endl;
			return 0;
		}
	}

	ll ans = 0;
	rep(i, N) {
		if (S[i] == '4') {
			ans++;
			S[i] = '2';
		}
		if (S[i] == '9') {
			ans++;
			S[i] = '3';
		}
	}

	char state = '0';
	for (ll i = N - 1; i >= 0; i--) {
		if (S[i] == '6') {
			state = '3';
		}
		else if (S[i] == '5') {
			state = '2';
		}
		else if (S[i] == state) {
			ans++;
		}
		else {
			state = '0';
		}
	}
	cout << ans << endl;

}
