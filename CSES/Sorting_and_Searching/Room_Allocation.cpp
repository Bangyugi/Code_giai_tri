#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

bool cmp(ii a, ii b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ii> schedule;
    vector < pair<pair<int,int>, int>> timeLine;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        timeLine.push_back({{x, y}, i});
    }
    sort(timeLine.begin(), timeLine.end());
    // for (auto x : timeLine)
    // {
    //     cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    // }
    vector<ii> roomID;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    for (auto x : timeLine)
    {
        if (Q.empty())
        {
            Q.push({x.first.second, 1});
            roomID.push_back({x.second, 1});
            continue;
        }
        ii top = Q.top();
        if (x.first.first > top.first)
        {
            Q.pop();
            Q.push({x.first.second, top.second});
            roomID.push_back({x.second, top.second});
        }
        else
        {
            int ID = Q.size() + 1;
            Q.push({x.first.second, ID});
            roomID.push_back({x.second, ID});
        }
    }
    int Max_value = INT_MIN;
    for (auto x : roomID)
    {
        Max_value = max(Max_value, x.second);
    }
    cout << Max_value << endl;
    sort(roomID.begin(), roomID.end());
    for (auto x : roomID)
    {
        cout << x.second << " ";
    }
    return 0;
}