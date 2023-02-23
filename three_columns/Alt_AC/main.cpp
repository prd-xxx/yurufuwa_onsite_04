#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
ll mod = 998244353;
ll num2 = 0,num3 = 0,num5 = 0;
vector<ll> vs;
ll lcm(ll a,ll b){
    vs.push_back(a); vs.push_back(b);
    return 1;
}

ll calc_lcm(){
    ll ret = 1;
    set<ll> s;
    for(ll val:vs){
        ll x,y,z; x = y = z = 0;
        while(val%2==0) val /= 2, x++; 
        while(val%3==0) val /= 3, y++;
        while(val%5==0) val /= 5, z++;
        s.insert(val);
        num2 = max(num2,x); num3 = max(num3,y); num5 = max(num5,z);
    }
    for(ll x:s) (ret *= x) %= mod;
    for(int i=0;i<num2;i++) (ret *= 2) %= mod;
    for(int i=0;i<num3;i++) (ret *= 3) %= mod;
    for(int i=0;i<num5;i++) (ret *= 5) %= mod;
    return ret;
}

ll two_columns_solver(ll x,ll d,ll a,ll b){
    if(x<d){
        ll y = (x>=2) ? 2*(a + b) : (a + b);
        ll z = (x==d - 1) ? 2*b : b;
        return lcm(y,z);
    }
    if(x==d){
        return (x>=2) ? 2*(a + b) : (a + b);
    }
    ll k = (x - 1)/d;
    if(!k) exit(1);
    return two_columns_solver(x - k*d,d,a,k*a + b);
}

ll solve_pattern_A(vector<ll> &a,vector<ll> &b){
    if(a[0] + a[1]<=a[2]){
        ll x = -1;
        if(a[2] - a[0] - a[1]==0) x = 1;
        if(a[2] - a[0] - a[1]==1) x = b[2];
        if(a[2] - a[0] - a[1]>=2) x = 2*b[2];
        ll y = b[1] + b[2];
        ll z = -1;
        if(a[0]==0) z = 1;
        if(a[0]==1) z = (b[0] + b[2]);
        if(a[0]>=2) z = 2*(b[0] + b[2]);
        return lcm(lcm(x,y),z);
    }
    if(a[0]<=a[1] + a[2]){
        if(a[0]<=a[2]){
            ll le = -1;
            if(a[2] - a[0]==0){
                le = a[1]>=2 ? 2*b[1] : b[1]; 
            }else{
                if(a[1]==a[2] - a[0]) le = b[1] + b[2]; // #b[1]=#b[2]
                if(a[1]<a[2] - a[0]) le = lcm(b[1] + b[2],b[2]); //b[1]<b[2]
                if(a[1]>a[2] - a[0]) le = lcm(b[1] + b[2],b[1]); //b[1]>b[2];
            }
            ll ri = a[0]>=2 ? 2*(b[0] + b[2]) : b[0] + b[2];
            return lcm(le,ri);
        }else{
            ll le = -1;
            if(a[1] + a[2] - a[0]==0) le = 1;
            else le = a[1] + a[2] - a[0]>=2 ? 2*b[1] : b[1];
            b[1] += b[0]; b[2] += b[0];
            ll ri = -1;
            if(a[0] - a[2]==a[2]) ri = (b[1] + b[2]); // #b[1]=#b[2]
            if(a[0] - a[2]<a[2]) ri = lcm(b[1] + b[2],b[2]); //b[1]<b[2]
            if(a[0] - a[2]>a[2]) ri = lcm(b[1] + b[2],b[1]); //b[1]>b[2]
            return lcm(le,ri);
        }
    }else{
        //this case may be overflow!!!!!!!!!
        // multi prime is 2 or 3
        ll d = (a[0] - 1)/(a[1] + a[2]);
        if(!d) exit(1);
        a[0] -= (a[1] + a[2])*d;
        if(a[0]>a[1] + a[2]) exit(1);
        b[1] += b[0]*d; b[2] += b[0]*d;
        return solve_pattern_A(a,b);
    }
}

ll solve(vector<ll> &a){
    int i;
    ll def = -1;
    if(a[1]<=2*a[2]){
        def = 2*a[2] - a[1]>=2 ? 2 : 1;
        vector<ll> v = {a[2],a[1] - a[2],a[0] - a[1]};
        vector<ll> u = {2,3,1};
        return lcm(def,solve_pattern_A(v,u));
    }else{
        if(a[0]>a[1] + a[2]){
            def = a[2]==1 ? 3 : 6;
            vector<ll> v = {a[1] - 2*a[2],a[2],a[0] - a[1] - a[2]};
            vector<ll> u = {2,3,1};
            return lcm(def,solve_pattern_A(v,u));
        }
        if(a[1] + a[2] - a[0]==0){
            def = a[0] - a[1]>=2 ? 6 : 3;
        }else{
            int le = a[1] + a[2] - a[0],ri = a[0] - a[1];
            if(le==ri) def = 8; //#5=#3
            if(le<ri) def = 24; //5<3, lcm(8,3)
            if(le>ri) def = 40; //5>3, lcm(5,8)
        }
        return lcm(def,two_columns_solver(a[1] - 2*a[2],a[0] - a[1],2,3));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int i=0;i<t;i++){
        ll a,b,c; cin >> a >> b >> c;
        num2 = num3 = num5 = 0;
        vs.clear();
        vector<ll> v = {a,b,c};
        solve(v);
        ll ans = calc_lcm();
        cout << ans << "\n";
    }
}