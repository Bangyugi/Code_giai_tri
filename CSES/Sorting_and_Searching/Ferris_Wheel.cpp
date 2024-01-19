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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (a[i] + a[j] <= x)
        {
            ans++;
            j--;
            i++;
        }
        else
        {
            ans++;
            j--;
        }
    }
    cout << ans;
    return 0;
}
    