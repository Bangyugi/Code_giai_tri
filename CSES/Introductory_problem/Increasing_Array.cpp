#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;
 
int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    ll ans = 0;
    ll addedNumber = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        addedNumber = max(0*1ll, a[i - 1] - a[i]);
        ans += addedNumber;
        a[i] += addedNumber;
    }
    cout << ans;
    return 0;
}