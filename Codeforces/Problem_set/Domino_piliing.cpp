#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (m%2==0)
    {
        cout << n * (m / 2);
    }
    else
    {
        cout << n * (m / 2) + (n / 2);
    }
    return 0;
}