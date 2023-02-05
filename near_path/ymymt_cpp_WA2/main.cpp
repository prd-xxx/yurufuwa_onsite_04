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

struct dsu {
public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
private:
    int _n;
    std::vector<int> parent_or_size;
};

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

    dsu ds(N * M);

    auto v = [&](ll i, ll j) {
        return i * M + j;
    };

    rep(i, N - 1)rep(j, M - 1) {
        if (C[i][j] == 1 && C[i][j + 1] == 1 && C[i + 1][j] == 1 && C[i + 1][j + 1] == 1) {
            ds.merge(v(i, j), v(i + 1, j));
            ds.merge(v(i, j), v(i, j + 1));
            ds.merge(v(i, j), v(i + 1, j + 1));
        }
    }

    vector<vector<int>> lis = ds.groups();
    sort(lis.begin(), lis.end());

    ll L = lis.size();
    vector<int> gr(N* M);
    rep(k, L)for (ll x : lis[k])gr[x] = k;

    vector<set<ll>> g(L);
    rep(i, N)rep(j, M) {
        if (i < N - 1 && C[i][j] == 1 && C[i + 1][j] == 1) {
            g[gr[v(i, j)]].insert(gr[v(i + 1, j)]);
        }
        if (j < M - 1 && C[i][j] == 1 && C[i][j + 1] == 1) {
            g[gr[v(i, j)]].insert(gr[v(i, j + 1)]);
        }
    }
    rep(i, L) {
        if (g[i].count(i)) {
            g[i].erase(i);
        }
    }

    vector<ll> in(L);
    rep(i, L)for (ll x : g[i]) {
        in[x]++;
    }

    queue<ll> q;
    vector<ll> dp(L);
    rep(x, L) {
        if (in[x] == 0)q.push(x);
    } 
    dp[gr[0]] = 1;

    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        for (ll y : g[x]) {
            //cout << x <<" " << y << endl;
            dp[y] += dp[x];
            in[y]--;
            if (in[y] == 0)q.push(y);
        }
    }
    /*
    rep(i, L) {
        if(dp[i]>0)cout << i << " " <<lis[i][0] / M << " " << lis[i][0] % M << " " << dp[i] << endl;
    }
    */
    cout << dp[gr[v(N - 1, M - 1)]] << endl;
}