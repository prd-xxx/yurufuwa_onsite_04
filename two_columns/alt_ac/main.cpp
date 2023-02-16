#include <iostream>

using namespace std;
typedef long long ll;
ll mod = 998244353;
ll gcd(ll a,ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(a%b,b);
}

ll lcm(ll x,ll y){return x*y/gcd(x,y);}
ll solve(ll x,ll d,ll a,ll b){
    if(x<d){
        ll y = (x>=2) ? 2*(a + b) : (a + b);
        ll z = (x<d - 1) ? 2*b : b;
        return lcm(y,z);
    }
    if(x==d){
        return (x>=2) ? 2*(a + b) : (a + b);
    }
    ll k = (x - 1)/d;
    return solve(x - k*d,d,a,k*a + b);
}

ll a[2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t){
        t--;
        cin >> a[0] >> a[1];
        ll x = a[1], d = a[0] - a[1];
        ll ans = solve(x,d,2,1)%mod;
        cout << ans << "\n";
    }
}