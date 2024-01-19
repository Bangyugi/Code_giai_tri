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
    ll  n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cout << i*i * (i*i - 1) / 2 - 4 * (i - 2) * (i - 1) << endl;
    }
    return 0;
}