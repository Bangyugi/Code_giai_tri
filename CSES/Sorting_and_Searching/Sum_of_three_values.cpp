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
    int n, s;
    cin >> n >> s;
    vector<ii> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    bool check = false;
    for (int i = 1; i < n - 1; i++)
    {
        int temp = v[i].first;
        int m = i;
        int r = n - 1;
        int l = 0;
        while (l < m && r > m)
        {
            if (v[l].first + v[r].first > s - temp)
            {
                r--;
            }
            else if (v[l].first + v[r].first < s - temp)
            {
                l++;
            }
            else
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            cout << v[l].second + 1 << " " << v[m].second + 1 << " " << v[r].second + 1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}