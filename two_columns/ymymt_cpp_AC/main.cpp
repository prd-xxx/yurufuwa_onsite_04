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


/////////////////////////////////////


int main() {
	ll T;
	cin >> T;
	rep(t,T){
    	ll A, B;
		cin >> A >> B;

		if (A - B == 1) {
			cout << smd(A,B) << endl;
			continue;
		}
		if (A - B == 2 && A%2==1) {
			cout << pmd(A,B) << endl;
			continue;
		}

		ll Q = B / (A - B);
		if (A % (A - B) == 0) {
			cout << pmd(2 * Q + 1,2) << endl;
		}
		else {
			cout << pmd((2 * Q + 1), (2 * Q + 3) * 2) << endl;
		}
	}

}