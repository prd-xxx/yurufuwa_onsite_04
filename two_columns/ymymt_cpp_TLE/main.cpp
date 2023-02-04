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


int main() {
	ll T;
	cin >>T;
	rep(t,T){
		ll A, B;
		cin >> A >> B;

		ll now = 1;


		rep(i, A) {
			ll x = 0;
			ll y = i;
			
			ll cnt = 0;
			while (1) {
				cnt++;
				if (y < B) {
					x = 1 - x;
				}
				if (x == 0) {
					y = A - 1 - y;
				}
				else {
					y = B - 1 - y;
				}

				if (x == 0 && y == i) {
					break;
				}
			}

			now = lcm(now, cnt);
			now = now % 998244353; //意味はないが一応

		}
		cout << now << endl;
	}
}