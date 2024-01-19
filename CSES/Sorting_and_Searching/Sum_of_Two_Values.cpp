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
    int n, x;
    cin >> n >> x;
    int a[n+1];
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (mp.count(x-a[i]))
        {
            cout << mp[x - a[i]] << ' ' << i;
            return 0;
        }
        else
        {
            mp[ a[i]] = i;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}