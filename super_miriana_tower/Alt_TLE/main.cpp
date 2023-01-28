#include <iostream>

using namespace std;
typedef long long ll;
ll f(ll x){
    if(x==0 || x==1) return 1;
    return f(x - 2) + f(x - 1);
}

int main(){
    ll n; cin >> n;
    ll nowx = 0,nowy = 1,pos = 0;
    while(nowy<n){
        ll z = f(pos);
        if(pos&1){
            nowx += min(n - nowy,z);
            nowy += min(n - nowy,z);
        }else{
            nowx -= min(n - nowy,z);
            nowy += min(n - nowy,z);
        }
        pos++;
    }
    cout << nowx << endl;
}