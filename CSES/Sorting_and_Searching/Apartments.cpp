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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;

    int i = 0;
    int j = 0;
    while (i<n && j<m)
    {
        if (abs(a[i]-b[j])<=k)
        {
            ans++;
            j++;
            i++;
        }
        else if (a[i]<b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << ans;
    return 0;
}