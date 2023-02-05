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

//高々素数は2,3,5
ll lm(set<ll> st) {

	ll ret = 1;

	vector<ll> v = { 2,3,5 };
	for (ll p : v) {
		ll mx = 0;
		set<ll> nst;
		for (ll x : st) {
			ll cnt = 0;
			while (x % p == 0) {
				x /= p;
				cnt++;
			}
			nst.insert(x);
			mx = max(mx, cnt);
		}
		rep(i, mx)ret *= p;
		st = nst;
	}

	for (ll x : st) {
		ret = ret * x % 998244353;
	}
	return ret;
}

ll A, B, C;

// 2*C >= B
ll solveAC() {

	auto ishalf = [&](ll cur, ll nxt) {
		return false;
	};

	set<ll> st;

	// BB
	if (2 * C >= B + 2)st.insert(2);

	// B < x < A
	vector<ll> lis;
	lis.push_back(B);
	rep(i, 2) {
		ll x = ((B / (A - C)) + i) * (A - C);
		if (B < x && x < A)lis.push_back(x);
		ll y = x + (A - B);
		if (B < y && y < A)lis.push_back(y);
	}
	lis.push_back(A);
	rep(i, lis.size() - 1) {
		ll val = 2 * (lis[i] / (A - C)) + 1 + ((lis[i] % (A - C)) >= (A - B));
		st.insert(ishalf(lis[i], lis[i+1]) ? val : val * 2);
	}

	// C < x < B;
	lis.clear();
	lis.push_back(C);
	rep(i, 2) {
		ll x = ((C / (A - C)) + i) * (A - C);
		if (C < x && x < B)lis.push_back(x);
		ll y = x + (A - B);
		if (C < y && y < B)lis.push_back(y);
	}
	lis.push_back(B);
	rep(i, lis.size() - 1) {
		ll val = 2 * (lis[i] / (A - C)) + 2 + ((lis[i] % (A - C)) >= (A - B));
		st.insert(ishalf(lis[i], lis[i + 1]) ? val : val * 2);
	}
	return lm(st);
}


// B+C>A>2*C
// このときとくにC>1
ll solveAB1() {
	// Cを通るもの
	set<ll> st;
	if (C > (B + C - A) * 2) {
		st.insert(C - (B + C - A) * 2 > 1 ? 6 : 3);
	}
	if (C < (B + C - A) * 2) {
		st.insert((B + C - A) * 2 - C > 1 ? 10 : 5);
	}
	st.insert(8);

	// 残りの部分
	ll X = A * 2 - C * 2 - B;
	ll Y = A - C * 2;

	if (X - Y == 1) {
		st.insert(X+Y);
	}
	else if (X - Y == 2 && X % 2 == 1) {
		st.insert(X);
		st.insert(Y);
	}
	else {
		ll Q = Y / (X - Y);
		st.insert(2 * (2 * Q + 1));
		if (Y % (X - Y) != 0) {
			st.insert(2 * (2 * Q + 3));
		}
	}
	return lm(st);
}

// B + C <= A
ll solveAB2() {
	auto ishalf = [&](ll cur, ll nxt) {
		return false;
	};

	set<ll> st;

	// Cを通るもの
	st.insert(C > 1 ? 6 : 3);

	vector<ll> lis;
	// B < x < A-C
	if (B < A - C) {
		lis.push_back(B);
		rep(i, 3) {
			ll x = ((B / (A - B)) - 1 + i) * (A - B) + C;
			if (B < x && x < A - C)lis.push_back(x);
			ll y = x + (A - C - B);
			if (B < y && y < A - C)lis.push_back(y);
		}
		lis.push_back(A - C);
		rep(i, lis.size() - 1) {
			ll val = 2 * ((lis[i] - C) / (A - B)) + 1 + (((lis[i] - C) % (A - B)) >= (A - C - B));
			st.insert(ishalf(lis[i], lis[i + 1]) ? val : val * 2);
		}
	}

	// max(C, B - C) < x < B
	lis.clear();
	ll Z = max(C, B - C);
	lis.push_back(Z);
	rep(i, 3) {
		ll x = ((Z / (A - B)) - 1 + i) * (A - B) + C;
		if (Z < x && x < B)lis.push_back(x);
		ll y = x + (A - C - B);
		if (Z < y && y < B)lis.push_back(y);
	}
	lis.push_back(B);
	rep(i, lis.size() - 1) {
		ll val = 2 * ((lis[i] - C) / (A - B)) + 2 + (((lis[i] - C) % (A - B)) >= (A - C - B));
		st.insert(ishalf(lis[i], lis[i + 1]) ? val : val * 2);
	}

	return lm(st);
}

void solve() {
	if (2 * C >= A) {
		ll ans =  solveAC();
		cout << ans << endl;
	}
	else if (B + C > A) {
		ll ans = solveAB1();
		cout << ans << endl;
	}
	else {
		ll ans = solveAB2();
		cout << ans << endl;
		
	}
	return;
}


int main() {
	ll T;
	cin >> T;
	rep(t, T) {
		cin >> A >> B >> C;
		solve();
	}
}