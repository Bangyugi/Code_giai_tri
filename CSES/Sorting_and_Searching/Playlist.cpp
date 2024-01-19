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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    ll j = 0;
    map<ll, ll> mp;

    for (ll i = 0; i < n; i++)
    {

        mp[a[i]]++;
        while (mp[a[i]]>=2)
        {
            mp[a[j]]--;
            j++;
        }
        ans = max(ans, i - j+1);
    }
   

    cout << ans;
    return 0;
}