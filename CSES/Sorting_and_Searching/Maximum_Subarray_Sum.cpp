#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int ans = 0;
int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;
    ll a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;
    ll result = INT_MIN;
    // for (int i = 1; i <= n;i++)
    // {
    //     a[i] += a[i - 1];

    // }
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        result = max(result, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << result << endl;

    return 0;
}