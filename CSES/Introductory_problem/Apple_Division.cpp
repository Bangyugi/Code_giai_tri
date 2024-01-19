#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
int n;
ll Min_value = INT_MAX;
int a[100005];

void Try(ll sumA, ll sumB, int i)
{
    if (i == n)
    {
        Min_value = min((ll)(abs(sumA - sumB)), Min_value);
        return;
    }
    Try(sumA + a[i + 1], sumB, i + 1);
    Try(sumA, sumB + a[i + 1], i + 1);
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll sumA = 0;
    ll sumB = 0;
    Try(sumA + a[1], sumB, 1);
    Try(sumA, sumB + a[1], 1);
    cout << Min_value;
    return 0;
}