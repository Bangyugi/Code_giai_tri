#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

ll maximumProduct(ll m, ll n, vector<ll> time)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += min(m / time[i],(ll)1e9) ;
    }
    return sum ;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    ll n, t;
    cin >> n >> t;
    vector<ll> time(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    sort(time.begin(), time.end());
    ll l = 1;
    ll r = 1e18;
    ll bestValue = 0;
    t = t ;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (maximumProduct(m, n, time) < t)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
            bestValue = m;
        }
    }
    cout << bestValue << endl;
    // cout << maximumProduct(bestValue, n, time) << endl;
    // cout << maximumProduct(768614336414205720, n, time) << endl;
    // cout << maximumProduct(41666667, n, time) << endl;
    // cout << maximumProduct(41666667000, n, time) << endl;
    // cout << maximumProduct(768614336414200000, n, time) << endl;

    return 0;
}