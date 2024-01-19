#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int used[100005];

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vector<ll> v;
    v.push_back(a[0]);
    int ans = 0;
    ans++;
    for (int i = 1; i < n; i++)
    {
        bool ok = false;
        int l = 0;
        int r = v.size() - 1;
        int bestIndex = 0;

        while (l<=r)
        {
            int m = (l + r) / 2;
            if (v[m]> a[i])
            {
                ok = true;
                r = m - 1;
                bestIndex = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if (ok)
        {
            v[bestIndex] = a[i];
        }
        else
        {
            v.push_back(a[i]);
            ans++;
        }
    }
    cout << ans;
  
    return 0;
}