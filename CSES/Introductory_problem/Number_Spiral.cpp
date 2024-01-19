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
    int t;
    cin >> t;
    while (t--)
    {
        ll res = 0;
        ll x, y;
        cin >> x >> y;
        ll z = max(x, y);
        ll temp = z * z - z + 1;
        if (z % 2 == 0)
        {
            res = temp + (x - y);
        }
        else
        {
            res = temp - (x - y);
        }
        cout << res << endl;
        
    }
    return 0;
}