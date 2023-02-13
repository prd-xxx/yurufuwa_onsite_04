#include <iostream>
using namespace std;
using ll = long long;
ll solve(ll a, ll b)
{
    if (2 * a <= b)
    {
        return a == 1 && b <= 3 ? 3 : 6;
    }
    ll d = b - a;
    ll n = a / d;
    if (d == 1)
    {
        return 2 * n + 1;
    }
    else if (d == 2)
    {
        return a % 2 == 1 ? (2 * n + 1) * (2 * n + 3) : 2 * (2 * n + 1);
    }
    else
    {
        return a % d > 0 ? 2 * (2 * n + 1) * (2 * n + 3) : 2 * (2 * n + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll b, a;
        cin >> b >> a;
        cout << solve(a, b) % 998244353 << endl;
    }
}