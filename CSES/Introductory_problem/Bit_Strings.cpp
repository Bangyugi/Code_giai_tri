#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

ll binpow(ll a, ll b)
{
    if (b == 1)
    {
        return a;
    }
    ll x = binpow(a, b / 2) % MOD;
    if (b % 2 == 0)
    {
        return (x * x) % MOD;
    }
    else
    {
        return ((x * x) % MOD * a % MOD) % MOD;
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    ll n;
    cin >> n;
    cout << binpow(2, n);
    return 0;
}