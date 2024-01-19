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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int standardScore = a[k - 1];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] >= standardScore)
            count++;
    }
    cout << count;
    return 0;
}