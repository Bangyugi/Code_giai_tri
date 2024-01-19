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
    ll n;
    cin >> n;
    ii a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    ll ans = 1;
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i].second < a[i - 1].second)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}