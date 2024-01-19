#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    ll a[n];

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll x1 = a[n / 2], x2 = a[n / 2 + 1];
    ll res1 = 0, res2 = 0;
    for (int i = 0; i < n;i++)
    {
        res1 += abs(x1 - a[i]);
        res2 += abs(x2 - a[i]);
    }
    cout << min(res1, res2);

    return 0;
}