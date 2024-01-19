#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

bool cmp(ii a, ii b)
{
    return a.second < b.second;
}

int main()

{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    vector<ii> timeLines;
    multimap <int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        timeLines.push_back({s, e});
        mp.insert({s, 1});
        mp.insert({e, -1});
    }
    int sum = 0;
    for (auto x : mp)
    {
        ans = max(ans, sum+=x.second);
    }
    cout << ans;

    return 0;
}