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
    ll ans = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans << endl;
    return 0;
}