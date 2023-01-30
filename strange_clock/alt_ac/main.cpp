#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> convolution(vector<int> a,vector<int> b){

}

vector<ll> moe_gen(int n){
    int i,j;
    vector<bool> sieve(n + 1,true);
    vector<ll> moe(n + 1);
    for(i=1;i<=n;i++) moe[i] = 1;
    for(int p=2;p<=n;p++){
        if(sieve[p]){
      	    moe[p] = -1;
            for(j=2;j*p<=n;j++){
			    sieve[j*p] = false;
          	    if(j%p==0) moe[j*p] = 0;
          	    else moe[j*p] *= -1;
            }
        }
    }
    return moe;
}

const int mx = 200000;
int a[200010],e[200010],cnt[200010],f[200010],g[200010];
int main(){
    //wirterが作業するまでコメントアウト
    // int i,j,n; cin >> n;
    // for(i=0;i<n;i++) cin >> a[i];
    // vector<int> b(mx + 1),c(mx + 1);
    // for(i=0;i<n;i++){
    //     b[a[i]] = 1; c[mx - a[i]] = 1;
    // }
    // vector<int> d = convolution(b,c);
    // for(i=mx + 1;i<=2*mx;i++){
    //     if(d[i]) e[i - mx]++;
    // }
    // for(i=1;i<=mx;i++){
    //     for(j=i;j<=mx;j+=i){
    //         if(e[j]) cnt[i]++;
    //     }
    // }
    // for(i=1;i<=mx;i++){
    //     if(cnt[i]) g[i] = 1;
    // }
    // vector<ll> m = moe_gen(mx);
    // ll ans = 0;
    // for(i=1;i<=mx;i++){
    //     ans += m[i]*g[i];
    // }
    // cout << ans << "\n";
}