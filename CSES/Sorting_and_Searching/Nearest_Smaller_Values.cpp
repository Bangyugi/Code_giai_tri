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
    vector<ii> v;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    vector<int> result(n + 1);
    set<int> se;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        // if (se.empty())
        // {
        //     result[v[i].second] = 0;
        //     if (v[i].first != v[i + 1].first)
        //         se.insert(v[i].second);

        // }
        auto it = se.lower_bound(v[i].second);
        if (it == se.begin())
        {
            result[v[i].second] = 0;
        }
        else
        {
            it--;
            result[v[i].second] = *it;
        }
        if (v[i].first == v[i + 1].first)
            temp.push_back(v[i].second);
        else
        {
            for (auto x:temp)
                se.insert(x);
            temp.clear();
            se.insert(v[i].second);
        }
    }

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}