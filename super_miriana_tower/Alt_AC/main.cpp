#include <iostream>

using namespace std;
typedef long long ll;
ll f[10010];
int main(){
    ll i,n; cin >> n;
    f[0] = 1; f[1] = 1;
    for(i=2;i<=1000;i++){
        f[i] = f[i - 1] + f[i - 2];
        if(f[i]>n) break;
    }
    ll nowx = 0,nowy = 1;
    for(i=0;i<100;i++){
        if(nowy + f[i]<=n){
            if(i&1) nowx += f[i];
            else nowx -= f[i];
            nowy += f[i];
        }else{
            if(i&1) nowx += n - nowy;
            else nowx -= n - nowy;
            nowy = n;
        }
    }
    cout << nowx << endl;
}