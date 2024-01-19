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
    int n;
    cin >> n;
    set<int> se;
    for (int i = 0; i <= n; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    cout << se.size();
    return 0;
}